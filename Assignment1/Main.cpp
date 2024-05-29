#include "Sorts.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>
#include <fstream>

using namespace std;

const int arraySize = 666;

int main() {

    //Instance Variables
    string fileArray[arraySize];
    string fileLine;
    int itemNum = 0;
    int qsNumComparisons = 0;
    int msNumComparisons = 0;

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


//! Check if Palindrome and Print if Palindrome
    for(int i = 0; i < arraySize; i++) {
        string temp;
        //for loop for going through each letter starting at the last one
        for(int j = fileArray[i].length() - 1; j >= 0; j--) {
            //append to temp string effectively flipping it
            temp += fileArray[i][j];
        }
        if(temp.compare(fileArray[i]) == 0) {
            cout << fileArray[i] << " Is a Palindrome" << endl;
        }
    }
//! End of Check if Palindrome and Print if Palindrome

//! Sorts
    Sorts::selectionSort(fileArray, arraySize);
    Sorts::shuffleSort(fileArray, arraySize);
    Sorts::insertionSort(fileArray, arraySize);
    Sorts::shuffleSort(fileArray, arraySize);
    Sorts::quickSort(fileArray,0,arraySize-1, qsNumComparisons);
    std::cout << "QS Sort Comparisons: " << qsNumComparisons << std::endl;
    Sorts::shuffleSort(fileArray, arraySize);
    Sorts::mergeSort(fileArray,0,arraySize-1, msNumComparisons);
    std::cout << "MS Sort Comparisons: " << msNumComparisons << std::endl;
    cout << "Done" << endl;
//! End Sorts


    /*
    QUEUE AND STACK TESTING
    Queue* myQueue = new Queue();
    Stack* myStack = new Stack();
    int userInput = -1;
    int userInput2 = -1;
    int result = -1;
    bool enQresult;
    bool puResult;
    myNode* deQresult;
    string stackResult;
    string queueResult;

    while(userInput != 0) {

    cout << "1 - add to Stack/Queue; 2 - Remove from Stack/Queue; 3 - Display Stack/Queue" << endl;
    cin >> userInput;
    switch(userInput) {
        case 1:
            cout << "Add what?" << endl;
            cin >> userInput2;
            enQresult = myQueue->enQueue(userInput2);
            puResult = myStack->push(userInput2);
            cout << "EnQueue" << enQresult << "Stack" << puResult << endl;
            break;

        case 2:
            deQresult = myQueue->deQueue();
            result = myStack->pop();
            cout << "DeQueue" << deQresult->getData() << "Stack" << result << endl;
            break;
        case 3:
            stackResult = myStack->printsList();
            queueResult = myQueue->printqList();
            cout << "Stack is" << stackResult << endl;
            cout << "Queue is" << queueResult << endl;
            break;
    }
    }
    */

 return 0;
}