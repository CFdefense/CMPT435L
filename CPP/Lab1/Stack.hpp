#include "Node.hpp"

class Stack {

public:
    //null constructor
    Stack() {
        myTop = nullptr;
    };

    //push method
    bool push(int newValue) {
        bool result = false;
        if(!isFull()) {
            result = true;
            Node* newGuy = new Node(newValue);
            newGuy->setNext(myTop);
            myTop = newGuy;
        }
        return result;
    };

    //pop method
    int pop() {
        //set flag
        int popped = -1;

        if(!isEmpty()) {
            popped = myTop->getData();
        }
        return popped;
    };

    //isEmpty method
    bool isEmpty() {
        return(myTop == nullptr);
    };

    //isFull method
    bool isFull() {
        return false;
    };

private:
    //Node Var
    Node* myTop;
};