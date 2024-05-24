#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Assignment2\HeaderFiles\Sorts.hpp"
#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Assignment2\HeaderFiles\Searches.hpp"
#include <fstream>

using namespace std;

const int arraySize = 666;
const int randSize = 42;
int main() {

//Instance Variables
string fileArray[arraySize];
string fileLine;
int itemNum = 0;
string randArray[randSize];
int linearComparisons = 0;
int binaryComparisons = 0;
int linearAverage = 0;
int binaryAverage = 0;

//! Read File and filter contents into Array
    //Open File to be Read
    ifstream myFile ("magicitems.txt");
    
    if(!myFile) {
        cout << "File Could Not Be Read" << endl;
    } else {
        //Check to see if file s
        while(!myFile.eof()) {

            //get next line from file to manipulate
            getline(myFile, fileLine);

            //Filter the inputs 
            for(std::string::size_type i = 0; i < fileLine.length(); i++) {
                //Check char's ASCII to see if its uppercase
                if(int(fileLine[i] >= 65 && int(fileLine[i] <= 90))) {
                    fileLine[i] = char(int(fileLine[i] + 32));
                // Check for spaces
                } else if(fileLine[i] == ' '|| fileLine[i] == '\t') { 
                fileLine.erase(i, 1);
                i--; // Decrement i to handle the shifting of characters after removing the space
                } 
            }

            //Add filtered String to the array
            fileArray[itemNum] = fileLine;
            itemNum++;

        }
    }
//! End of Read File and Filter Contents into Array

//! Begin Function Calls
    //Sort the Inputs
    Sorts::insertionSort(fileArray, arraySize);

    //Select Random 42 Elements
    Searches::randSelect(fileArray, randArray, arraySize, randSize);

    //Preform a Linear Search on the Randomly Selected Items
    for(int i = 0; i < randSize; i++) {
        Searches::linearSearch(fileArray, randArray[i], linearComparisons);
    }

    //Calculate Linear Search Average Comparisons and Print Results
    linearAverage = (linearComparisons / randSize);
    cout << "Linear Search Comparisons: " << linearComparisons << endl;
    cout << "Average Linear Search Comparisons: " << linearAverage << endl;
    
    //Preform a Binary Search on the Randomly Selected Items
    for(int i = 0; i < randSize; i++) {
        Searches::binarySearch(fileArray, randArray[i], binaryComparisons, arraySize);
    }

    //Calculate Binary Search Average Comparisons and Print Results
    binaryAverage = (binaryComparisons / randSize);
    cout << "Binary Search Comparisons: " << binaryComparisons << endl;
    cout << "Average Binary Search Comparisons: " << binaryAverage << endl;

    return 0;
}