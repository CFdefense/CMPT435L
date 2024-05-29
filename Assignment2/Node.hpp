    #ifndef NODE_HPP
    #define NODE_HPP
    
    #include <string>

    class myNode {
    public: 
        // Constructors
        myNode();
        myNode(std::string newValue);
        myNode(std::string newValue, myNode* newNext);

        // Getter methods
        std::string getValue();
        myNode* getNext();

        // Setter methods
        void setValue(std::string newValue);
        void setNext(myNode* newNext);

    private:
        // Member variables
        std::string myValue;
        myNode* myNext;
    };

    #endif
