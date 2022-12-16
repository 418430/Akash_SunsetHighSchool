#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>
using namespace std;
class Item {
  char description[100];
 public:
  Item(char* description);
  char* getDescription();
};
#endif
