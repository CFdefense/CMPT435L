#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Assignment2\HeaderFiles\Searches.hpp"

void Searches::linearSearch(std::string arr[], std::string target, int &numComparisons) {
    bool found = false;
    int i = 0;
    while(found != true) {
        numComparisons++;
        if(arr[i].compare(target) == 0) {
            found = true;
        }
        i++;
    }
}

void Searches::binarySearch(std::string arr[], std::string target, int &numComparisons, int size) {
    int mid;
    int low = 0;
    int high = (size - 1);
    bool found = false;
    while((low <= high) && (!found)) {
        numComparisons++;
        mid = (low + (high - low) / 2); //find new middle
        
        //find how the current word compares to our target
        if(arr[mid].compare(target) < 0) {
            low = mid + 1;
        }
        else if(arr[mid].compare(target) > 0) {
            high = mid - 1;
        }
        else {
            found = true;
        }
    }
}

void Searches::randSelect(std::string arr[], std::string randoms[], int arrSize, int randSize) {

    //Instance Variables
    int randNum;
    std::random_device rand; //create random number generator
    std::mt19937 gen(rand()); //create Mersenne Twister random generator
    int upperBound = arrSize; //upper bound for random generated number
    int lowerBound = 0; //lower bound for random generated number
    int numComparisons = 0; 

    //Create the distribution
    std::uniform_int_distribution<> distr(lowerBound, upperBound-1);

    //perform the shuffle 
    for(int i = 0; i < randSize; i++) {
        randNum = distr(gen);
        //Add randomly selected word to randoms array
        randoms[i] = arr[randNum];
        numComparisons++;
    }
    std::cout << "Random Select Comparisons: " << numComparisons << std::endl;
}
