#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Header Files\Queue.hpp"

    //null constructor
    Queue::Queue() {
        myNode* myFront = nullptr;
        myNode* myRear = nullptr;
    };

    //enQueue method
    bool Queue::enQueue(int newValue) {
        //Instance Variables
        bool result = false;
        //Add if Empty, if not add to front
        if(isEmpty()) {
            result = true;
            myNode* newGuy = new myNode(newValue);
            myFront = newGuy;
            myRear = newGuy;
        }
        else if(!isFull()) {
            result = true;
            myNode* newGuy = new myNode(newValue);
            newGuy->setNext(myFront);
            myFront = newGuy;
        }
        return result;
    };
    
    //deQueue method
    int Queue::deQueue() {
        //Instance Variables
        bool result = false;
        myNode* curr = myFront;
        myNode* prev = nullptr;

        if(!isEmpty()) {
            result = true;
            //Iterate through the linked list until the last node
            while(curr != myRear) {
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
    bool Queue::isFull() {
        return false;
    }

    //isEmpty method
    bool Queue::isEmpty() {
        return(myFront == nullptr);
    };