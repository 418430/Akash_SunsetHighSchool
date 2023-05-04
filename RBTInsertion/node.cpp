//Akash Pai
//Thursday, 4/27/2023
//.cpp file for nodes - outlines functions defined in .h file

#include <iostream>

#include "node.h"

using namespace std;

//constructor and destructor (so far idt i'll be using destructor, so leaving it empty
Node::Node(int newValue) {
  left = NULL;
  right = NULL;
  parent = NULL;
  color = 1; //NOTE TO SELF: 1 == red, 0 == black
  value = newValue; //straightforward
}

//destructor
Node::~Node() {
}

//getters: way i tell is that all getters are void, but setters are never void
void Node::setBlack() {
  color = 0;
}

void Node::setRed() {
  color = 1; //red
}

void Node::setValue(int newValue) {
  value = newValue;
}

void Node::setParent(Node* newParent) {
  parent = newParent;
}

void Node::setRight(Node* newRight) {
  right = newRight;
}

void Node::setLeft(Node* newLeft) {
  left = newLeft;
}

//setters: way i tell is all setters have return type,but all getters are void
Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}

Node* Node::getParent() {
  return parent;
}

int Node::getValue() {
  return value;
}

int Node::getColor() {
  return color;
}
