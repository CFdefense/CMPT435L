#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

class Node {

    public:
        //constructor
        Node(int id, std::vector<std::pair<int,int>> myNeighbors);

        //getters
        int getID();
        bool getProcessed();
        Node* getNext();

        //setter
        void setProcessed(bool upd);
        void setNext(Node* newNode);


        std::vector<int> myNeighbors;
        std::vector<Node*> myNodeNeighbors;
        void addNodeNeighbor(Node* newNeighbor);
        
    private:
        int myId;
        bool isProcessed = false;
        void addNeighbor(int neighborID);
        Node* myNext;
};

#endif