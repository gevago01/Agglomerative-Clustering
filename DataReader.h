//
// Created by gevagorou on 14/04/16.
//

#ifndef THESIS_DATAREADER_H
#define THESIS_DATAREADER_H
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Cluster.h"
#include <map>

class DataReader {
private:
    std::string file_name;
    std::ifstream in_file_stream;
public:
    DataReader(std::string filename): file_name(filename), in_file_stream(filename) {};
    std::map<long,Cluster>  returnClusters();
};

#endif //THESIS_DATAREADER_H
