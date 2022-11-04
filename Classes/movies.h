//Akash Pai
//11/4/22
//Header class for movies
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public media {
 public:
  Movie();
  Movie(char*, int, int, char*, int);
  ~Movie();
  char* getDirector();
  int getDuration();
  int getRating();
 private:
  char* director;
  int duration;
  int rating;
};
