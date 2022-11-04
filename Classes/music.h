//Akash Pai
//11/4/22
//Header class for music
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public media {
 public:
  Music();
  Music(char*, char*, int, char*, int);
  ~Music();
  char* getPublisher();
  char* getArtist();
  int getDuration();
 private:
  char* publisher;
  char* artist;
  int duration;
};
