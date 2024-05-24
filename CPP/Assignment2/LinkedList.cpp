#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Assignment2\HeaderFiles\LinkedList.hpp"

    //Constructor
    LinkedList::LinkedList() {
        myHead = nullptr;
    }

    //Deconstructor
    LinkedList::~LinkedList() {
        myNode* current = myHead;
        while (current != nullptr) {
            myNode* next = current->getNext(); // Get the next node before deleting the current one
            delete current; // Delete the current node
            current = next; // Move to the next node
        }
    }

    void LinkedList::setHead(myNode* newHead) {
        myHead = newHead;
    }

    myNode* LinkedList::getHead() {
        return myHead;
    }

    void LinkedList::add(myNode* newNode) {
        //Assuming were adding because there is a bucket collision
        if(myHead == nullptr) {
            myHead = newNode;
        } else {
            myNode* curr = myHead;
            myNode* prev;
            while(curr != nullptr) {
                prev = curr;
                curr = curr->getNext();
            }   
            prev->setNext(newNode);
        }
        
    }

    void LinkedList::remove(std::string str) {
        //Remove From LinkedList Assuming str is in the linkedlist
        myNode* curr = myHead;
        myNode* prev;

        if (myHead == nullptr) {
            // List is empty, nothing to remove
            return;
        }

        if(myHead->getData().compare(str) == 0) {
            myNode* temp = myHead;
            myHead = myHead->getNext();
            delete temp;
            return;
        }

        while(curr->getData().compare(str) != 0) {
            prev = curr;
            curr = curr->getNext();
        }
        prev->setNext(curr->getNext());
        delete curr;
    }

    bool LinkedList::search(std::string str) {
        bool found = false;
        myNode* curr = myHead;

        while(found == false && curr != nullptr) {
            if(curr->getData().compare(str) == 0) {
                found = true;
            }
            curr = curr->getNext();
        }
        return found;
    }