#include "C:\Users\Christian\Documents\GitHub\LeetCode\CPP\Lab1\Header Files\Sorts.hpp"

void Sorts::selectionSort(std::string arr[], int arrSize) {
    std::string currentMin;
    std::string temp;
    //for loop to indicate how many passes
    for(int i = 0; i < arrSize; i++) {
        //for loop to find smallest
        currentMin = arr[i];
        int location = i;
        for(int j = i; j < arrSize; j++) {
            if(arr[j].compare(currentMin) < 0) {
                currentMin = arr[j];
                location = j;
            }
        }
        //swap
        temp = arr[i];
        arr[i] = arr[location];
        arr[location] = temp;
    }
}; 

void Sorts::insertionSort() {

};

void Sorts::mergeSort() {

};

void Sorts::quickSort() {

};

void Sorts::shuffleSort() {

};