//
// Created by giannis on 21/04/16.
//

#ifndef THESIS_AGGLOMERATE_H
#define THESIS_AGGLOMERATE_H

#include "Cluster.h"
#include <map>
#include "InterClusterDistance.h"
#include <queue>
#include <values.h>
#include <set>
#include <iterator>
#include <fstream>
#include <stdexcept>

class Agglomerate {

private:

    //define the comparator for our priority queue
    struct comparator {
        bool operator()(const InterClusterDistance &left, const InterClusterDistance &right) {
            return left.getDistance() > right.getDistance();
        }
    };

    //declare alias for this priority queue
    using my_priority_queue=std::priority_queue<double, std::vector<InterClusterDistance>, comparator>;

    my_priority_queue prior_queue;

    std::map<long, Cluster> all_clusters;
    /*associates cluster ids to priority queues, first element
     * in queue is the nearest to the cluster specified by the key*/
//    std::map<long, std::priority_queue<double, std::vector<InterClusterDistance>, comparator>> distance_matrix;
    std::map<long, std::priority_queue<double, my_priority_queue, comparator>> distance_matrix;

public:
    Agglomerate() = default;

    Agglomerate(std::map<long, Cluster> clusters);

    void calculateInitialDistances();

    Cluster mergeClusters(long from, long to);

    void agglomerate();

    void recalculateDistances(Cluster new_cluster);
};

#endif //THESIS_AGGLOMERATE_H
