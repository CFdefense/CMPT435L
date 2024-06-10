#include "Traversals.hpp"

void Traversals::DFS(Node* vertex) {
    //if it hasnt been processed were going to process it and update it
    if(!(vertex->getProcessed())) {
        std::cout << vertex->getID() << " ";
        vertex->setProcessed(true);
    }
    //then we will do the same to all of its unprocessed neighbors
    for(Node* n : vertex->myNodeNeighbors) {
        if(!(n->getProcessed())) {
            DFS(n);
        }
    }
};

void Traversals::BFS(Node* vertex) {
    Queue newQueue;
    Node* currVertex;
    newQueue.enQueue(vertex);
    vertex->setProcessed(true);
    while(!newQueue.isEmpty()) {
        currVertex = newQueue.deQueue();
        std::cout << currVertex->getID() << " ";
        for(Node* neighbor : currVertex->myNodeNeighbors) {
            if(!neighbor->getProcessed()) {
                newQueue.enQueue(neighbor);
                neighbor->setProcessed(true);
            }
        }
    }
};