#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

class Node {

    public:
        //constructor
        Node(int vectorID);

        //getters
        int getID();
        bool getProcessed();
        int getDistance();

        //setter
        void setProcessed(bool newProcessed);
        void setDistance(int newDistance);
        //methods
        void addNodeNeighbor(Node* neighbor, int cost);

        std::vector<std::pair<Node*,int>> myNodeNeighbors;
        std::vector<int> myPath;
        
    private:
        //variables
        int myID;
        bool isProcessed = false;
        int myDistance;
};

#endif