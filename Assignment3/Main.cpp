#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {

    //! File Reading and Manipulation

    // Counting Vertices and Edges using dynamic arrays
    vector<int> vCounts; 
    vector<int> eCounts;

    // Counting variables for each graph
    int vCount = 0;
    int eCount = 0;

    // Count number of graphs
    int gCount;

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
        }
    }

    //! End of File Reading and Manipulation

    //! Start of Graph Creation and Visualization

    return 0;
}



// General printing function for testing and visualization purposes
void printInfo(vector<int> vCounts, vector<int> eCounts, int gCount, vector<vector<pair<int,int>>> edgePairsArray) {
        cout << "Total number of graphs: " << gCount << endl;
        for(int i = 0; i < gCount; i++) {
            cout << "Graph #" << i + 1 << endl;
            cout << "Vertices " << vCounts[i] << endl;
            cout << "Edges " << eCounts[i] << endl;
            for(int j = 0; j < eCounts[i]; j++) {
                cout << "(" << edgePairsArray[i][j].first << "," << edgePairsArray[i][j].second << ")" << endl;
            }
        }
    }