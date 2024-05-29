#include "Sorts.hpp"

void Sorts::insertionSort(std::string arr[], int arrSize) {
    //1st always good loop through all
    int numComparisons = 0;
    for(int i = 1; i < arrSize; i++) {
        int j = i-1; //j will be our pointer to compare our current element to, starts at the one before current
        std::string curr = arr[i];
        //Scooch while current element is smaller
        while(j >= 0) {
            numComparisons++;
            if(curr < arr[j]) {
                arr[j+1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        //place curr element in its spot
        arr[j+1] = curr;
    }
    std::cout << "Insertion Sort Comparisons: " << numComparisons << std::endl;
};
