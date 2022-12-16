//Akash Pai
//12/16/22
//Zuul is a text-based adventure game wehre the user has to acheieve an objective unbeknownst to them
#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;
//contents of functions defined in .h file
Item::Item(char* newdescription) {
  strcpy(description, newdescription);
}

char* Item::getDescription() {
  return description;
}
