#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

class Node {

    public:
        //constructor
        Node(int id, std::vector<std::pair<int,int>> myNeighbors);

        //getters
        int getID();

        std::vector<int> myNeighbors;
        std::vector<Node*> myNodeNeighbors;
        void addNodeNeighbor(Node* newNeighbor);
        
    private:
        int myId;
        bool isProcessed = false;
        void addNeighbor(int neighborID);
};

#endif