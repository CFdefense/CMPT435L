#include "Node.hpp"

//constructor
Node::Node(int id) {
    myId = id;
    isProcessed = false;
    //maybe some initializing of vector to empty
    Node* myNext = nullptr;
}
Node::Node(int id, Node* newNext) {
    myId = id;
    isProcessed = false;
    //maybe some initializing of vector
    Node* myNext = newNext;
}

void Node::addNeighbor(int neighborID) {
    myNeighbors.push_back(neighborID);
}

Node* Node::getNext() {
    return myNext;
}

int Node::getID() {
    return myId;
}

void Node::setNext(Node* newNext) {
    myNext = newNext;
}