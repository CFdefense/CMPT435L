#include "Graphs.hpp"

Graphs::Graphs(std::vector<int> vCounts) {
    // Resize the adjacency matrices to their respective vCount x vCount and initialize all elements to 0
    myMatrices.resize(vCounts.size());
    for(std::vector<std::vector<int>>::size_type i = 0; i < vCounts.size(); i++) {
        myMatrices[i].resize(vCounts[i], std::vector<int>(vCounts[i], 0));
    }
}

void Graphs::makeMatrices(int gCount, std::vector<int> vCounts, std::vector<std::vector<std::pair<int,int>>> edgePairsArray) {
    // instance variable
    int first;
    int second;
    
    // go through each pair stored in edge pairs and toggle its corresponding pair in its matrix
    for(int i = 0; i < gCount; i++) {
        for(std::vector<std::pair<int,int>>::size_type j = 0; j < edgePairsArray[i].size(); j++) {
            first = edgePairsArray[i][j].first;
            second = edgePairsArray[i][j].second;
            myMatrices[i][first][second] = 1; //some matrix is not scaled properly
        }
    }
}

void Graphs::printMatrix() {
    // go through matrices
    for(std::vector<std::vector<std::vector<int>>>::size_type i = 0; i < myMatrices.size(); i++) {
        std::cout << "Matrix " << i + 1 << ":" << std::endl;
        for(std::vector<std::vector<int>>::size_type row = 0; row < myMatrices[i].size(); row++) {
            for(std::vector<int>::size_type col = 0; col <myMatrices[i][row].size(); col++) {
                std::cout << myMatrices[i][row][col] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

// General printing function for testing and visualization purposes
void printInfo(std::vector<int> vCounts, std::vector<int> eCounts, int gCount, std::vector<std::vector<std::pair<int,int>>> edgePairsArray) {
        std::cout << "Total number of graphs: " << gCount << std::endl;
        for(int i = 0; i < gCount; i++) {
            std::cout << "Graph #" << i + 1 << std::endl;
            std::cout << "Vertices " << vCounts[i] << std::endl;
            std::cout << "Edges " << eCounts[i] << std::endl;
            for(int j = 0; j < eCounts[i]; j++) {
                std::cout << "(" << edgePairsArray[i][j].first << "," << edgePairsArray[i][j].second << ")" << std::endl;
            }
        }
    }