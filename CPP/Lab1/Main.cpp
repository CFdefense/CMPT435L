#include "Stack.hpp"
#include "Queue.hpp"
#include <iostream>

using namespace std;

int main() {

    Queue* myQueue = new Queue();
    Stack* myStack = new Stack();
    int userInput = -1;
    int userInput2 = -1;
    int result = -1;
    bool enQresult;
    bool puResult;
    bool deQresult;
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
            cout << "DeQueue" << deQresult << "Stack" << result << endl;
            break;
        case 3:
            break;
    }
    }
 return 0;
}