//
// Created by gevagorou on 19/04/16.
//

#include "Cluster.h"

using std::cout;
using std::endl;
using std::vector;
using std::cout;
long Cluster::id_generator = 0;

void Cluster::insertPoint(Point p) {
    cluster_points.push_back(p);
    num_of_points++;
    //adjust stats
    for (unsigned long i = 0; i < p.coordinates.size(); ++i) {
        //called from the constructor
        if (i >= sum_vector.size()) {
            //if nothing exists at that index
            sum_vector.push_back(p.coordinates.at(i));
            sq_sum_vector.push_back(std::pow(p.coordinates.at(i), 2));
            //calculate variance for this dimension
            variance.push_back((sq_sum_vector.at(i) / num_of_points) - std::pow((sum_vector.at(i) / num_of_points), 2));
            //calculate std for this dimension
            st_deviation.push_back(std::sqrt(variance.at(i)));
            centroid.push_back(sum_vector.at(i) / num_of_points);
        }
        else {
            sum_vector.at(i) += p.coordinates.at(i);
            sq_sum_vector.at(i) += std::pow(p.coordinates.at(i), 2);
            //calculate variance for this dimension
            variance.at(i)=((sq_sum_vector.at(i) / num_of_points) - std::pow((sum_vector.at(i) / num_of_points), 2));
            //calculate std for this dimension
            st_deviation.at(i)=(std::sqrt(variance.at(i)));
            centroid.at(i)=(sum_vector.at(i) / num_of_points);
        }

    }

}


Cluster::Cluster(Point p) : num_of_points(0), cluster_id(id_generator) {
    /*tell the container how many elements it
        should be prepared to hold.*/
    sum_vector.reserve(p.coordinates.size());
    sq_sum_vector.reserve(p.coordinates.size());
    variance.reserve(p.coordinates.size());
    st_deviation.reserve(p.coordinates.size());
    centroid.reserve(p.coordinates.size());
    //insert point to this cluster
    insertPoint(p);
    id_generator++;
}


long Cluster::getCluster_id() const {
    return cluster_id;
}

Cluster &Cluster::operator=(const Cluster &right) {

    num_of_points = right.num_of_points;
    cluster_id = right.cluster_id;
    sum_vector = right.sum_vector;
    sq_sum_vector = right.sq_sum_vector;
    cluster_points = right.cluster_points;
    centroid = right.centroid;
    st_deviation = right.st_deviation;
    variance = right.variance;
    return *this;
}

Cluster::Cluster(const Cluster &cl) :
        num_of_points(cl.num_of_points), cluster_id(cl.cluster_id), sum_vector(cl.sum_vector),
        sq_sum_vector(cl.sq_sum_vector),
        cluster_points(cl.cluster_points), centroid(cl.centroid), variance(cl.variance), st_deviation(cl.st_deviation) {
}


/**
 * Estimates euclidean distance between two clusters
 */
double Cluster::euclidean_distance(const Cluster &a, const Cluster &b) {
    double sum = 0;

    for (unsigned long i = 0; i < b.centroid.size(); ++i) {
        sum += std::pow((a.centroid.at(i) - b.centroid.at(i)), 2);
    }

    return std::sqrt(sum);
}

/**
 * Merges two clusters
 */
Cluster& Cluster::merge(const Cluster &right) {

    vector<Point>::const_iterator points_begin = right.cluster_points.cbegin();
    vector<Point>::const_iterator points_end = right.cluster_points.cend();
    //iterate over all points in the right cluster
    while (points_begin != points_end) {
        //insert all points from right cluster to left cluster
        insertPoint(*points_begin);
        ++points_begin;
    }

    //the left cluster is essentially a new cluster - so change its cluster id
    this->cluster_id=id_generator;
    ++id_generator;
    return *this;
}

/**
 * Friend method that prints the Cluster object
 */
std::ostream &operator<<(std::ostream &out_stream, const Cluster &cl) {
    out_stream.precision(17);
    out_stream << "--------------------Cluster" << " " << cl.cluster_id << "--------------------" << std::endl;
    out_stream << "Number of points:" << cl.cluster_points.size() << std::endl;
    out_stream << "Points:" << std::endl;
    for (Point p:cl.cluster_points) {
        std::cout << p;
    }
    std::cout << "sum vector:" ;
    for (double sum:cl.sum_vector) {
        out_stream << sum;
        out_stream << " ";
    }
    out_stream << std::endl<<"square sum vector:" ;
    for (double sqsum:cl.sq_sum_vector) {
        out_stream << sqsum;
        out_stream << " ";
    }
    out_stream << std::endl<<"Variance" ;
    for (double sqsum:cl.variance) {
        out_stream << sqsum;
        out_stream << " ";
    }

    out_stream << std::endl<<"Standard deviation" ;
    for (double sqsum:cl.st_deviation) {
        out_stream << sqsum;
        out_stream << " ";
    }
    out_stream << std::endl<<"Centroid:";

    for (double d:cl.centroid) {
        out_stream << d << ",";
    }

    out_stream << std::endl;

    out_stream << "------------------------------------------------" << std::endl;

    return out_stream;

}