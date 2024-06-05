#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

class Node {

    public:
        //constructor
        Node(int id, std::vector<std::pair<int,int>> myNeighbors);

        //getters
        int getID();
        
    private:
        int myId;
        std::vector<int> myNeighbors;
        bool isProcessed;
        void addNeighbor(int neighborID);
};

#endif