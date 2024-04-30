#ifndef NODE_HPP
#define NODE_HPP

class myNode {
public: 
    // Constructors
    myNode();
    myNode(int newData);
    myNode(int newData, myNode* newNext);

    // Getter methods
    int getData();
    myNode* getNext();

    // Setter methods
    void setData(int newData);
    void setNext(myNode* newNext);

private:
    // Member variables
    int myData;
    myNode* myNext;
};

#endif
