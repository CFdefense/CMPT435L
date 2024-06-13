    #include "Node.hpp"

    Node::Node(int vectorID) {
        myID = vectorID;
        isProcessed = false;
        myDistance = -1;
    }

    void Node::addNodeNeighbor(Node* neighbor, int cost) {
        myNodeNeighbors.push_back(std::pair(neighbor,cost)); //make pair and push
    }

    int Node::getID() {
        return myID;
    }

    bool Node::getProcessed() {
        return isProcessed;
    }

    void Node::setProcessed(bool newProcessed) {
        isProcessed = newProcessed;
    }

    void Node::setDistance(int newDistance) {
        myDistance = newDistance;
    }

    int Node::getDistance() {
        return myDistance;
    }