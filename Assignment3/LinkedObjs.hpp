#ifndef LINKEDOBJS_HPP
#define LINKEDOBJS_HPP

#include "Node.hpp"
#include <vector>

class LinkedObjs {

    public:
        //constructor
        LinkedObjs();
        
        //methods
        void addVertex(int id);
        void addEdge(std::pair<int, int> pair);

    private:
        Node* myHead;

};



#endif