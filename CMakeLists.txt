cmake_minimum_required(VERSION 3.5)
project(Agglomerative)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DataReader.cpp DataReader.h Point.cpp Point.h Cluster.cpp Cluster.h Agglomerate.cpp Agglomerate.h InterClusterDistance.cpp InterClusterDistance.h)
add_executable(Agglomerative ${SOURCE_FILES})