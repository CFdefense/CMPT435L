#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Assignment2\HeaderFiles\Node.hpp"

    //constructor 
    myNode::myNode() {
        myData = "";
        myNext = nullptr;
    };

    //half constructor
    myNode::myNode(std::string newData) {
        myData = newData;
        myNext = nullptr;
    };

    //full constructor
    myNode::myNode(std::string newData, myNode* newNext) {
        myData = newData;
        myNext = newNext;
    };

    //get methods
    std::string myNode::getData() { return myData; };
    myNode* myNode::getNext() { return myNext; };

    //set methods
    void myNode::setData(std::string newData) {myData = newData; };
    void myNode::setNext(myNode* newNext) {myNext = newNext; };