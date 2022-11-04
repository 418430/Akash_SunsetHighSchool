//Akash Pai
//11/4/22
//Header class for media, Parent class for movies, videogames, music
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
using namespace std;

class media {
 public:
  media();
  char* getTitle();
  int getYear();
 protected:
  char* title;
  int year;
};

#endif
