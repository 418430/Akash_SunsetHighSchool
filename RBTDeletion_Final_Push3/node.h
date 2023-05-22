//Akash Pai
//Wednesday, 5/10/2023
//.h file for nodes - like a blueprint essentially. defines functions and variables
#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node{
  //variables of the node
  private:
    Node* left;
    Node* right;
    Node* parent;
    int value;
    int color; // value of one is red, value of 0 is black (note for later)
    
  public:
    //destructor and constructor for creating / destroying nodes
    Node(int newValue);
    ~Node();

    //setter functions
    void setLeft(Node* newLeft);
    void setRight(Node* newRight);
    void setParent(Node* newParent);
    void setValue(int newValue);
    void setColor(int newColor);
    void setBlack();
    void setRed();
    
    //getter functions
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    int getValue();
    int getColor();
};

#endif
