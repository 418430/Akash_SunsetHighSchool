//Akash Pai
//12/16/22
//Zuul is a text-based adventure game where the player has to acheive an objective. Unfortunately, the objective is unbeknownst to them
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <cstring>
#include <map>
#include "item.h"
using namespace std;
//room class defines functions used in room.cpp
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
