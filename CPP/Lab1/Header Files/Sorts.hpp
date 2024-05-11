#ifndef SORTS_HPP
#define SORTS_HPP

#include <string>

class Sorts {
    public:
    //Sorts
    static void selectionSort(std::string arr[], int size);
    static void insertionSort(std::string arr[], int size);
    static void mergeSort(std::string arr[], int size);
    static void quickSort(std::string arr[], int size);
    static void shuffleSort(std::string arr[], int size);
};



#endif