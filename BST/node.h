/* Akash Pai
   4/5/2023
   This is the node.h file of the Binary Search Tree Project */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Node {
  //private varaibles (node pointer directions, value of node)
  private:
    int value;
    Node* left;
    Node* right;

  public:
    Node(int newValue); //constructor
    //getters
    Node* getLeft();
    Node* getRight();
    int getValue();
    //setters
    void setLeft(Node* newLeft);
    void setRight(Node* newRight);
    void setValue(int newValue);

};

#endif
