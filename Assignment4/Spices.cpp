#include "Spices.hpp"

Spices::Spices(std::string newName, float newPrice, int newQuant) {
    myName = newName;
    myTotPrice = newPrice;
    myQuant = newQuant;
}

void Spices::setQuant(int newQuant) {
    myQuant = newQuant;
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