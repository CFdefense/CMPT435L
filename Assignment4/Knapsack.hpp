#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include "Spices.hpp"
#include <vector>
#include <iostream>

class Knapsack {

    public:

    // constructor
    Knapsack(int newSize);

    // get
    int getSize();

    // method
    void greedy(std::vector<Spices*> spiceList, float* totalPrice);
    void printResult();
    void setTotPrice(float newTotalPrice);
    
    private:
    int mySize;
    std::vector<Spices*> mySpices;
    int mySpiceCount;
    int myTotPrice;
    
};

#endif