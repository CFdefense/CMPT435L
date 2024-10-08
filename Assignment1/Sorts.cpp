#include "Sorts.hpp"
#include <iostream>
void Sorts::selectionSort(std::string arr[], int arrSize) {
    std::string currentMin;
    std::string temp;
    int numComparisons = 0;
    //for loop to indicate how many passes
    for(int i = 0; i < arrSize; i++) {
        //for loop to find smallest
        currentMin = arr[i];
        int location = i;
        for(int j = i; j < arrSize; j++) {
            numComparisons++;
            if(arr[j].compare(currentMin) < 0) {
                currentMin = arr[j];
                location = j;
            }
        }
        //swap
        swap(&arr[i], &arr[location]);
    }
    std::cout << "Selection Sort Comparisons: " << numComparisons << std::endl;
}; 

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

void Sorts::mergeSort(std::string arr[], int start, int end, int &numComparisons) {
    //instance variable
    int middle = start + (end-start) / 2;
    
    //base case
    if(start >= end) {
        return;
    }
    
    //recursive case
    //left split
    mergeSort(arr, start, middle, numComparisons);
    //right split
    mergeSort(arr, middle+1, end, numComparisons);
    //merge splitted in sorted fashion
    merge(arr, start, middle, end, numComparisons);
};

void Sorts::merge(std::string arr[], int start, int middle, int end, int &numComparisons) {
    //Instance Variables
    int len = end-start + 1;
    std::string* temp = new std::string[len];   
    //create pointers
    int i = start;
    int j = middle + 1;
    //counter
    int k = 0;

    //merge subarrays into temp array
    while(i <= middle && j <= end) {
        numComparisons++;
        if(arr[i] <= arr[j]) {
            //add i to temp and post increment
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    //copy any remaining elements
    while(i <= middle) {
        temp[k++] = arr[i++];
    }
    while(j <= end) {
        temp[k++] = arr[j++];
    }

    //copy temp array onto main array
    for(int m = 0; m < len; m++) {
        arr[start + m] = temp[m];
    }

    //garbage collection
    delete[] temp;
};

void Sorts::quickSort(std::string arr[], int start, int end, int &numComparisons) {
    //recusively call while start < end
    if(start < end) {
        //find pivot and sort around the pivot
        int pivot = quickSubset(arr, start, end, numComparisons); 
        //recursive call the right of the pivot
        quickSort(arr, pivot + 1, end, numComparisons);
        //recursive call the left of the pivot
        quickSort(arr, start, pivot - 1, numComparisons); 
    }
};

int Sorts::quickSubset(std::string arr[], int start, int end, int &numComparisons) {
    //Method to find pivot and sort around it

    //set pivot to be last element
    std::string pivot = arr[end];
    //set var to count the amount of elements that have been moved
    int curr = start - 1;

    //go through all previous elements and determine which side of the pivot they fall on
    for(int i = start; i < end; i++) {
        numComparisons++;
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
    //Instance Variables
    int randNum;
    std::random_device rand; //create random number generator
    std::mt19937 gen(rand()); //create Mersenne Twister random generator
    int upperBound = size; //upper bound for random generated number
    int lowerBound = 0; //lower bound for random generated number
    int numComparisons = 0;

    //Create the distribution
    std::uniform_int_distribution<> distr(lowerBound, upperBound-1);

    //perform the shuffle 
    for(int i = size-1; i >= 0; i--) {
        randNum = distr(gen);
        swap(&arr[i], &arr[randNum]);
        numComparisons++;
    }
    std::cout << "Shuffle Comparisons: " << numComparisons << std::endl;
};

//general swapping method
void Sorts::swap(std::string* str1, std::string* str2) {
    std::string temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}
