#include "BST.hpp"

BST::BST() {
    myRoot = nullptr;
}

void BST::populate(std::string newStr, int &numComparisons) {
    //other instance variables
    BSTNode* curr = myRoot;
    int cValue;
    bool placed = false;
    int localComparisons = 0;

    //Check if tree is empty
    numComparisons++; // increment for if else below
    localComparisons++;
    if(myRoot == nullptr) {
        BSTNode* newGuy = new BSTNode(newStr);
        myRoot = newGuy;
        std::cout << "Initialized at Root" << std::endl;
    } else {
        //while we havent placed the node
        while(!placed) {

            //if its not empty we will traverse the tree for where it goes
            cValue = newStr.compare(curr->getValue());

            //if the value is bigger we check right
            numComparisons++; //increment for if else below
            localComparisons++;
            if(cValue > 0) {

                //check if right exists
                numComparisons++; //increment for if else below
                localComparisons++;
                if(curr->getRight() != nullptr) {
                    std::cout << "R";
                    //the right node is now our new node
                    curr = curr->getRight();
                } else {
                    //create node
                    BSTNode* newGuy = new BSTNode(newStr, curr);
                    curr->setRight(newGuy);
                    std::cout << "R";
                    placed = true;
                }
            } else { //if the value is smaller we check left
                numComparisons++; //increment for if else below
                localComparisons++;
                if(curr->getLeft() != nullptr) {
                    std::cout << "L";
                    curr = curr->getLeft();
                } else {
                    //create node
                    BSTNode* newGuy = new BSTNode(newStr, curr);
                    curr->setLeft(newGuy);
                    std::cout << "L";
                    placed = true;
                }
            }
        }
    }
    std::cout << " - " << localComparisons << " Comparisons";
}