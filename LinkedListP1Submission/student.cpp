#include <iostream>
#include "student.h"

using namespace std;

Student::Student() {
  id = 0;
}

Student::Student(int newid) {
  id = newid;
}

int Student::getID() {
  return id;
}
