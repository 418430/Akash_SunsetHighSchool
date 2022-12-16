//Akash Pai
//12/16/22
//Zuul is a text-based adventure game where the player has to acheive an objective, but they don't know what it is
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "room.h"
#include "item.h"
//cpp file for rooms

using namespace std;

Room::Room() {
  description = new char[100];
}

Room::Room(char* newdescription) {
  description = new char[100];
  strcpy(description, newdescription);
}

void Room::addItem(Item* item) {//adding items
  items.push_back(item);
}

Item* Room::getItem(char* itemTemp) {//returning items to main
  for(int i = 0; i < items.size(); i++) {
    if(strcmp(itemTemp, items[i]->getDescription()) == 0) {
      return items[i];
      break;
    }
  }
  return NULL;
}

void Room::removeItems(char* itemTemp) {//removing items
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(itemTemp, items[i]->getDescription()) == 0) {
      items.erase(items.begin()+i);
      break;
    }
  }
}

char* Room::getDescription() {
  return description;
}

void Room::addExit(char* direction, Room* newRoom) {//adding exits using c++ map
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

bool Room::hasExit(char* direction) {
  for (auto it = exits.begin(); it != exits.end(); it++) {
    if (strcmp(it->first, direction) == 0) {
      return true;
    }
  }
  return false;
}

void Room::printExit() {//prints exits and items
  cout << "Exits:" << endl;
  for (auto it = exits.begin(); it != exits.end(); it++) {
    cout << it->first << " to " << it->second->getDescription()<< endl;
  }
}

void Room::printItems() {//prints items
  cout << "Items in Room: " << endl;
  for (Item* i: items) {
    cout << i->getDescription() << endl;
  }
}
