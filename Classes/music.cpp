//Akash Pai
//11/4/22
//CPP for music. Defines constructor, destructor, and gets fields like publisher, artist, etc.
#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

Music::Music() {
  publisher = new char[80];
  artist = new char[80];
  duration = 0;
}

Music::Music(char* newpublisher, char* newartist, int temp, char* newtitle, int newyear) {
  publisher = new char[80];
  title = new char[80];
  strcpy(publisher, newpublisher);
  strcpy(title, newtitle);
  artist = new char[80];
  strcpy(artist, newartist);
  duration = temp;
  year = newyear;
}

Music::~Music() {
  delete[] publisher;
  delete[] title;
  delete[] artist;
}

char* Music::getPublisher() {
  return publisher;
}

char* Music::getArtist() {
  return artist;
}

int Music::getDuration() {
  return duration;
}
