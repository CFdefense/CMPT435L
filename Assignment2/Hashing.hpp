#ifndef HASHING_HPP
#define HASHING_HPP

#include <string>
#include <vector>
#include <list>

#include "LinkedList.hpp"
class Hashing {
    
    private:
    static const int fileSize = 666;

    //array of LinkedList
    std::vector<LinkedList> hashTable;

    public:

    //Constructor
    Hashing();

    //methods
    static int getHashCode(std::string& value);
    void add(std::string &value);
    void remove(std::string &value);
    bool search(std::string &value, int &comparisons);

};


#endif