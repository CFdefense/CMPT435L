    #ifndef NODE_HPP
    #define NODE_HPP
    
    #include <string>

    class myNode {
    public: 
        // Constructors
        myNode();
        myNode(std::string newData);
        myNode(std::string newData, myNode* newNext);

        // Deconstructor
        ~myNode();

        // Getter methods
        std::string getData();
        myNode* getNext();

        // Setter methods
        void setData(std::string newData);
        void setNext(myNode* newNext);

    private:
        // Member variables
        std::string myData;
        myNode* myNext;
    };

    #endif
