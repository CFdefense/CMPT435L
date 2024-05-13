#ifndef SORTS_HPP
#define SORTS_HPP

#include <string>

class Sorts {
    public:
    //Sorts
    static void selectionSort(std::string arr[], int size);
    static void insertionSort(std::string arr[], int size);
    static void mergeSort(std::string arr[], int size);
    static void quickSort(std::string arr[], int start, int end);
    static void shuffleSort(std::string arr[], int size);

    private:
    //private methods
    static int quickSubset(std::string arr[], int start, int end);
    static void swap(std::string* str1, std::string* str2);
};

#endif