#include "SSSP.hpp"


bool SSSP::bellmanFord(Node* source, std::vector<Node>& nodeList) {

    // Initialize all distances to MAX and source to 0
    INIT(nodeList, source); //
    
    // Relax
    int vCount = nodeList.size();

    // loop through every edge V - 1 times
    for(int k = 0; k < vCount - 1; k++) {
        // FOR EVERY EDGE WE LOOP VERTEX -> Our edges are stored in vertexes therefore to reach every edge once we must loop every vertex
        for(int i = 0; i < vCount; i++) {
            // for every edge in vertex
            for(std::vector<std::pair<Node*, int>>::size_type j = 0; j < nodeList[i].myNodeNeighbors.size(); j++) {
                Node currNode = nodeList[i];
                Node* dest = nodeList[i].myNodeNeighbors[j].first;
                int weight = nodeList[i].myNodeNeighbors[j].second;
                relax(&currNode, dest, weight);
            }
        }
    }
    

    // Check for Negative cycles

    // for every vertex
    for(Node& currNode : nodeList) {
        // for every edge from that vertex
        for(std::pair currPair : currNode.myNodeNeighbors) {
            //if this is true that means there is negative cycles and we cant find use bellmanFord
            if(currPair.first->getDistance() > currNode.getDistance() + currPair.second) {
                return false;
            }
        }
    }
    return true;
}

void SSSP::relax(Node* curr, Node* dest, int weight) {
    //Curr = 1 Dest = 2 weigh = 6
    //check if candidate edge is a shorter path also checking for integer overflow
    if(curr->getDistance() != INT_MIN && curr->getDistance() + weight < dest->getDistance()) {
        dest->setDistance(curr->getDistance() + weight);

        //update path
        dest->myPath = curr->myPath;
        dest->myPath.push_back(dest->getID());
    }
}

void SSSP::INIT(std::vector<Node>& nodeList, Node* source) {
    for(Node& currNode : nodeList) {
        if(currNode.getID() == source->getID()) {
        currNode.setDistance(0);
        currNode.myPath.push_back(1); // path of itself
        } else { 
            currNode.setDistance(INT_MAX);
        }
        // add every path to start with

    }
}

void SSSP::printResults(std::vector<Node> nodeList) {
    // for each node in the graph well print its path
    for(std::vector<Node>::size_type i = 0; i < nodeList.size(); i++) {
        std::cout << "-- 1 --> " << nodeList[i].getID() << " cost is " << nodeList[i].getDistance() << "; path:";
        for(std::vector<int>::size_type j = 0; j < nodeList[i].myPath.size(); j++) {
            if(j == nodeList[i].myPath.size() - 1) { //if its the last one
                std::cout << " " << nodeList[i].myPath[j];
            } else {
                std:: cout << " " << nodeList[i].myPath[j] << " -->";
            }
        }
        std::cout << std::endl;
    }
}