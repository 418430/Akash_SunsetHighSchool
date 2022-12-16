#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <cstring>
#include <map>
#include "item.h"
using namespace std;

class Room {
 public:
  Room();
  Room(char*);
  char* getDescription();
  void addExit(char* direction, Room* newRoom);
  Room* getExit(char* direction);
  bool hasExit(char* direction);
  void printExit();
  void addItem(Item* item);
  vector<Item*> items;
  void printItems();
  Item* getItem(char* itemTemp);
  void removeItems(char* itemTemp);
 private:
  char* description;
  map<char*, Room*> exits;
};
