#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Assignment1\HeaderFiles\Stack.hpp"

    //null constructor
    Stack::Stack() {
        myTop = nullptr;
    };

    //push method
    bool Stack::push(int newValue) {
        bool result = false;
        if(!isFull()) {
            result = true;
            myNode* newGuy = new myNode(newValue);
            newGuy->setNext(myTop);
            myTop = newGuy;
        }
        return result;
    };

    //pop method
    int Stack::pop() {
        //set flag
        int popped = -1;

        if(!isEmpty()) {
            popped = myTop->getData();
            myTop = myTop->getNext();
        }
        return popped;
    };

    //isEmpty method
    bool Stack::isEmpty() {
        return(myTop == nullptr);
    };

    //isFull method
    bool Stack::isFull() {
        return false;
    };
    
    std::string Stack::printsList() {
        //Instance Variables
        Stack* tempStack = new Stack();
        std::string output;
        int curr = 0;
        
        //pop and add from original
        while(!isEmpty()) {
            curr = pop();
            output += std::to_string( curr ) + " ";
            tempStack->push(curr);
        }
        //push back to original
        while(!tempStack->isEmpty()) {
            push(tempStack->pop());
        }
        return output;
    };