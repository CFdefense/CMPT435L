#include "Stack.hpp"

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