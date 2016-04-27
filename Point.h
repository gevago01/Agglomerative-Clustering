//
// Created by giannis on 15/04/16.
//

#ifndef THESIS_POINT_H
#define THESIS_POINT_H
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

class Point {

    //friend function that prints the object
    friend std::ostream& operator<<(std::ostream&, const Point&);

    // friend class declaration is its own a forward declaration
    friend class Cluster;

private:
    /*holds coordinates for a number of dimensions
     its size is the number of dimensions*/
    std::vector<double> coordinates;

    /*denotes the cluster id (from the input
     * file) that the point belongs to*/
    int cluster_id;
    /* num of dimensions for this point*/
    int num_of_dimensions;

public:
    Point (std::vector<std::string> records );

    Point () : cluster_id(0),num_of_dimensions(0){ };

    //copy constructor takes a reference to a const object of this class
    Point (const Point &originalPoint);

    //default destructor
    ~Point()= default;

    //copy assignment operator
    Point &operator=(const Point &right);

    static double stringToDouble(std::string const str);

};

#endif //THESIS_POINT_H
