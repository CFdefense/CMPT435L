#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Lab1\Header Files\Stack.hpp"
#include "C:\Users\CFdef\Documents\GitHub\LeetCode\CPP\Lab1\Header Files\Queue.hpp"
#include <iostream>
#include <fstream>

using namespace std;

const int arraySize = 666;

int main() {

    //Instance Variables
    string fileArray[arraySize];
    string fileLine;
    int itemNum = 0;
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
            for(int i = 0; i < fileLine.length(); i++) {
                //Check char's ASCII to see if its uppercase
                if(int(fileLine[i] >= 65 && int(fileLine[i] <= 90))) {
                    fileLine[i] = char(int(fileLine[i] + 32));
                }
            }

            //Add filtered String to the array
            fileArray[itemNum] = fileLine;
            itemNum++;

        }
    }
    
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