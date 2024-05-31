#ifndef GRAPHS_HPP
#define GRAPHS_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
class Graphs {

    public:
    // Constructor
    Graphs(std::vector<int> vCounts);

    // Methods
    void makeMatrices(int gCount, std::vector<int> minVertexes, std::vector<int> vCounts, std::vector<std::vector<std::pair<int, int>>> edgePairsArray);
    void makeAdjacency(int gCount, std::vector<int> minVertexes, std::vector<int> vCounts, std::vector<std::vector<std::pair<int, int>>> edgePairsArray);
    void printMatrix();
    void printAdjacency(int gCount, std::vector<int> minVertexes, std::vector<int> vCounts);

    private:
    // Array of matrices
    std::vector<std::vector<std::vector<int>>> myMatrices;
    std::vector<std::vector<std::vector<int>>> aList;
};


#endif