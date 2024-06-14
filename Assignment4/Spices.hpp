#ifndef SPICES_HPP
#define SPICES_HPP

#include <string>

class Spices {

    public:

    //Constructor
    Spices(std::string newName, float newPrice, int newQuant);
    Spices();

    // Setters
    void setQuant(int newQuant);
    void setTotPrice(float newTotPrice);

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