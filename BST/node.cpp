/* Akash Pai
   4/5/2023
   This is the node.cpp file of the Binary Search Tree Project */

#include <iostream>
#include <fstream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(int newValue) {
    value = newValue;
    left = NULL;
    right = NULL;
}

Node* Node::getLeft() { //returns left node (getter)
    return left;
}

Node* Node::getRight() { //returns right node (getter)
    return right;
}

int Node::getValue() { //returns the value (data in node) - getter
    return value;
}

void Node::setLeft(Node* newLeft) { //sets the value for the left node (setter)
    left = newLeft;
}

void Node::setRight(Node* newRight) { //sets the value for the right node (setter)
    right = newRight;
}

void Node::setValue(int newValue) { //setter for value
    value = newValue;
}
