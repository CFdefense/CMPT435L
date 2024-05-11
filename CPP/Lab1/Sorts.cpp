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

void Sorts::insertionSort(std::string arr[], int arrSize) {
    //1st always good loop through all
    for(int i = 1; i < arrSize; i++) {
        int j = i-1; //j will be our pointer to compare our current element to, starts at the one before current
        std::string curr = arr[i];
        //Scooch while current element is smaller
        while((curr < arr[j]) && (j >= 0)) {
            arr[j+1] = arr[j];
            j--;
        }
        //place curr element in its spot
        arr[j+1] = curr;
    }
};

void Sorts::mergeSort(std::string arr[], int size) {

};

void Sorts::quickSort(std::string arr[], int size) {

};

void Sorts::shuffleSort(std::string arr[], int size) {

};