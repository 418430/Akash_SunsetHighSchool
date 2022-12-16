#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <cstring>
#include <map>
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
 private:
  char* description;
  map<char*, Room*> exits;
};
