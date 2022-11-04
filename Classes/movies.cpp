//Akash Pai
//11/4/22
//CPP for movies. Defines constructor, destructor, methods for grabbing fields like director, duration, rating, etc.
#include <iostream>
#include <cstring>
#include "movies.h"

using namespace std;

Movie::Movie() {
  director = new char[80];
  duration = 0;
  rating = 0;
}

Movie::Movie(char* newdirector, int newduration, int newrating, char* newtitle, int newyear) {
  director = new char[80];
  title = new char[80];
  strcpy(director, newdirector);
  strcpy(title, newtitle);
  duration = newduration;
  rating = newrating;
  year = newyear;
}

Movie::~Movie() {
  delete[] director;
  delete[] title;
}

char* Movie::getDirector() {
  return director;
}


int Movie::getDuration() {
  return duration;
}

int Movie::getRating() {
  return rating;
}

