//Akash Pai
//1/26/2023
//student cpp file
#include <iostream>
#include "student.h"
#include <cstring>
using namespace std;
//constructor
Student::Student() {
  fname = new char[80];
  lname = new char[80];
  id = 100,000;
  gpa = 0.00;
}
//setting input variables
Student::Student(char* newfname, char* newlname, int newid, float newgpa) {
  fname = new char[80];
  strcpy(fname, newfname);
  lname = new char[80];
  strcpy(lname, newlname);
  id = newid;
  gpa = newgpa;
  
}
//getters setters
int Student::getID() {
  return id;
}

char* Student::getFname() {
  return fname;
}

char* Student::getLname() {
  return lname;
}

float Student::getGPA() {
  return gpa;
}
