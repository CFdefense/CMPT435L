#include "Node.hpp"

class Queue {

    public:
    //null constructor
    Queue() {
        Node* myFront = nullptr;
        Node* myRear = nullptr;
    };

    //enQueue method
    bool enQueue(int newValue) {
        //Instance Variables
        bool result = false;
        //Add if Empty, if not add to front
        if(isEmpty()) {
            result = true;
            Node* newGuy = new Node(newValue);
            myFront = newGuy;
            myRear = newGuy;
        }
        else if(!isFull()) {
            result = true;
            Node* newGuy = new Node(newValue);
            newGuy->setNext(myFront);
            myFront = newGuy;
        }
    };
    
    //deQueue method
    int deQueue() {
        //Instance Variables
        bool result = false;
        Node* curr = myFront;
        Node* prev = nullptr;

        if(!isEmpty()) {
            result = true;
            //Iterate through the linked list until the last node
            while(curr != nullptr) {
                prev = curr;
                curr = curr->getNext();
            }//while

            //Now that we've tranversed the linked list we must now determined what to do
            if (prev == nullptr) {
            // If prev is still nullptr, it means myFront is the only node
                myFront = nullptr;
                myRear = nullptr;
            } else {
                    prev->setNext(nullptr); // Update the next pointer of the second-to-last node
                    myRear = prev; // Update myRear to point to the new last node
            }
        }
        return result;
    };

    //isFull method
    bool isFull() {
        return false;
    }

    //isEmpty method
    bool isEmpty() {
        return(myFront == nullptr);
    };

    private:
        Node* myFront;
        Node* myRear;
};