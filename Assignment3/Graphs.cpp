#include "Graphs.hpp"

Graphs::Graphs(std::vector<int> vCounts) {
    // Resize the matrix to their respective vCount x vCount and initialize all elements to 0
    myMatrices.resize(vCounts.size());
    for(std::vector<std::vector<int>>::size_type i = 0; i < vCounts.size(); i++) {
        myMatrices[i] = std::vector<std::vector<int>>(vCounts[i], std::vector<int>(vCounts[i], 0));
    }
    // Resize our adjacency list to its respective vConut size
    aList.resize(vCounts.size());
}

void Graphs::makeMatrices(int gCount, std::vector<int> minVertexes, std::vector<int> vCounts, std::vector<std::vector<std::pair<int,int>>> edgePairsArray) {
    // Initialize matrices with appropriate sizes
    for(int i = 0; i < gCount; i++) {
        // Fill in the matrix with edge values
        for(const auto& edge : edgePairsArray[i]) {
            if(minVertexes[i] >= 0) {
                int v1 = edge.first - minVertexes[i];
                int v2 = edge.second - minVertexes[i];
                myMatrices[i][v1][v2] = 1;
                myMatrices[i][v2][v1] = 1;
            } else {
                int v1 = edge.first + minVertexes[i];
                int v2 = edge.second + minVertexes[i];
                myMatrices[i][v1][v2] = 1;
                myMatrices[i][v2][v1] = 1;
            }
            
        }
    }
}

void Graphs::printMatrix() {
    // go through matrices
    for(std::vector<std::vector<std::vector<int>>>::size_type i = 0; i < myMatrices.size(); i++) {
        std::cout << "Matrix " << i + 1 << ":" << std::endl;
        //print the matrices
        for(std::vector<std::vector<int>>::size_type row = 0; row < myMatrices[i].size(); row++) {
            for(std::vector<int>::size_type col = 0; col <myMatrices[i][row].size(); col++) {
                std::cout << myMatrices[i][row][col] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Graphs::makeAdjacency(int gCount, std::vector<int> minVertexes, std::vector<int> vCounts, std::vector<std::vector<std::pair<int,int>>> edgePairsArray) {
    
    // for each graph
    for(int i = 0; i < gCount; i++) {
        // Resize the adjacency list for the current graph if needed
        // for each Vertex we will pushback its adjacent vertexes
        for(int j  = 0; j < vCounts[i]; j++) {
            aList[i].push_back(std::vector<int>());
        }
        for(const auto& edge : edgePairsArray[i]) {
            int v1 = edge.first;
            int v2 = edge.second;
            aList[i][v1].push_back(v2);
            aList[i][v2].push_back(v1);
        } //pushing back starting at 0 need to adjust according to min vertex instead push all 8 vertice
    }
}
