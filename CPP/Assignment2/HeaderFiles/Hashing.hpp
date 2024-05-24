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

    static int makeHashCode(std::string str);

    public:

    //Constructor
    Hashing(int size);

    //Deconstructor
    ~Hashing();

    void add(std::string key, int value);
    void remove(std::string key);
    bool search(std::string key);

};


#endif