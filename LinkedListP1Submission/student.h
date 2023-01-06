#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student {
 public:
  Student();
  Student(int);
  int getID();
 private:
  int id;
};

#endif
