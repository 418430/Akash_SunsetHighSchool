#include "node.h"
#include <iostream>

using namespace std;

Node::Node(Student* newstudent) {
  next = NULL;
  student = newstudent;
}

Node::~Node() {
  next = NULL;
  delete student;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

Node* Node::getNext() {
  return next;
}

Student* Node::getStudent() {
  return student;
}
