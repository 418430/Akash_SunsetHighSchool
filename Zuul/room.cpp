#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "room.h"

using namespace std;

Room::Room() {
  description = new char[100];
}

Room::Room(char* newdescription) {
  description = new char[100];
  strcpy(description, newdescription);
}

char* Room::getDescription() {
  return description;
}

void Room::addExit(char* direction, Room* newRoom) {
  exits.insert(pair<char*, Room*>(direction, newRoom));
}

//NOTE: Received getExit + hasExit function from Zayeed Saffat
Room* Room::getExit(char* direction) {
  for(auto it = exits.begin(); it != exits.end(); it++) {
    if(strcmp(it->first, direction) == 0) {
      return it->second;
    }
  }
  return NULL;
}

bool  Room::hasExit(char* direction) {
  for (auto it = exits.begin(); it != exits.end(); it++) {
    if (strcmp(it->first, direction) == 0) {
      return true;
    }
  }
  return false;
}

void Room::printExit() {
  cout << "Exits:" << endl;
  for (auto it = exits.begin(); it != exits.end(); it++) {
    cout << it->first << " to " << it->second->getDescription()<< endl;
  }
}
