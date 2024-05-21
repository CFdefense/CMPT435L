#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Lab1\HeaderFiles\Node.hpp"

    //constructor 
    myNode::myNode() {
        myData = -1;
        myNext = nullptr;
    };

    //half constructor
    myNode::myNode(int newData) {
        myData = newData;
        myNext = nullptr;
    };

    //full constructor
    myNode::myNode(int newData, myNode* newNext) {
        myData = newData;
        myNext = newNext;
    };

    //get methods
    int myNode::getData() { return myData; };
    myNode* myNode::getNext() { return myNext; };

    //set methods
    void myNode::setData(int newData) {myData = newData; };
    void myNode::setNext(myNode* newNext) {myNext = newNext; };