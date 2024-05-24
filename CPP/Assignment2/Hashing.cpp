#include "Hashing.hpp"

const int hashSizeUltimate = 250;


//! Hash Table is an array which each contains a linkedlist of HashCodes, LinkedList is updated if Collision

//Constructor
Hashing::Hashing(int hashSize) {
    hashTable = new LinkedList[hashSize];
}

//Deconstructor
Hashing::~Hashing() {
    delete[] hashTable;
}

//Function to create the hashCode from a string
int Hashing::makeHashCode(std::string str) {
    int letterTotal = 0;
    for(int i = 0; i < str.length(); i++) {
        char letter = str.at(i);
        int charValue = (int)letter;
        letterTotal += charValue;
    }

    //Scale Lettertotal to Hash Table Size
    int hashCode = letterTotal % hashSizeUltimate;

    return hashCode;
}

void Hashing::add(std::string key, int value) {
    int index = makeHashCode(key);
    hashTable.add()
}

void Hashing::remove(std::string key) {
    
}

bool Hashing::search(std::string key) {

}

