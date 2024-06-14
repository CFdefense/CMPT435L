#include "Knapsack.hpp"

Knapsack::Knapsack(int newSize) {
    mySize = newSize;
    mySpiceCount = 0;
}

int Knapsack::getSize() {
    return mySize;
}

void Knapsack::greedy(std::vector<Spices> spiceList) {
    // if there is room in our sack
    if(mySize > mySpiceCount) {
        // Find Biggest Spice to add
        float currSize = 0;
        float max = FLT_MIN;
        Spices maxSpice;
        for(Spices spice : spiceList) {
            currSize = spice.getTotPrice() / spice.getQuant();
            if(currSize > max) {
            maxSpice = spice;
            }
        }

        // Calculate the maximum number of instances we can add
        int availableQuantity = maxSpice.getQuant();
        int remainingCapacity = mySize - mySpiceCount;
        int quantityToAdd = std::min(availableQuantity, remainingCapacity);

        // Add the calculated number of instances to the sack
        if (quantityToAdd > 0) {
            float individualCost = maxSpice.getTotPrice() / maxSpice.getQuant();
            mySpices.push_back(Spices(maxSpice.getName(), individualCost * quantityToAdd, quantityToAdd));
            mySpiceCount += quantityToAdd;
            maxSpice.setQuant(maxSpice.getQuant() - quantityToAdd);
            maxSpice.setTotPrice(maxSpice.getTotPrice() - individualCost * quantityToAdd);
        }

    }
}