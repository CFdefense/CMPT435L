#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Assignment2\HeaderFiles\Hashing.hpp"

//Number of Buckets for array
const int hashSizeUltimate = 250;

//! Hash Table is an array which each contains a linkedlist of HashCodes, LinkedList is updated if Collision

//Constructor
Hashing::Hashing() {
    hashTable.resize(hashSizeUltimate);
}

//Function to create the hashCode from a string
int Hashing::getHashCode(std::string &value) {
    int letterTotal = 0;
    for(std::string::size_type i = 0; i < value.length(); i++) {
        char letter = value.at(i);
        int charValue = (int)letter;
        letterTotal += charValue;
    }

    //Scale Lettertotal to Hash Table Size (hashCode -> Bucket to place)
    int hashCode = letterTotal % hashSizeUltimate;

    return hashCode;
}

void Hashing::add(std::string &value) {
    //Find bucket to place hash
    int index = getHashCode(value);

    //Create new Node
    myNode* newNode = new myNode(value);
    
    //call Add() on linkedlist at bucket
    hashTable[index].add(newNode);
}

void Hashing::remove(std::string &value) {
    //Find Bucket Hash is in
    int index = getHashCode(value);

    //Call Remove() Function on linkedlist in Bucket
    hashTable[index].remove(value);
}

bool Hashing::search(std::string &value, int &comparisons) {
    //Instance Variable
    bool result;

    //Find Bucket Value is in
    int index = getHashCode(value);

    //Get counts as one comparison therefore
    comparisons++;
    
    //Call Search to find if value exists in Hash
    result = hashTable[index].search(value, comparisons);

    return result;
}

