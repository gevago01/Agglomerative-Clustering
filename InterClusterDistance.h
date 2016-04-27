//
// Created by giannis on 21/04/16.
//

#ifndef THESIS_INTERCLUSTERDISTANCE_H
#define THESIS_INTERCLUSTERDISTANCE_H


#include <cmath>
#include <ostream>
#include <iostream>

class InterClusterDistance {

private:
    long cluster_1;
    long cluster_2;
    double distance;

public:
    InterClusterDistance() : cluster_1(0), distance(0),cluster_2(0) { };

    InterClusterDistance(long cluster1, long cluster2, double dis) : cluster_1(cluster1), distance(dis),cluster_2(cluster2) { };

    //copy constructor
    InterClusterDistance(const InterClusterDistance &other_cluster);

    //default destructor
    ~InterClusterDistance() = default;

    //direct initialization
    InterClusterDistance &operator=(const InterClusterDistance &right_cluster);

    //get distance - const : the object's state
    // on which it is called cannot be changed
    double getDistance() const ;

    friend  std::ostream& operator<<(std::ostream &, const InterClusterDistance &);

    long getFrom();

    long getTo();

};


#endif //THESIS_INTERCLUSTERDISTANCE_H
