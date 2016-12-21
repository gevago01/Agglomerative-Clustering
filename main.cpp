#include <iostream>
#include "DataReader.h"
#include "Cluster.h"
#include "Agglomerate.h"
using std::cout;
using std::endl;
int main() {
    DataReader dr("../0.txt");

    std::map<long,Cluster>  clusters=dr.returnClusters();

    Agglomerate agglomerate(clusters);

    agglomerate.calculateInitialDistances();
    agglomerate.agglomerate();

    cout<<"done"<<endl;
    return 0;
}
