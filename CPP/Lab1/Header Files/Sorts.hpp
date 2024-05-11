#ifndef SORTS_HPP
#define SORTS_HPP

#include <string>

class Sorts {
    public:
    //Sorts
    static void selectionSort(std::string arr[], int size);
    void insertionSort();
    void mergeSort();
    void quickSort();
    void shuffleSort();
};



#endif