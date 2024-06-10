#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <string>
class BSTNode {

    public:
    //constructor
    BSTNode(std::string newValue, BSTNode* newParent);
    BSTNode(std::string newValue);

    //getters
    std::string getValue();
    BSTNode* getRight();
    BSTNode* getLeft();
    BSTNode* getParent();

    //setters
    void setRight(BSTNode* newRight);
    void setLeft(BSTNode* newLeft);


    private:
    std::string myValue;
    BSTNode* myRight;
    BSTNode* myLeft;
    BSTNode* myParent;

};


#endif