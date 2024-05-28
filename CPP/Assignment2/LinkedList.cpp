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
        //Add regardless of bucket collision

        //If bucket is empty we just make the new node the front
        if(myHead == nullptr) {
            myHead = newNode;
        //otherwise we traverse the linkedlist and add to end
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

        // List is empty, nothing to remove
        if (myHead == nullptr) { return; }

        //If Value is at Head
        if(myHead->getValue().compare(str) == 0) {
            myNode* temp = myHead;
            myHead = myHead->getNext();
            delete temp;
            return;
        }

        //else traverse linked list and delete
        while(curr->getValue().compare(str) != 0) {
            prev = curr;
            curr = curr->getNext();
        }
        prev->setNext(curr->getNext());
        delete curr;
    }

    bool LinkedList::search(std::string str, int &comparisons) {
        bool found = false;
        myNode* curr = myHead;

        while(found == false && curr != nullptr) {
            comparisons++;
            if(curr->getValue().compare(str) == 0) {
                found = true;
            }
            curr = curr->getNext();
        }
        return found;
    }