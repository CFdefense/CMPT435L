#include <iostream>

using namespace std;

class Node {

public: 

    //constructor 
    Node() {
        myData = -1;
        myNext = nullptr;
    };

    //half constructor
    Node(int newData) {
        myData = newData;
        myNext = nullptr;
    };

    //full constructor
    Node(int newData, Node* newNext) {
        myData = newData;
        myNext = newNext;
    };

    //get methods
    int getData() { return myData; };
    Node* getNext() { return myNext; };

    //set methods
    void setData(int newData) {myData = newData; };
    void setNext(Node* newNext) {myNext = newNext; };
    
private:
    //private vars
    int myData;
    Node* myNext;
};