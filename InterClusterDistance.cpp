//
// Created by giannis on 21/04/16.
//

#include "InterClusterDistance.h"

using std::cout;
using std::endl;

InterClusterDistance::InterClusterDistance(const InterClusterDistance &other_cluster) :distance(other_cluster.distance),cluster_1(other_cluster.cluster_1),cluster_2(other_cluster.cluster_2){
}

InterClusterDistance& InterClusterDistance::operator=(const InterClusterDistance &right_cluster) {
    distance=right_cluster.distance;
    cluster_1=right_cluster.cluster_1;
    cluster_2=right_cluster.cluster_2;
}

double InterClusterDistance::getDistance() const {
    return distance;
}

std::ostream& operator<<(std::ostream & out_stream, const InterClusterDistance &icd) {
    cout<<"Distance:"<<icd.distance;
    cout<<" From Cluster:"<<icd.cluster_1;
    cout<<" To Cluster:"<<icd.cluster_2<<endl;
}

long InterClusterDistance::getFrom() {
    return cluster_1;
}

long InterClusterDistance::getTo() {
    return cluster_2;
}