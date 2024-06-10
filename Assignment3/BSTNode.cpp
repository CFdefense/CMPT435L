#include "BSTNode.hpp"

BSTNode::BSTNode(std::string newValue, BSTNode* newParent) {
    myValue = newValue;
    myParent = newParent;
    myRight = nullptr;
    myLeft = nullptr;
}
BSTNode::BSTNode(std::string newValue) {
    myValue = newValue;
    myParent = nullptr;
    myRight = nullptr;
    myLeft = nullptr;
}

BSTNode* BSTNode::getLeft() {
    return myLeft;
}

BSTNode* BSTNode::getRight() {
    return myRight;
}

BSTNode* BSTNode::getParent() {
    return myParent;
}

std::string BSTNode::getValue() {
    return myValue;
}

void BSTNode::setLeft(BSTNode* newLeft) {
    myLeft = newLeft;
}

void BSTNode::setRight(BSTNode* newRight) {
    myRight = newRight;
}