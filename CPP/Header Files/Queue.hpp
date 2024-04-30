#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Node.hpp"

class Queue {
public:
    // Constructors
    Queue();

    // Member functions
    bool enQueue(int newValue);
    int deQueue();
    bool isFull();
    bool isEmpty();

private:
    myNode* myFront;
    myNode* myRear;
};

#endif
