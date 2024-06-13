#include "SSSP.hpp"


bool SSSP::bellmanFord(Node* source, std::vector<Node>& nodeList) {

    // Initialize all distances to MAX and source to 0
    INIT(nodeList, source); //
    
    // Relax
    int vCount = nodeList.size();

    // for every vertex
    for(int i = 0; i < vCount - 1; i++) {
        // for every Node in Nodelist
        for(Node& currNode : nodeList) {
            // for every edge in vertex
            for(std::pair currPair : nodeList[i].myNodeNeighbors) {
                relax(&currNode, currPair.first, currPair.second);
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
                return true;
            }
        }
    }
    return false;
}

void SSSP::relax(Node* curr, Node* dest, int weight) {
    
    //check if candidate edge is a shorter path also checking for integer overflow
    if(curr->getDistance() != INT_MAX && dest->getDistance() > curr->getDistance() + weight) {
        //update
        dest->setDistance(curr->getDistance() + weight);
    }
}

void SSSP::INIT(std::vector<Node>& nodeList, Node* source) {
    for(Node& currNode : nodeList) {
        if(currNode.getID() == source->getID()) {
        currNode.setDistance(0);
        } else { 
            currNode.setDistance(INT_MAX);
        }
    }
}