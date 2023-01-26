//Akash Pai
//1/26/2023
//Student header file
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student {
 public:
  //constructor destructor
  Student();
  Student(char*, char*, int, float);
  //get variables
  char* getFname();
  char* getLname();
  int getID();
  float getGPA();
  char* fname;
  char* lname;
  int id;
  float gpa;
  
};

#endif
