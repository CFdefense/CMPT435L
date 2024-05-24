#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"
#include <string>

class LinkedList {
    public:
    LinkedList();
    ~LinkedList();

    myNode* getHead();
    void setHead(myNode* newHead);
    void add(myNode* newNode);
    void remove(std::string str);
    bool search(std::string str);

    private:
    myNode* myHead;

};


#endif