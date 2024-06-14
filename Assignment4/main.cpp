#include "SSSP.hpp"
#include "Knapsack.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int main() {
    // Variables for file Manipulation of Graphs
    string fileLine;
    bool newGraph = true;
    vector<vector<int>> aVertexes;
    vector<vector<tuple<int, int, int>>> aEdges;
    vector<int> cVertex;
    vector<tuple<int, int, int>> cEdges;
    vector<int> minVertexes;
    int minVertex = std::numeric_limits<int>::max();

    // Variables for Graph Creation
    vector<vector<Node>> nodeList;
    int findFirst;
    int findSecond;
    Node* second;
    bool secondFound;
    bool isNegCycle;
    vector<bool> negCycles;

    // Variables for file Manipulation of Spice
    string fileLine2;
    string newSpiceName;
    bool firstFound = false;
    bool second2Found = false;
    bool thirdFound = false;
    int newQuant = 0;
    float newTotPrice;
    vector<Spices> spiceList;
    vector<Knapsack> knapsackList;
    int newSize;

    //! Start of File Reading and Manipulation

    //read in a file
    // Open File to be Read
    ifstream myFile ("graphs2.txt");
    
    if(!myFile) {
        cout << "File Could Not Be Read" << endl;
    } else {
        // While there is a line to look at
        while (getline(myFile, fileLine)) {
            if (fileLine.find("new") != string::npos) { // check if line says new indicating a new graph
                if (!newGraph) {
                    // if we have found a new graph we will push back temp values and reset them for next graph
                    aVertexes.push_back(cVertex);
                    aEdges.push_back(cEdges);
                    minVertexes.push_back(minVertex);

                    //reset for next graph
                    minVertex = std::numeric_limits<int>::max();
                    cVertex.clear();
                    cEdges.clear();
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
                cVertex.push_back(vertexValue);
                // 'Add Edge' Case
                } else if(fileLine.find("add edge") != string::npos) {
                    //this data type is a tuple we must extract all 3 numbers
                    int tuple1 = 0,tuple2 = 0,tuple3 = 0;
                    bool found1 = false,found2 = false,found3 = false;
                    std::string::size_type first;
                    std::string::size_type second;
                    std::string::size_type forThird;
                    int firstLen = 0;
                    int secondLen = 0;
                    bool isNeg = false;

                    // Extract our first number
                    for (first = 0; first < fileLine.length(); first++) {
                        if ((int(fileLine[first]) >= 48) && (int(fileLine[first]) <= 57)) {
                            // Necessary for shifting digits left if multiple
                            tuple1 = tuple1 * 10 + (fileLine[first] - '0');
                            found1 = true;
                            firstLen++;
                        } else if (found1) {
                            break;
                        }
                    }
                    // Extract our second number
                    for (second = first + firstLen; second < fileLine.length(); second++) {
                        //start after '-' to ensure we are finding second of the pair
                        if (fileLine[second] == '-') {
                            for (forThird = second + 1; forThird < fileLine.length(); forThird++) {
                                if ((int(fileLine[forThird]) >= 48) && (int(fileLine[forThird]) <= 57)) {
                                    // Necessary for shifting digits left if multiple
                                    tuple2 = tuple2 * 10 + (fileLine[forThird] - '0');
                                    found2 = true;
                                    secondLen++;
                                } else if (found2) {
                                    break;                                        
                                }
                            }
                            break;
                        }
                    }
                    // Extract our third number starting after last
                    for(std::string::size_type k = forThird + secondLen; k < fileLine.length(); k++) {
                        //check for digits or - for negative
                        if(int(fileLine[k]) == 45) {
                            isNeg = true;
                        } else if((int(fileLine[k]) >= 48) && (int(fileLine[k]) <= 57)) {
                            // Necessary for shifting digits left if multiple
                            tuple3 = tuple3 * 10 + (fileLine[k] - '0');
                            found3 = true;
                        } else if(found3) {
                            break;
                        }
                    }
                    
                    // Add the tuple to Cedges
                    if (found1 && found2 && found3) {
                        if(isNeg) {
                            tuple3 *= -1;
                        }
                        cEdges.push_back(make_tuple(tuple1, tuple2, tuple3));
                    }
                }
            }
        }
        // add for last graph
        if (!newGraph || !cEdges.empty()) {
            aVertexes.push_back(cVertex);
            aEdges.push_back(cEdges);
            minVertexes.push_back(minVertex);
        }

    }   
    //close file
    myFile.close();


    // Now Spices

    // read in a file
    //open file to be read
    ifstream myFile2 ("spice.txt");
    
    if(!myFile2) {
        cout << "File Could Not Be Read" << endl;
    } else {
        // While there is a line to look at
        while (getline(myFile2, fileLine2)) {
            if (fileLine2.find("spice name") != string::npos) { // check if line says spice
                // found a line indicating a new spice
                // ex: "spice name = red;    total_price =  4.0;  qty = 4"

                // reset our values
                basic_string<char>::size_type i = 0;
                firstFound = false;
                second2Found = false;
                thirdFound = false;
                newSpiceName = "";
                newQuant = 0;
                newTotPrice = 0;
                // find = for myName
                while(!firstFound && i < fileLine2.length()) {
                    if(fileLine2[i] ==  '=') {
                        i = i + 2; // skip space
                        while(fileLine2[i] != ';') {
                            newSpiceName += fileLine2[i];
                            i++;
                        }
                        firstFound = true;
                    }
                    i++;
                }
                
                // find = for myTotPrice
                while(!second2Found && i < fileLine2.length()) {
                    if(fileLine2[i] == '=') {
                        i = i + 2; // skip space
                        string priceStr;
                        while(fileLine2[i] != ';') {
                            priceStr += fileLine2[i];
                            i++;
                        }
                        second2Found = true;
                        newTotPrice = stof(priceStr); // convert string to float
                    }
                    i++;
                }
                // find = for myQuant
                while(!thirdFound && i < fileLine2.length()) {
                    if(fileLine2[i] == '=') {
                        i++; // skip space
                        bool foundDigit = false;
                        newQuant = 0;
                        while(int(i) < int(fileLine2.length())) {
                            if (isdigit(fileLine2[i])) {
                            foundDigit = true;
                            newQuant = newQuant * 10 + (fileLine2[i] - '0');
                            } else if (foundDigit) {
                            // If a digit has been found and the current character is not a digit then were done w 
                            break;
                            }
                            i++;
                        }
                        thirdFound = true;
                    }
                    i++;
                }

                // create the spice and add to the list
                if(firstFound && second2Found && thirdFound) {
                    spiceList.push_back(Spices(newSpiceName, newTotPrice, newQuant));
                }
                

            } else if(fileLine2.find("knapsack capacity") != string::npos) {
                // found a line indicating a new knapsack
                // ex: knapsack capacity =  1;
                for(int i = 0; i < int(fileLine2.length()); i++) {
                    if(fileLine2[i] == '=') {
                        i++; //skip space
                        newSize = 0;
                        bool foundDigit = false;
                        while(fileLine2[i] != ';') {
                            if(isdigit(fileLine2[i])) {
                                newSize = newSize * 10 + (fileLine2[i] - '0');
                                foundDigit = true;
                            } else if(foundDigit) {
                                break;
                            }
                            i++;
                            
                        }
                    }
                }
                //create knapsack and add to our list
                knapsackList.push_back(Knapsack(newSize));

            }

        }
    }

    // close the file
    myFile2.close();

    //! End of File Reading and Manipulation

    //! Start of Graph Creation and Visualization

    // Create our Vertexes (Nodes)

    // resize nodelist to fit graphs
    nodeList.resize(aVertexes.size());

    // for each graph
    for(vector<vector<int>>::size_type i = 0; i < aVertexes.size(); i++) {
        // for each node
        for(int vertexID : aVertexes[i]) {
            nodeList[i].push_back(Node(vertexID));
        }
    }
    // add their neighbors and the costs

    // for each graph
    for(vector<vector<tuple<int,int,int>>>::size_type i = 0; i < aEdges.size(); i++) {
        // for each edge
        for(tuple edge : aEdges[i]) {
            secondFound = false;
            findFirst = get<0>(edge);
            findSecond = get<1>(edge);
            //for each Node
            for(vector<Node>::size_type j = 0; j < nodeList[i].size(); j++) {
                //see if the node is the one were looking for
                if(nodeList[i][j].getID() == findSecond) {
                    second = &nodeList[i][j];
                    secondFound = true;
                }
                if(nodeList[i][j].getID() == findFirst) {
                    if(secondFound) {
                        // if weve found the second already we add
                        nodeList[i][j].addNodeNeighbor(second,get<2>(edge));
                    } else {
                        // if we havent found the second find it then update
                        int k = j;
                        while(!secondFound) {
                            if(nodeList[i][k].getID() == findSecond) {
                                second = &nodeList[i][k];
                                secondFound = true;
                            }
                            k++;
                        }
                        // now add
                        nodeList[i][j].addNodeNeighbor(second,get<2>(edge));
                    }    
                }
            }
        }
    }

    //! End of Graph Creation and Visualization


    //! Start of Bellman-Ford Single-Source Shortest Path Algorithm

    // for each graph we call bellmanFord on the first vertex
    for(vector<vector<Node>>::size_type i = 0; i < nodeList.size(); i++) {
        Node source = nodeList[i][0];
        isNegCycle = SSSP::bellmanFord(&source, nodeList[i]);

        //store the results of each bellman
        negCycles.push_back(isNegCycle);
    }
    
    //print results
    for(vector<vector<Node>>::size_type i = 0; i < nodeList.size(); i++) {
        cout << "SSSP Source on Graph #" << i + 1 << ":" << endl;
        if(!negCycles[i]) {
            cout << "Source Node : " << nodeList[i][0].getID() << endl;
            for(vector<Node>::size_type j = 0; j < nodeList[i].size(); j++) {
            cout << "Node : " << nodeList[i][j].getID() << " Distance : " << nodeList[i][j].getDistance() << endl;
            }
        } else {
            cout << "Negative Cycle Exists - Bellman Ford Fails" << endl;
        }
    }

    // ! End of Bellman-Ford Single-Source Shortest Path Algorithm

    // ! Begin of Greedy Algorithm Spice Stealing SUH-OOST-AGEESTA-FALLAH

    //we have created already two vectors of our spice nodes and our knapsacks

    //now we will have every knapsack preform 'greedy' to fill itself
    for(int i = 0; i < knapsackList.size(); i++) {
        knapsackList[i].greedy(spiceList);
    }
    // ! End of Greedy Algorithm Spice Stealing SUH-OOST-AGEESTA-FALLAH
    
    return 0;
}


