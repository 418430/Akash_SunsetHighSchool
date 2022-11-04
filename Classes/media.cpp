//Akash Pai
//11/4/22
//CPP for media. Defines functions used throughout all other classes like getTitle, getYear
#include <iostream>
#include "media.h"
#include <cstring>

media::media() {
  title = new char[80];
  year = 0;
}

char* media::getTitle() {
  return title;
}

int media::getYear() {
  return year;
}
