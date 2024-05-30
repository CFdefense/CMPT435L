#ifndef GRAPHS_HPP
#define GRAPHS_HPP

#include <vector>
#include <iostream>
class Graphs {

    public:
    // Constructor
    Graphs(std::vector<int> vCounts);

    // Methods
    void makeMatrices(int gCount, std::vector<int> vCounts, std::vector<std::vector<std::pair<int, int>>> edgePairsArray );
    void printMatrix();
    void printInfo(std::vector<int> vCounts, std::vector<int> eCounts, int gCount, std::vector<std::vector<std::pair<int,int>>> edgePairsArray);

    private:
    // Array of matrices
    std::vector<std::vector<std::vector<int>>> myMatrices;
};


#endif