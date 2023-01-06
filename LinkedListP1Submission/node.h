#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"
using namespace std;

class Node {
 public:
  Node(Student* newstudent);
  ~Node();
  Student* getStudent();
  void setNext(Node* newnext);
  Node* getNext();
 private:
  Node* next;
  Student* student;
};
#endif
