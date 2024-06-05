#include "LinkedObjs.hpp"

//Null Constructor
LinkedObjs::LinkedObjs() {
    myHead = nullptr;
};

void LinkedObjs::addVertex(int j) {
    //create new node
    Node* newNode = new Node(j);
    //add to the list
    if(myHead == nullptr) {
            myHead = newNode;
        //otherwise we traverse the linkedlist and add to end
        } else {
            Node* curr = myHead;
            Node* prev = nullptr;
            while(curr != nullptr) {
                prev = curr;
                curr = curr->getNext();
            }
            if(prev != nullptr) {
                prev->setNext(newNode);
            }
        }
};

void LinkedObjs::addEdge(std::pair<int, int> pair) {
    //get our edge
    int first = pair.first;
    int second = pair.second;
    //to keep track and get us out of looking
    bool fFound = false;
    bool sFound = false;
    //find and add neighbors to Nodes
    Node* curr = myHead;
    //traverse our linkedlist to find both nodes and then add their neighbors
    while(curr != nullptr) {
        //check if weve already found and updated both
        if(fFound && sFound) {
            break;
        }
        if(curr->getID() == first) {
            //setNeighbor and update found
            curr->addNeighbor(second);
            fFound = true;
        } else if(curr->getID() == second) {
            //setNeightbor and update found
            curr->addNeighbor(first);
            sFound = true;
        }
        curr = curr->getNext();
    }
}