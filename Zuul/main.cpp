#include <iostream>
#include <cstring>
#include "room.h"
#include <vector>
#include <map>    
#include <iomanip>

using namespace std;

void print(Room*);

int main() {
  vector<Room*> vect;
  char description[100];
  strcpy(description, "Lobby");
  vect.push_back(new Room(description)); //Room 0: Lobby
  strcpy(description, "Swimming Pool");
  vect.push_back(new Room(description)); //Room 1: Swimming Pool
  strcpy(description, "Spa");
  vect.push_back(new Room(description)); //Room 2: Spa
  strcpy(description, "Kitchen");
  vect.push_back(new Room(description)); //Room 3: Kitchen
  strcpy(description, "Pantry");
  vect.push_back(new Room(description)); //Room 4: Pantry
  strcpy(description, "Living Room");
  vect.push_back(new Room(description)); //Room 5; Living Room
  strcpy(description, "Studio");
  vect.push_back(new Room(description)); //Room 6: Studio
  strcpy(description, "BedroomA");
  vect.push_back(new Room(description)); //Room 7: Bedroom 1
  strcpy(description, "Bathroom");
  vect.push_back(new Room(description)); //Room 8: Bathroom
  strcpy(description, "BedroomB");
  vect.push_back(new Room(description)); //Room 9: Bedroom 2
  strcpy(description, "Cinema");
  vect.push_back(new Room(description)); //Room 10: Cinema
  strcpy(description, "Theater");
  vect.push_back(new Room(description)); //Room 11: Theater
  strcpy(description, "Bowling Alley");
  vect.push_back(new Room(description)); //Room 12: Bowling Alley
  strcpy(description, "Basketball Court");
  vect.push_back(new Room(description)); //Room 13: Basketball Court
  strcpy(description, "Tennis Court");
  vect.push_back(new Room(description)); //Room 14: Tennis Court
  
  char north[100];
  strcpy(north, "NORTH");
  char east[100];
  strcpy(east, "EAST");
  char south[100];
  strcpy(south, "SOUTH");
  char west[100];
  strcpy(west, "WEST");

  vect[0]->addExit(east, vect[1]);
  vect[0]->addExit(north, vect[10]);
  vect[0]->addExit(south, vect[3]);
  vect[1]->addExit(west, vect[0]);
  vect[1]->addExit(east, vect[2]);
  vect[2]->addExit(west, vect[1]);
  vect[3]->addExit(east, vect[4]);
  vect[3]->addExit(west, vect[5]);
  vect[4]->addExit(west, vect[3]);
  vect[5]->addExit(east, vect[3]);
  vect[5]->addExit(north, vect[6]);
  vect[5]->addExit(west, vect[6]);
  vect[6]->addExit(south, vect[5]);
  vect[7]->addExit(west, vect[5]);
  vect[7]->addExit(south, vect[8]);
  vect[8]->addExit(north, vect[7]);
  vect[8]->addExit(west, vect[9]);
  vect[9]->addExit(east, vect[8]);
  vect[10]->addExit(south, vect[0]);
  vect[10]->addExit(east, vect[12]);
  vect[10]->addExit(north, vect[11]);
  vect[11]->addExit(south, vect[10]);
  vect[12]->addExit(west, vect[10]);
  vect[12]->addExit(north, vect[13]);
  vect[13]->addExit(south, vect[12]);
  vect[13]->addExit(east, vect[14]);
  vect[14]->addExit(west, vect[13]);
    
  Room* current = vect[0];
  
  bool playing = true;
  cout << "Welcome to Zuul, a text-based adventure game where you travel a mansion, attempting to fulfill an objective unbeknownst to you. Good luck!" << endl;
  while (playing==true) {
    print(current);
    current->printExit();
    char move[100];
    move[0] = 0;
    cout << "What would you like to do (Enter: NORTH, SOUTH, EAST, WEST, TAKE, DROP, QUIT)" << endl;
    cin.get(move, 100);
    cin.get();
    move[strlen(move)] = '\0';
    if (strcmp(move, "NORTH") == 0 || strcmp(move, "SOUTH") == 0 || strcmp(move, "EAST") == 0 || strcmp(move, "WEST") == 0) {
      if (current->hasExit(move)==true) {
	current = current->getExit(move);
      }
      else {
	cout << "This room does not have the designated exit you entered. Please enter a different exit." << endl;
      }
    }
    else if (strcmp(move, "QUIT") == 0) {
      playing = false;
    }
  }
}

void print(Room* currentRoom) {
  cout << "You are in " << currentRoom->getDescription() << endl;
}
