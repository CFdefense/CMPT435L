#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int main() {
    //Variables for file Manipulation
    string fileLine;
    bool newGraph = true;
    vector<vector<int>> Avertexes;
    vector<vector<tuple<int, int, int>>> Aedges;
    vector<int> Cvertex;
    vector<tuple<int, int, int>> Cedges;
    vector<int> minVertexes;
    int minVertex = std::numeric_limits<int>::max();
    
    //! Start of File Reading and Manipulation

    //read in a file and created directed weighted graphs
    // Open File to be Read
    ifstream myFile ("graphs2.txt.txt");
    
    if(!myFile) {
        cout << "File Could Not Be Read" << endl;
    } else {
        // While there is a line to look at
        while (getline(myFile, fileLine)) {
            if (fileLine.find("new") != string::npos) { // check if line says new indicating a new graph
                if (!newGraph) {
                    // if we have found a new graph we will push back temp values and reset them for next graph
                    Avertexes.push_back(Cvertex);
                    Aedges.push_back(Cedges);
                    minVertexes.push_back(minVertex);

                    //reset for next graph
                    minVertex = std::numeric_limits<int>::max();
                    Cvertex.clear();
                    Cedges.clear();
                }
                newGraph = false; // Now we move on to new graph
            } else { // otherwise will determine what the line requires us to do
            
                // 'Add Vertex' Case
                if (fileLine.find("add vertex") != string::npos) { 
                    // Find value of vertex
                    int vertexValue = 0;
                    bool foundDigit = false; // Flag to indicate if a first digit has been found
                    for (std::string::size_type i = 0; i < fileLine.length(); i++) {
                        // look for our first digit
                        if (isdigit(fileLine[i])) {
                            foundDigit = true;
                            vertexValue = vertexValue * 10 + (fileLine[i] - '0');
                        } else if (foundDigit) {
                            // If a digit has been found and the current character is not a digit then were done w 
                            break;
                        }
                    }
                // Update minVertex if the current vertexValue is smaller
                minVertex = std::min(minVertex, vertexValue);
                //add to cVertex
                Cvertex.push_back(vertexValue);
                // 'Add Edge' Case
                } else if(fileLine.find("add edge") != string::npos) {
                    //this data type is a tuple we must extract all 3 numbers
                    int tuple1,tuple2,tuple3;
                    bool found1,found2,found3;
                    std::string::size_type j;

                    // Extract our first number
                    for (std::string::size_type i = 0; i < fileLine.length(); i++) {
                        if ((int(fileLine[i]) >= 48) && (int(fileLine[i]) <= 57)) {
                            // Necessary for shifting digits left if multiple
                            tuple1 = tuple1 * 10 + (fileLine[i] - '0');
                            found1 = true;
                        } else if (found1) {
                            break;
                        }
                    }
                    // Extract our second number
                    for (j = 0; j < fileLine.length(); j++) {
                        //start after '-' to ensure we are finding second of the pair
                        if (fileLine[j] == '-') {
                            for (std::string::size_type m = j + 1; m < fileLine.length(); m++) {
                                if ((int(fileLine[m]) >= 48) && (int(fileLine[m]) <= 57)) {
                                    // Necessary for shifting digits left if multiple
                                    tuple2 = tuple2 * 10 + (fileLine[m] - '0');
                                    found2 = true;
                                } else if (found2) {
                                    break;                                        
                                }
                            }
                        }
                        break;
                    }
                    // Extract our third number starting after last
                    for(std::string::size_type k = j + 1; k < fileLine.length(); k++) {
                        if(((int(fileLine[k]) >= 48) && (int(fileLine[k]) <= 57)) || (int(fileLine[k]) == "- ADD HERE ASCII")) {

                        }
                    }
                    
                }
                


            }
        }
    }

    //close file
    myFile.close();

    return 0;
}


