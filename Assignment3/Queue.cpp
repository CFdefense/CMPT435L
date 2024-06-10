#include "Queue.hpp"

    //null constructor
    Queue::Queue() {
        myFront = nullptr;
        myRear = nullptr;
    };

    //enQueue method
    bool Queue::enQueue(Node* newGuy) {
        //Instance Variables
        bool result = false;
        //Add if Empty, if not add to front
        if(isEmpty()) {
            result = true;
            myFront = newGuy;
            myRear = newGuy;
        }
        else if(!isFull()) {
            result = true;
            newGuy->setNext(myFront);
            myFront = newGuy;
        }
        return result;
    };
    
    //deQueue method
    Node* Queue::deQueue() {
        //Instance Variables
        Node* result = nullptr;
        Node* curr = myFront;
        Node* prev = nullptr;

        if(!isEmpty()) {
            //Iterate through the linked list until the last node
            while(curr != myRear) {
                prev = curr;
                curr = curr->getNext();
            }//while

            //Now that we've tranversed the linked list we must now determined what to do
            if (prev == nullptr) {
            // If prev is still nullptr, it means myFront is the only node
                result = myFront;
                myFront = nullptr;
                myRear = nullptr;
            } else {
                    result = myRear;
                    prev->setNext(nullptr); // Update the next pointer of the second-to-last node
                    myRear = prev; // Update myRear to point to the new last node
            }
        }
        return result;
    };

    //isFull method
    bool Queue::isFull() {
        return false;
    };

    //isEmpty method
    bool Queue::isEmpty() {
        return(myFront == nullptr);
    };

    std::string Queue::printqList() {
        //instance variables
        std::string output;
        Node* curr = myFront;
        while (curr != nullptr) {
            output += std::to_string(curr->getID()) + " ";
            curr = curr->getNext();
        }
    return output;
    };
    