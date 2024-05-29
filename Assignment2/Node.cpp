#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Assignment2\HeaderFiles\Node.hpp"
    //constructor 
    myNode::myNode() {
        myValue = "";
        myNext = nullptr;
    };

    //half constructor
    myNode::myNode(std::string newValue) {
        myValue = newValue;
        myNext = nullptr;
    };

    //full constructor
    myNode::myNode(std::string newValue, myNode* newNext) {
        myValue = newValue;
        myNext = newNext;
    };

    //get methods
    std::string myNode::getValue() { return myValue; };
    myNode* myNode::getNext() { return myNext; };

    //set methods
    void myNode::setValue(std::string newValue) {myValue = newValue; };
    void myNode::setNext(myNode* newNext) {myNext = newNext; };