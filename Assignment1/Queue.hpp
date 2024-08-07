#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Node.hpp"
#include <string>

class Queue {
public:
    // Constructors
    Queue();

    // Member functions
    bool enQueue(int newValue);
    myNode* deQueue();
    bool isFull();
    bool isEmpty();
    std::string printqList();

private:
    myNode* myFront;
    myNode* myRear;
};

#endif
