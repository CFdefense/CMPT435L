#include "Traversals.hpp"

void Traversals::DPS(Node* vertex) {
    //if it hasnt been processed were going to process it and update it
    if(!(vertex->getProcessed())) {
        std::cout << vertex->getID() << " ";
        vertex->updProcessed();
    }
    //then we will do the same to all of its unprocessed neighbors
    for(Node* n : vertex->myNodeNeighbors) {
        if(!(n->getProcessed())) {
            DPS(n);
        }
    }
};