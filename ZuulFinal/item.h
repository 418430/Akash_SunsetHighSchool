//Akash Pai
//12/16/22
//Zuul is a text-based adventure game where the user has to acheive an objective. Unfortunately, the objective is unknown to them.
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>
using namespace std;
//.h file for item - defines items and functions used
class Item {
  char description[100];
 public:
  Item(char* description);
  char* getDescription();
};
#endif
