#ifndef SORTS_HPP
#define SORTS_HPP

#include <string>
#include <random> //for shuffleSort O(n)

class Sorts {
public:
    //Sorts
    static void selectionSort(std::string arr[], int size);
    static void insertionSort(std::string arr[], int size);
    static void mergeSort(std::string arr[],int start, int end, int &numComparisons);
    static void quickSort(std::string arr[], int start, int end, int &numComparisons);
    static void shuffleSort(std::string arr[], int size);

private:
    //private methods
    static int quickSubset(std::string arr[], int start, int end, int &numComparisons);
    static void swap(std::string* str1, std::string* str2);
    static void merge(std::string arr[], int start, int middle, int end, int &numComparisons);
};

#endif