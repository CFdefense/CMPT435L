#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include "Spices.hpp"
#include <vector>

class Knapsack {

    public:

    // constructor
    Knapsack(int newSize);

    // get
    int getSize();

    // method
    void greedy(std::vector<Spices> spiceList);

    private:
    int mySize;
    std::vector<Spices> mySpices;
    int mySpiceCount;
    
};

#endif