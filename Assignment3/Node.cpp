#include "Node.hpp"


Node::Node(int id, std::vector<std::pair<int, int>> pairs) {
    myId = id;
    isProcessed = false;
    //add neighbors
    for(int i = 0; i < pairs.size(); i++) {
        int first = pairs[i].first;
        int second = pairs[i].second;
        if(first == myId) {
            this->addNeighbor(second);
        }
        if(second == myId) {
            this->addNeighbor(first);
        }
    }
}

void Node::addNeighbor(int neighborID) {
    myNeighbors.push_back(neighborID);
}

int Node::getID() {
    return myId;
}