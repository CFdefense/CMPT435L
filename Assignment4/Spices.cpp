#include "Spices.hpp"

Spices::Spices(std::string newName, float newPrice, int newQuant) {
    myName = newName;
    myTotPrice = newPrice;
    myQuant = newQuant;
}

Spices::Spices() {
    myName = "";
    myTotPrice = 0;
    myQuant = 0;
}

void Spices::setQuant(int newQuant) {
    myQuant = newQuant;
}

void Spices::setTotPrice(float newTotPrice) {
    myTotPrice = newTotPrice;
}

std::string Spices::getName() {
    return myName;
}

float Spices::getTotPrice() {
    return myTotPrice;
}

int Spices::getQuant() {
    return myQuant;
}