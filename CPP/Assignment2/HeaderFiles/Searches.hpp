#ifndef SEARCHES_HPP
#define SEARCHES_HPP

#include <string>
#include <random>
#include <iostream>

class Searches {
    public:
    static void linearSearch(std::string arr[], std::string target, int &numComparisons);
    static void binarySearch(std::string arr[], std::string target, int &numComparisons, int size);
    static void randSelect(std::string arr[], std::string randoms[], int arrSize, int randSize);
};

#endif