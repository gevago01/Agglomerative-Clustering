//
// Created by gevagorou on 19/04/16.
//

#ifndef THESIS_CLUSTER_H
#define THESIS_CLUSTER_H

#include <vector>
#include "Point.h"
#include <cmath>
#include <ostream>

class Cluster {

    friend std::ostream &operator<<(std::ostream &ostr, const Cluster &cl);

private:


    static long id_generator;
    long cluster_id;
    int num_of_points;
    std::vector<double> sum_vector;
    std::vector<Point> cluster_points;
    std::vector<double> centroid;

public:
    Cluster() = default;

    Cluster(const Cluster &cl);

    Cluster &merge(const Cluster &right);

    Cluster(Point p);

    void insertPoint(Point p);

    long getCluster_id() const;

    Cluster &operator=(const Cluster &right);

    static double euclidean_distance(const Cluster &a, const Cluster &b);

};


#endif //THESIS_CLUSTER_H