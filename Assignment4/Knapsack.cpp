#include "Knapsack.hpp"
#include <float.h>

Knapsack::Knapsack(int newSize) {
    mySize = newSize;
    mySpiceCount = 0;
    myTotPrice = 0;
}

int Knapsack::getSize() {
    return mySize;
}

void Knapsack::setTotPrice(float newTotalPrice) {
    myTotPrice = newTotalPrice;
}

void Knapsack::greedy(std::vector<Spices*> spiceList, float* totalPrice) {
    // find total spice count to avoid segfaults of big bags
    int totSpice = 0;
    for(Spices* spice : spiceList) {
        totSpice += spice->getQuant();
    }

    // if there is room in our sack
    while(mySize > mySpiceCount && totSpice > 0) {
        // Find Biggest Spice to add
        float currSize = 0;
        float max = FLT_MIN;
        Spices* maxSpice = nullptr;

        // find most expensive per cost spice
        for(Spices* spice : spiceList) {
            currSize = spice->getTotPrice() / spice->getQuant();
            if(currSize > max) {
                max = spice->getTotPrice() / spice->getQuant();
                maxSpice = spice;
            }
        }

        // Calculate the maximum number of instances we can add
        int availableQuantity = maxSpice->getQuant();
        int remainingCapacity = mySize - mySpiceCount;
        int quantityToAdd = std::min(availableQuantity, remainingCapacity);

        // Add the calculated number of instances to the sack
        if (quantityToAdd > 0) {
            float individualCost = maxSpice->getTotPrice() / maxSpice->getQuant();
            mySpices.push_back(new Spices(maxSpice->getName(), individualCost * quantityToAdd, quantityToAdd));
            mySpiceCount += quantityToAdd;
            maxSpice->setQuant(maxSpice->getQuant() - quantityToAdd);
            maxSpice->setTotPrice(maxSpice->getTotPrice() - individualCost * quantityToAdd);
            totSpice -= quantityToAdd;
            *totalPrice = *totalPrice + individualCost * quantityToAdd; //upd total price of knapsack
        }

    }
}

void Knapsack::printResult() {
    int comCount = mySpices.size();
    std::cout << "Knapsack of capacity " << this->mySize << " is worth " << this->myTotPrice << " quatloos and contains ";
    for(Spices* spice : this->mySpices) {
        if(spice->getQuant() == 1) {
            std::cout << spice->getQuant() << " scoop of " << spice->getName();
        } else {
            std::cout << spice->getQuant() << " scoops of " << spice->getName();
        }
        if(comCount == 1) {
            std::cout << ".";
        } else if(comCount == 2) {
            std::cout << ", and ";
            comCount--;
        } else{
            std::cout << ", ";
            comCount--;
        }
    }
    std::cout << std::endl;
}