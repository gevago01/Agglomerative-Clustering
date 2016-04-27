# Agglomerative-Clustering
A bottom up clustering approach in which each object starts in
its own cluster, and pairs of clusters are merged as one moves up the
hierarchy. This implementation is based
 on the paper "An efficient agglomerative clustering algorithm using a heap" and works as
follows:

1. Begin with N objects where each object is a cluster on tis own.
   The clusters are uniquely identified by a cluster id (e.g. **1**
   to **N**)
2. Calculate pairwise distances between the clusters and insert
    them into a heap
3. Retreive from the heap the nearest pair of clusters, which is
    the first element in the heap (complexity **O(1)**).
4. Merge the two nearest clusters (e.g. **a** and **b**) into a new
    cluster (e.g. **K**) and insert the cluster **K** to the set of all clusters.
    Remove **a** and **b** from the set of all clusters. This step
    reduces the number of all clusters by one. Calculate the
    pairwise distances between cluster **K** and all the remaining
    clusters.
5. Execute steps **3** and **4**, **N-1** times until you end up with a big single
    cluster.

## Time Complexity
The complexity for calculating the pairwise  distances between the new
cluster **K** and all remaining clusters (**N<sub>r</sub>**) is
**O(N<sub>r</sub>)**. Each pairwise distance is inserted into the heap,
which has a complexity of **O(log(n))**. Since step **3** and **4** are
 executed **N-1** times, the overall time complexity is
 **(N-1) \* N<sub>r</sub> \* log(n)** or more simply
  **N<sup>2</sup>  \* log(n)**.

## Project Requirements
   1. C++11
   2. CMake 3.5
   3. STL Containers (no libraries)




