#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include "Spices.hpp"
#include <vector>

class Knapsack {

    public:

    //constructor
    Knapsack(int newSize);

    //get
    int getSize();

    private:
    int mySize;
    std::vector<Spices> mySpices;
    
};

#endif