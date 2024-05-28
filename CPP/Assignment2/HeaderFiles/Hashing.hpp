#ifndef HASHING_HPP
#define HASHING_HPP

#include <string>
#include <vector>
#include <list>

#include "LinkedList.hpp"

class Hashing {
    
    private:
    static const int fileSize = 666;

    //Linked List - Nodes contain (std::string, int) pairs
    LinkedList* hashTable;

    public:

    //Constructor
    Hashing();

    //Deconstructor
    ~Hashing();

    //methods
    static int getHashCode(std::string str);
    void add(std::string value);
    void remove(std::string key);
    bool search(std::string key, int &comparisons);

};


#endif