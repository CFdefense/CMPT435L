#include "Graphs.hpp"
#include "Traversals.hpp"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {

    //! File Reading and Manipulation

    // Counting Vertices and Edges using dynamic arrays
    vector<int> vCounts; 
    vector<int> eCounts;
    vector<int> minVertexes;
    vector<vector<Node>> nodeList;

    // Counting variables for each graph
    int vCount = 0;
    int eCount = 0;

    //Needed to indentify when indexing will need to begin before 1
    int minVertex = std::numeric_limits<int>::max();
    int maxVertex;

    // Count number of graphs
    int gCount = 0;

    //Dynamic 2d Array to Hold Edge Pairs of each graph
    vector<vector<pair<int, int>>> edgePairsArray; // 2D array to hold edge pairs for each graph
    vector<pair<int, int>> edgePairs; // for storing each array through each graph iteration

    //Other Variables
    string fileLine;
    int vertex1 = 0;
    int vertex2 = 0;
    bool foundFirst = false;
    bool foundSecond = false;
    bool newGraph = true;

    // Open File to be Read
    ifstream myFile ("graphs1.txt");
    
    if(!myFile) {
        cout << "File Could Not Be Read" << endl;
    } else {
        // Skip whole previous method and just say while there is a line to look at
        while (getline(myFile, fileLine)) {
            if (fileLine.find("new") != string::npos) { // check if line says new indicating a new graph
                if (!newGraph) {
                    // if we have found a new graph we will push back temp values and reset them for next graph
                    vCounts.push_back(vCount);
                    eCounts.push_back(eCount);
                    edgePairsArray.push_back(edgePairs);
                    minVertexes.push_back(minVertex);

                    //reset for next graph
                    minVertex = std::numeric_limits<int>::max();
                    vCount = 0;
                    eCount = 0;
                    edgePairs.clear();
                }
                newGraph = false; // Now we move on to new graph
                gCount++;
            } else {
                if (fileLine.find("add vertex") != string::npos) { 
                    // increment vertex
                    vCount++;
                    // Find value of vertex
                    int vertexValue = 0;
                    bool foundDigit = false; // Flag to indicate if a first digit has been found
                    for (std::string::size_type i = 0; i < fileLine.length(); i++) {
                        // look for our first digit
                        if (isdigit(fileLine[i])) {
                            foundDigit = true;
                            vertexValue = vertexValue * 10 + (fileLine[i] - '0');
                        } else if (foundDigit) {
                            // If a digit has been found and the current character is not a digit then were done
                            break;
                        }
                    }
                // Update minVertex if the current vertexValue is smaller
                minVertex = std::min(minVertex, vertexValue);
                } else if (fileLine.find("add edge") != string::npos) {
                    // find edge values
                    vertex1 = 0;
                    vertex2 = 0;
                    foundFirst = false;
                    foundSecond = false;
                    
                    // find first of pair
                    for (std::string::size_type i = 0; i < fileLine.length(); i++) {
                        if ((int(fileLine[i]) >= 48) && (int(fileLine[i]) <= 57)) {
                            // Necessary for shifting digits left if multiple
                            vertex1 = vertex1 * 10 + (fileLine[i] - '0');
                            foundFirst = true;
                        } else if (foundFirst) {
                            break;
                        }
                    }
                    // Extract our second of pair
                    for (std::string::size_type j = 0; j < fileLine.length(); j++) {
                        //start after '-' to ensure we are finding second of the pair
                        if (fileLine[j] == '-') {
                            for (std::string::size_type m = j + 1; m < fileLine.length(); m++) {
                                if ((int(fileLine[m]) >= 48) && (int(fileLine[m]) <= 57)) {
                                    // Necessary for shifting digits left if multiple
                                    vertex2 = vertex2 * 10 + (fileLine[m] - '0');
                                    foundSecond = true;
                                } else if (foundSecond) {
                                    break;                                        
                                }
                            }
                            break;
                        }
                    }
                    // Add the edge to edgePairs
                    if (foundFirst && foundSecond) {
                        edgePairs.push_back(make_pair(vertex1, vertex2));
                        eCount++;
                    }
                }
            }
        }
        // Storing counts and edge pairs for the last graph
        if (!newGraph || !edgePairs.empty()) {
            vCounts.push_back(vCount);
            eCounts.push_back(eCount);
            edgePairsArray.push_back(edgePairs);
            minVertexes.push_back(minVertex);
        }
    }

    //close file
    myFile.close();

    //! End of File Reading and Manipulation

    //! Start of Graph Creation and Visualization
    
    // Create Instance of Graphs
    Graphs graphs(vCounts);
    
    //Matrices
    graphs.makeMatrices(gCount, minVertexes, vCounts, edgePairsArray);
    graphs.printMatrix();

    //Adjaciencies
    graphs.makeAdjacency(gCount, minVertexes, vCounts, edgePairsArray);
    graphs.printAdjacency(gCount, minVertexes, vCounts);

    //Linked Objects
    
    //resize our nodeList to fit all graphs
    nodeList.resize(gCount);
    
    //Create our nodes for each graph
    for(int i = 0; i < gCount; i++) {
        //Determine highest node id
        if(minVertexes[i] <= 0) {
            maxVertex = vCounts[i] - minVertexes[i];
        } else {
            maxVertex = vCounts[i] + minVertexes[i];
        }
        //Create each node
        for(int j = minVertexes[i]; j < maxVertex; j++) {
            nodeList[i].push_back(Node(j, edgePairsArray[i]));
        }

        //now we link each node and its neighbors (Had to wait till to avoid seg faulting)

        //for each node
        for(Node& currNode : nodeList[i]) {
            //for each neighbor
            for(int currNeighbor : currNode.myNeighbors) {
                //find neighbor and push back onto Node Neighbors
                for (Node& potentialNeighbor : nodeList[i]) {
                    if (potentialNeighbor.getID() == currNeighbor) {
                        currNode.addNodeNeighbor(&potentialNeighbor);
                        break;
                    }
                }
            }
        }
    }
    //! End of Graph Creation and Visualization

    //! Start of Depth-First Traversals and Breadth First Traversals

    //Execute DPS Traversal for each Graph
    for(int i = 0; i < gCount; i++) {
        Traversals::DPS(&nodeList[i][0]);
        cout << endl;
    }

    //Execute BFS Traversal for each Graph


    //! End of Depth-First Traversals and Breadth First Traversals
    
    cout << "done";
    return 0;
}