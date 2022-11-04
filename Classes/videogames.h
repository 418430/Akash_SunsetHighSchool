//Akash Pai
//11/4/22
//Header class for videogames file
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Game : public media {
 public:
  Game();
  Game(char*, int, char*, int);
  ~Game();
  char* getPublisher();
  int getRating();
 private:
  char* publisher;
  int rating;
};
