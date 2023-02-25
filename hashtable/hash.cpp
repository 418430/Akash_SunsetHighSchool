//Akash Pai
//2/24/2023 - Recieved 1-Week Extension from Mr. Galbraith Due to Science Fair
//This project creates a student list using a hashtable - has funcs PRINT, QUIT, ADD, DELETE
#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <cstring>
#include <fstream>

using namespace std;
//student struct
struct Student {
  char fname[10];
  char lname[10];
  int id;
  float gpa;
  //constuctor, variables
public:
  Student(char* newFN, char* newLN, int newID, float newGPA) {
    strcpy(fname, newFN);
    strcpy(lname, newLN);
    id = newID;
    gpa = newGPA;
  }
};

class Node {
  Student* student;
  Node* next;
  //open functions
public:
  Node(Student* newStudent) {
    student = newStudent;
    next = NULL;
  }

  Student* getStudent() {
    return student;
  }
  void setStudent(Student* newStudent) {
    student = newStudent;
  }

  Node* getNext() {
    return next;
  }

  void setNext(Node* newnext) {
    next = newnext;
  }
};

//prototypes
int hashFunction(int id, int size); //retrieved online
void randomStudents(Node** &table, int numstudents, int &ranID, int size);
void print(Node* head);
void del(Node* &head, Node* current, Node* previous, int ID);
void add (Node* &head, Student* student);
void totalCollisions(Node* &head, int &maxCollisions);

int main() {
  bool playing = true;
  int size = 100;
  Node** table = new Node*[size];
  for (int i = 0; i < size; i++) {
     table[i] = NULL;
  }
  int id = 0;
  char move[20];
  int ranID = 1;
  //main program, plays until quit statement
  while (playing == true) {
    move[0] = 0;
    int maxCollisions = -1;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Would you like to add, print, delete, or quit (Enter ADD, PRINT, DELETE, or QUIT)?" << endl;
    cin >> move;
    //enter variables
    if(strcmp(move, "ADD") == 0) {
      move[0] = 0;
      cout << "Would you like to add manually or randomly (Enter MANUALLY or RANDOMLY)" << endl;
      cin >> move;
      if (strcmp(move, "MANUALLY") == 0) {
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
	//creates new student from input fields
	Student* student = new Student(fname, lname, id, gpa);
	//hashf index
	int index = hashFunction(student->id, size);
	add(table[index], student);
	for (int i = 0; i < size; i++) {
	  totalCollisions(table[i], maxCollisions);
	}
	//check for collisions
	if (maxCollisions > 3) {
	  //rehash
	  size = size*2;
	  Node** newa = new Node*[size];
	  for (int i = 0; i < size; i++) {
	    newa[i] = NULL;
	  }
	  for (int i = 0; i < size/2; i++) {
	    Node* n = table[i];
	    while (n != NULL) {
	      int index = hashFunction(n->getStudent()->id, size);
	      add(newa[index], n->getStudent());
	      n = n->getNext();
	    }
	  }
	  table = new Node*[size];
	  table = newa;
	}
	cout << "Max Collisions: " << maxCollisions << endl;
      }
      else if(strcmp(move, "RANDOMLY") == 0) {
	//random generator
	int numstu = -1;
	cout << "How many students would you like to add" << endl;
	cin >> numstu;
	randomStudents(table, numstu, ranID, size);
	for (int i = 0; i < size; i++) {
	  totalCollisions(table[i], maxCollisions);
	}
        if (maxCollisions > 3) {
      	  size = size*2;
          Node** newa = new Node*[size];
          for (int i = 0; i < size; i++) {
            newa[i] = NULL;
          }
          for (int i = 0; i < size/2; i++) {
            Node* n = table[i];
            while (n != NULL) {
              int index = hashFunction(n->getStudent()->id, size);
              add(newa[index], n->getStudent());
              n = n->getNext();
            }
          }
          table = new Node*[size];
          table = newa;
	}
      }
     }
    else if(strcmp(move, "PRINT") == 0) {
      for (int i = 0; i < size; i++) {
	print(table[i]);
      }
    }
   
    else if(strcmp(move, "DELETE") == 0) {
      //delete
      int idT;
      cout << "Enter the ID of the student you'd like to delete" << endl;
      cin >> idT;
      for (int i = 0; i < size; i++) {
	del(table[i], table[i], table[i], idT);
      }
    }
    else if(strcmp(move, "QUIT") == 0) {
      playing = false;
      break;
    } 
  }
}
//adds node. checks if there is alr one in that index, then chains if so
void add (Node *&head, Student* student) {
  Node * current = head;
  if (head == NULL) {
    Node * newnode = new Node(student);
    head = newnode;
  }
  else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    Node * newnode = new Node (student);
    current->setNext(newnode);
  }
}

//prints, per array index, then per node
void print (Node * head) {
  if (head != NULL) {
    while (head != NULL) {
      cout << head->getStudent()->fname << " " << head->getStudent()->lname << ", " << head->getStudent()->id << ", ";
      cout << setprecision(2) << fixed << head->getStudent()->gpa << endl;
      head = head->getNext();
    }
  }
}
//hashf
int hashFunction(int id, int size) {
  return id % size;
}
//counts colliisons (if more than 3, rehash)
void totalCollisions(Node* &head, int &maxCollisions) {
  int temp = 0;
  Node * current = head;
  if (head == NULL) {
    temp = 0;
    if (temp > maxCollisions) {
      maxCollisions = temp;
    }
  }
  else {
    int temp = 0;
    while (current != NULL) {
      current = current->getNext();
      temp++;
    }
    if (temp > maxCollisions) {
      maxCollisions = temp;
    }
  }
}
//random student generator, utilizes add function to add students
void randomStudents(Node** &table, int numstudents, int &ranID, int size) {
  srand(time(NULL));
  for (int i = 0; i < numstudents; i++) {
    int fline = rand() % 20 + 1;
    int lline = rand() % 20 + 1;
    //received this code from friend - reading from a file
    fstream fin;
    fstream lin;
    fin.open("firstnames.txt");
    lin.open("lastnames.txt");
    char* first = new char[100];
    char* last = new char[100];
    for (int j = 0; j < fline; j++) {
      fin >> first;
    }
    for (int j = 0; j < lline; j++) {
      lin >> last;
    }
    float GPA = float(rand()%501)/100;
    Student* student = new Student(first, last, ranID, GPA);
    ranID++;
    int index = hashFunction(student->id, size);
    add(table[index], student);

  }
}
//delete, checks for base cases, then proceeds.
void del(Node* &head, Node* current, Node* previous, int ID) {
  if (head == NULL) {
    return;
  }
  else if (current == NULL) {
    return;
  }
  else if (ID == current->getStudent()->id) {
    if (ID == head->getStudent()->id){
      Node * temp = head;
      head = head->getNext();
    }
    else {
      previous->setNext(current->getNext());
    }
  }
  else {
    del(head, current->getNext(), current, ID);
  }
  
}
