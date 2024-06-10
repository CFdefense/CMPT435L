#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"
#include <iostream>

class BST {
    public:
    BST();
    void populate(std::string newGuy, int &numComparisons);

    private:
    BSTNode* myRoot;
};




#endif