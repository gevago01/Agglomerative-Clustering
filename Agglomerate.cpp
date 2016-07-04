//
// Created by giannis on 21/04/16.
//

#include "Agglomerate.h"

using std::set;

Agglomerate::Agglomerate(const std::map<long, Cluster> clusters) {
    //we only insert in all_clusters - we don't remove
    all_clusters = clusters;
}

/**
 * This function takes single point cluters and find the
 * nearest cluster to each cluster
 */
void Agglomerate::calculateInitialDistances() {
    set<long> from;
    set<long> to;
    for (const auto &pair_one:all_clusters) {
        for (const auto &pair_two:all_clusters) {

            bool from_to = ((from.find(pair_one.first) == from.end()) && (to.find(pair_two.first) == to.end()));
            bool to_from = ((to.find(pair_one.first) == to.end()) && (from.find(pair_two.first) == from.end()));
            //check that cluster ids are different and that
            // the distance for this pair has not been calculated
            if ((pair_one.first != pair_two.first) && from_to && to_from) {
                //calculate distance between two clusters
                double distance = Cluster::euclidean_distance(pair_one.second, pair_two.second);

                InterClusterDistance inter_cluster_dis(pair_one.first, pair_two.first, distance);

                prior_queue.push(inter_cluster_dis);

                from.insert(pair_one.first);
                to.insert(pair_two.first);
            }
        }
    }

}

Cluster Agglomerate::mergeClusters(long from, long to) {

    auto to_cluster = all_clusters.find(to);
    auto from_cluster = all_clusters.find(from);

    //merge the two clusters
    Cluster new_cluster = from_cluster->second.merge(to_cluster->second);

    return new_cluster;
}

void Agglomerate::agglomerate() {
    long from, to;
    set<long> merged;

    //we should end up with only one cluster
    while (prior_queue.size()!=0) {
        //take the two nearest clusters
        InterClusterDistance icd = prior_queue.top();
        from = icd.getFrom();
        to = icd.getTo();

        //check if already merged and continue
        if ((merged.find(from) != merged.end()) || (merged.find(to) != merged.end())) {
            //remove the nearest two clusters
            prior_queue.pop();
            continue;
        }
        //merge two clusters

        Cluster new_cluster = mergeClusters(from, to);
        //erase the two clusters
        all_clusters.erase(from);
        all_clusters.erase(to);
        merged.insert(from);
        merged.insert(to);

        //recalculate distances
        recalculateDistances(new_cluster);

        //insert the new cluster to all_clusters
        all_clusters.insert({new_cluster.getCluster_id(), new_cluster});

        //remove the nearest two clusters
        prior_queue.pop();
    }


}

void Agglomerate::recalculateDistances(Cluster new_cluster) {
    auto begin = all_clusters.begin();
    auto end = all_clusters.end();
    while (begin != end) {
        //calculate distance between two clusters
        double distance = Cluster::euclidean_distance(new_cluster, begin->second);

        InterClusterDistance inter_cluster_dis(new_cluster.getCluster_id(), begin->first, distance);

        prior_queue.push(inter_cluster_dis);
        ++begin;
    }

}
