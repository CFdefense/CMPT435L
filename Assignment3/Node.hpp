#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

class Node {

    public:
        //constructors
        Node(int id);
        Node(int id, std::vector<std::pair<int,int>> myNeighbors);

        //methods
        void addNeighbor(int neighborID);

        //getters
        Node* getNext();
        int getID();
        
        //setters
        void setNext(Node* newNext);

    private:
        int myId;
        std::vector<int> myNeighbors;
        bool isProcessed;
        Node* myNext;
};

#endif