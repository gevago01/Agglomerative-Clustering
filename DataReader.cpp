//
// Created by gevagorou on 14/04/16.
//


#include "DataReader.h"


using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::flush;
using std::vector;

std::map<long,Cluster> DataReader::returnClusters() {

    std::map<long,Cluster> clusters;

    if (!in_file_stream) {
        cout << "failed to read input"<<endl;
        exit(-1);
    }
    string line, word;
    vector<string> tokens;
    while (getline(in_file_stream, line)) {

        //ignore comment lines
        if (line[0] == '#') {
            continue;
        }
        //istringstream makes the line string an input string stream
        istringstream record(line);

        /*a record contains a number of coordinates and a cluster id:
        2.58119273751133 -3.0897997256242977 1*/
        while (record >> word) {
            tokens.push_back(word);
        }

        Point new_point(tokens);
        /*we perform agglomerative clustering -
        each point is a cluster at the beginning*/
        Cluster new_cluster(new_point);
        clusters[new_cluster.getCluster_id()]=new_cluster;

        tokens.clear();

    }


    return clusters;

}