//Akash Pai
//11/4/22
//CPP for videogames. Defines constructor, destructor, methods for grabbing fields
#include <iostream>
#include <cstring>
#include "videogames.h"


using namespace std;

Game::Game() {
  publisher = new char[80];
  rating = 0;
}

Game::Game(char* newpublisher, int temp, char* newtitle, int newyear) {
  publisher = new char[80];
  title = new char[80];
  strcpy(publisher, newpublisher);
  strcpy(title, newtitle);
  rating = temp;
  year = newyear;
}

Game::~Game() {
  delete[] publisher;
  delete[] title;
}

char* Game::getPublisher() {
  return publisher;
}

int Game::getRating() {
  return rating;
}
