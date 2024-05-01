    #ifndef STACK_HPP
    #define STACK_HPP

    #include "Node.hpp"
    #include <string>

    class Stack {
    public:
        // Constructors
        Stack();

        // Member functions
        bool push(int newValue);
        int pop();
        bool isEmpty();
        bool isFull();
        std::string printsList();

    private:
        myNode* myTop;
    };

    #endif