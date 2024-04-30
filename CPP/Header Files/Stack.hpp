#ifndef STACK_HPP
#define STACK_HPP

#include "Node.hpp"

class Stack {
public:
    // Constructors
    Stack();

    // Member functions
    bool push(int newValue);
    int pop();
    bool isEmpty();
    bool isFull();

private:
    myNode* myTop;
};

#endif