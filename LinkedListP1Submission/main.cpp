#include <iostream>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

//void add(Student* newstudent, Node* &head);
//void print(Node* next, Node* &head);

//Node* head = NULL;

int main() {
  //Node* head = NULL;
  //Node* tail = NULL;
  Student* student1 = new Student(1);
  Student* student2 = new Student(2);
  Student* student3 = new Student(3);

  Node* node1 = new Node(student1);
  Node* node2 = new Node(student2);
  Node* node3 = new Node(student3);

  //head->setNext(node1);
  node1->setNext(node2);
  node2->setNext(node3);
  //node3->setNext(tail);

  
  //print(head, head);
  
  //print(head, head);
  
  //print(head, head);

  cout << node1->getStudent()->getID() << endl;
  cout << node2->getStudent()->getID() << endl;
  cout << node3->getStudent()->getID() << endl;

  cout << endl;

  cout << node1->getStudent()->getID() << endl;
  cout << node1->getStudent()->getID() << endl;
  cout << node1->getNext()->getStudent()->getID() << endl;
  cout << node1->getStudent()->getID() << endl;
  cout << node1->getNext()->getStudent()->getID() << endl;
  cout << node1->getNext()->getNext()->getStudent()->getID() << endl;
  
}




//void print(Node* next, Node* &head) {
// if (next == head) {
//   cout << "List: ";
// }
// if (next != NULL) {
//   cout << next->getStudent()->getID() << " ";
//   print(next->getNext(), head);
// }
//}


