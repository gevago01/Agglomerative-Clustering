//
// Created by giannis on 15/04/16.
//


#include "Point.h"

using std::istringstream;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::ostream;

/**
 * Converts string to double
 */
double Point::stringToDouble(const string str) {
    istringstream double_str(str);
    double x;
    if (!(double_str >> x)) {
        cerr << "Error converting string to double" << endl;
        exit(-1);
    }

    return x;
}

/**
 * gets records of this form:
 * 2.58119273751133 -3.0897997256242977 1
 */
Point::Point(vector<string> records) : num_of_dimensions(0) {
    double one_dimension;
    for (string record:records) {
        one_dimension = stringToDouble(record);
        coordinates.push_back(one_dimension);
        ++num_of_dimensions;
    }
    --num_of_dimensions;
    //get cluster id
    cluster_id = int(coordinates.back());
    //remove cluster id
    coordinates.pop_back();
}


/**
 * Define the copy constructor. This is equivalent with the default/compiler synthesized
 */
Point::Point(const Point &originalPoint) :
        cluster_id(originalPoint.cluster_id), coordinates(originalPoint.coordinates),
        num_of_dimensions(originalPoint.num_of_dimensions) {

}

/**
 * Copy assignment operator - this is equivalent to the default/compiler synthesized
 */
Point &Point::operator=(const Point &right) {
    cluster_id = right.cluster_id;
    coordinates = right.coordinates;
    num_of_dimensions = right.num_of_dimensions;
    //return reference
    return *this;
}

ostream &operator<<(ostream &ostream1, const Point &point) {
    //increase stream precision to print all decimal places
    ostream1.precision(17);

    for (double dim:point.coordinates) {
        ostream1 << dim << ",";
    }
    //ostream1<<endl;
    //ostream1<<"# of dimensions:"<<point.num_of_dimensions<<endl;
    //ostream1<<"Cluster id:"<<point.cluster_id<<endl;
    return ostream1;
}

