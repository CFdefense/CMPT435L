#ifndef SPICES_HPP
#define SPICES_HPP

#include <string>

class Spices {

    public:

    //Constructor
    Spices(std::string newName, float newPrice, int newQuant);

    // Setters
    void setQuant(int newQuant);

    // Getters
    std::string getName();
    float getTotPrice();
    int getQuant();

    private:
    // Variables
    std::string myName;
    float myTotPrice;
    int myQuant;

};

#endif