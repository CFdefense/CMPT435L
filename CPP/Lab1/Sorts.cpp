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
        swap(&arr[i], &arr[location]);
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

void Sorts::quickSort(std::string arr[], int start, int end) {
    //recusively call while start < end
    if(start < end) {
        
        //find pivot and sort around the pivot
        int pivot = quickSubset(arr, start, end); 
        //recursive call the right of the pivot
        quickSort(arr, pivot + 1, end);
        //recursive call the left of the pivot
        quickSort(arr, start, pivot - 1); 
    }
};

int Sorts::quickSubset(std::string arr[], int start, int end) {
    //Method to find pivot and sort around it

    //set pivot to be last element
    std::string pivot = arr[end];
    //set var to count the amount of elements that have been moved
    int curr = start - 1;

    //go through all previous elements and determine which side of the pivot they fall on
    for(int i = start; i < end; i++) {  
        if(arr[i].compare(pivot) <= 0) {
            //if we found the element to be smaller were going to swap it with the # of curr were on
            curr++;
            swap(&arr[curr], &arr[i]);
        }
    }
    //we then move the pivot to the middle of the now partially sorted arr to split the lesser and greater elements
    swap(&arr[curr+1], &arr[end]);
    return curr + 1;
}

void Sorts::shuffleSort(std::string arr[], int size) {

};

//general swapping method
void Sorts::swap(std::string* str1, std::string* str2) {
    std::string temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}