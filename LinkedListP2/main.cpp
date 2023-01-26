//Akash Pai
//1/26/2023
//Main file to set nodes, delete them, print, average and quit the program
#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

//void add(Student* newstudent, Node* &head);
//void print(Node* next, Node* &head);

//Node* head = NULL;

//adding program
void add(Node* c, Node* p, Node* &head, Student* newS) {
  Node* current = head;
  //check for empty list
  if(current == NULL) {
      head = new Node(newS);
      return;
  }
  //sort by ID, add nodes
  if (newS->getID() < head->getStudent()->getID()) {
    Node* newN = new Node(newS);
    newN->setNext(head);
    head = newN;
    return;
  }
  if (current!=NULL) {
    while(newS->getID() > current->getNext()->getStudent()->getID()) {
      current = current->getNext();
      if(current->getNext() == NULL) {
	break;
      }
    }
    if(current->getNext() == NULL) {
      current->setNext(new Node(newS));
    }
    else {
      Node* newN = new Node(newS);
      newN->setNext(current->getNext());
      current->setNext(newN);
    }
  }
}
//prints node using recursion
void print(Node* next, Node* head) {
  if (next == head) {
    cout << "List: " << endl;
  }
  if (next != NULL) {
    cout << next->getStudent()->getFname() << " " << next->getStudent()->getLname() << ", " << next->getStudent()->getID() << ", ";
    cout << setprecision(2) << fixed << next->getStudent()->getGPA() << endl;
    //recursive state
    print(next->getNext(), head);
  }
}
//delete nodes
void deleteN(Node* &head, Node* current, Node* previous, int ID) {
  //check for empty nodes
  if (head == NULL) {
    cout << "List is empty" << endl;
  }
  //check if head has id, delete head
  if (head->getStudent()->getID() == ID) {
    Node* temp = head;
    head = head->getNext();
    temp->~Node();
  }
  //element isnt in list
  else if (current == NULL) {
    cout << "Element is not in List" << endl;
  }
  //node other than head, if mathces input id, delete
  else if(current->getStudent()->getID() == ID) {
    previous->setNext(current->getNext());
    current->~Node();
  }
  else {
    //recursive case
    deleteN(head, current->getNext(), previous->getNext(), ID);
  }
}


void average(Node* next, Node* head, float &gpa2, int &times) {
  //average
  if (next == head) {
    times = times + 0;
    gpa2 = gpa2 + 0.00;
  }
  if (next != NULL) {
    times = times + 1;
    gpa2 = gpa2 + (next->getStudent()->getGPA());
    average(next->getNext(), head, gpa2, times);
  }
}

int main() {
  Node* head = NULL;
  bool playing = true;
  char move[20];
  //main program, plays until quit statement
  while (playing == true) {
    move[0] = 0;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Would you like to add, print, delete, average or quit (Enter ADD, PRINT, DELETE, AVERAGE, or QUIT)?" << endl;
    cin >> move;
    //enter variables
    if(strcmp(move, "ADD") == 0) {
      char* fname = new char[80];
      cout << "Enter a first name" << endl;
      cin >> fname;
      char* lname = new char[80];
      cout << "Enter a last name" << endl;
      cin >> lname;
      int id;
      cout << "Enter an ID Number" << endl;
      cin >> id;
      float gpa;
      cout << "Enter a GPA" << endl;
      cin >> gpa;
      Student* student = new Student(fname, lname, id, gpa);
      add(head, head, head, student);
    }
    //decide what function to use
    else if(strcmp(move, "PRINT") == 0) {
      print(head, head);
    }
    else if(strcmp(move, "AVERAGE") == 0) {
      float gpa2 = 0.00;
      int times = 0;
      average(head, head, gpa2, times);
      cout << setprecision(2) << fixed << gpa2/times << endl;
    }
    else if(strcmp(move, "DELETE") == 0) {
      int idT;
      cout << "Enter the ID of the student you'd like to delete" << endl;
      cin >> idT;
      deleteN(head, head->getNext(), head, idT);
    }
    else if(strcmp(move, "QUIT") == 0) {
      playing = false;
      break;
    } 
  }

  /*
  char* fname = new char[80];
  strcpy(fname, "Akash");
  char* lname = new char[80];
  strcpy(lname, "Pai");
  Student* student1 = new Student(fname, lname, 418430, 4.14);
  Student* student2 = new Student(fname, lname, 400221, 5.00);
  Student* student3 = new Student(fname, lname, 510000, 5.15);
  Student* student4 = new Student(fname, lname, 500000, 5.20);
  add(head, head, head, student1);
  add(head, head, head, student2);
  add(head, head, head, student3);
  add(head, head, head, student4);
  print(head, head);
  */
}
