//Akash Pai
//11/4/22
//Main file, creates vectors that stores various fields. Has add, search, delete methods. can quit when done.
#include <iostream>
#include <cstring>
#include "videogames.h"
#include "music.h"
#include "movies.h"
#include <vector>

using namespace std;

const int SIZE = 2;
//methods
void search(vector<Game*> &, vector<Music*> &, vector<Movie*> &);
void add(vector<Game*> &, vector<Music*> &, vector<Movie*> &);
void remove(vector<Game*> &, vector<Music*> &, vector<Movie*> &);

int main() {
  //vectors for storing
  vector<Game*> vect;
  vector<Music*> vect2;
  vector<Movie*> vect3;
  int temp = -1;
  char move[20];
  while (temp == -1) {
    //checking what function they'd like to use
    cout << "Would you like to add, delete, search or quit? (Enter QUIT, ADD, SEARCH, or DELETE)" << endl;
    cin.get(move, 21);
    cin.get();
    move[strlen(move)] = '\0';
    if(strcmp(move, "QUIT") == 0) {
      temp = 0;
      move[0] = 0;
    }
    else if(strcmp(move, "ADD") == 0) {
      add(vect, vect2, vect3);
      move[0] = 0;
    }
    else if(strcmp(move, "SEARCH") == 0) {
      search(vect, vect2, vect3);
      move[0] = 0;
    }
    else if(strcmp(move, "DELETE") == 0) {
      remove(vect, vect2, vect3);
      move[0] = 0;
    }
    else {
      cout << "Incorrect input. Re-enter." << endl;
      move[0] = 0;
    }
      
  }
  cout << "Thank you." << endl;
}

void search(vector<Game*> &newvect, vector<Music*> &newvect2, vector<Movie*> &newvect3) {
  char type[20];
  type[0]= 0;
  cout << "Would you like to search by year or title (ENTER Y/T)" << endl;
  cin.get(type, 2);
  cin.get();
  type[strlen(type)] = '\0';
  if (strcmp(type, "Y") == 0) {
    //search by year
    char nums[20];
    nums[0] = 0;
    cout << "Enter a year (4 digits or less)" << endl;
    cin.get(nums, 5);
    cin.get();
    int i = 0;
    int number  = 0;
    while (nums[i] != 0) {
      number = (nums[i] - '0') + (number*10);
      i++;
    }
    //iterate throgh items in vector that match the year
    for(vector<Game*>::iterator it = newvect.begin(); it != newvect.end(); it++) {
      if (number == (*it)->getYear()) {
       cout << "Videogame - Title: " << (*it)->getTitle() << ", Publisher: " << (*it)->getPublisher() << ", Rating: " << (*it)->getRating() << ", Year: " << (*it)->getYear() << endl;
      }
    }
    for(vector<Music*>::iterator it = newvect2.begin(); it != newvect2.end(); it++) {
      if (number == (*it)->getYear()) {
	cout << "Music - Title: " << (*it)->getTitle() << ", Publisher: " << (*it)->getPublisher() << ", Artist: " << (*it)->getArtist() << ", Duration: " << (*it)->getDuration() << ", Year: " << (*it)->getYear() << endl;
      }
    }
    for(vector<Movie*>::iterator it = newvect3.begin(); it != newvect3.end(); it++) {
      if (number == (*it)->getYear()) {
	cout << "Movie - Title: " << (*it)->getTitle() << ", Director: " << (*it)->getDirector() << ", Duration: " << (*it)->getDuration() << ", Rating: " << (*it)->getRating() << ", Year: " << (*it)->getYear() << endl;
      }
    }
  }
  else if(strcmp(type, "T") == 0) {
    //seaerch by title
    char titles[80];
    titles[0] = 0;
    cout << "Enter a title" << endl;
    cin.get(titles, 81);
    cin.get();
    titles[strlen(titles)] = '\0';
    //iterate through vector. print out items that match inputted title
    for(vector<Game*>::iterator it = newvect.begin(); it != newvect.end(); it++) {
      if (strcmp(titles, (*it)->getTitle()) == 0) {
       cout << "Videogame - Title: " << (*it)->getTitle() << ", Publisher: " << (*it)->getPublisher() << ", Rating: " << (*it)->getRating() << ", Year: " << (*it)->getYear() << endl;
      }
    }
    for(vector<Music*>::iterator it = newvect2.begin(); it != newvect2.end(); it++) {
      if (strcmp(titles, (*it)->getTitle()) == 0) {
        cout << "Music - Title: " << (*it)->getTitle() << ", Publisher: " << (*it)->getPublisher() << ", Artist: " << (*it)->getArtist() << ", Duration: " << (*it)->getDuration() << ", Year: " <<(*it)->getYear() << endl;
      }
    }
    for(vector<Movie*>::iterator it = newvect3.begin(); it != newvect3.end(); it++) {
      if (strcmp(titles, (*it)->getTitle()) == 0) {
        cout << "Movie - Title: " << (*it)->getTitle() << ", Director: " << (*it)->getDirector() << ", Duration: " << (*it)->getDuration() << ", Rating: " << (*it)->getRating() << ", Year: " << (*it)->getYear() << endl;
      }
    }
  }
  else {
    cout << "Incorrect input. Re-enter." << endl;
  }
 }

void add(vector<Game*> &newvect, vector<Music*> &newvect2, vector<Movie*> &newvect3) {
  char type[80];
  cout << "Would you like to add a song, videogame, or movie (Enter SONG, GAME OR MOVIE)." << endl;
  //what type of thing they'd like to add
  cin.get(type, 81);
  cin.get();
  if (strcmp(type, "SONG") == 0) {
    char* publisher = new char[80];
    publisher[0] = 0;
    char* artist = new char[80];
    artist[0] = 0;
    char* title = new char[80];
    title[0] = 0;
    char durationA[20];
    durationA[0] = 0;
    char yearA[20];
    yearA[0] = 0;
    cout << "Enter a title" << endl;
    cin.get(title, 81);
    cin.get();
    cout << "Enter a publisher" << endl;
    cin.get(publisher, 81);
    cin.get();
    cout << "Enter an artist" << endl;
    cin.get(artist, 81);
    cin.get();
    cout << "Enter a duration (in minutes)" << endl;
    cin.get(durationA, 3);
    cin.get();
    cout << "Enter a year of make" << endl;
    cin.get(yearA, 21);
    cin.get();
    int number  = 0;
    int i = 0;
    while (durationA[i] != 0) {
      number = (durationA[i] - '0') + (number*10);
      i++;
    }
    int year = 0;
    int j = 0;
    while (yearA[j] != 0) {
      year = (yearA[j] - '0') + (year*10);
      j++;
    }
    //creates new object, pushes back to vector
    newvect2.push_back(new Music(publisher, artist, number, title, year));

  }
  else if (strcmp(type, "GAME") == 0) {
    //add videogame
    type[0] = 0;
    char* publisher = new char[80];
    publisher[0] = 0;
    char* title = new char[80];
    title[0] = 0;
    char ratingA[20];
    char yearA[20];
    ratingA[0] = 0;
    yearA[0] = 0;
    cout << "Enter a title" << endl;
    cin.get(title, 81);
    cin.get();
    cout << "Enter a publisher" << endl;
    cin.get(publisher, 81);
    cin.get();
    cout << "Enter a rating (1-10)" << endl;
    cin.get(ratingA, 3);
    cin.get();
    cout << "Enter a year of make" << endl;
    cin.get(yearA, 21);
    cin.get();
    int number  = 0;
    int i = 0;
    while (ratingA[i] != 0) {
      number = (ratingA[i] - '0') + (number*10);
      i++;
    }
    int y = 0;
    int j = 0;
    while (yearA[j] != 0) {
      y = (yearA[j] - '0') + (y*10);
      j++;
    }
    //creates object from inputs, pushes it to back of vector
    newvect.push_back(new Game(publisher, number, title, y));
  }
  else if (strcmp(type, "MOVIE") == 0) {
    //add movie
    type[0] = 0;
    char* director = new char[80];
    director[0] = 0;
    char* title = new char[80];
    title[0] = 0;
    char durationA[20];
    durationA[0] = 0;
    char ratingA[20];
    ratingA[0] = 0;
    char yearA[20];
    yearA[0] = 0;
    cout << "Enter a title" << endl;
    cin.get(title, 81);
    cin.get();
    cout << "Enter a director" << endl;
    cin.get(director, 81);
    cin.get();
    cout << "Enter a duration (in minutes)" << endl;
    cin.get(durationA, 21);
    cin.get();
    cout << "Enter a rating (1-10)" << endl;
    cin.get(ratingA, 3);
    cin.get();
    cout << "Enter a year of make" << endl;
    cin.get(yearA, 21);
    cin.get();
    int numberD = 0;
    int numberR = 0;
    int numberY = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    while (ratingA[i] != 0) {
      numberR = (ratingA[i] - '0') + (numberR*10);
      i++;
    }
    while (durationA[j] != 0) {
      numberD = (durationA[j] - '0') + (numberD*10);
      j++;
    }
    while (yearA[k] != 0) {
      numberY = (yearA[k] - '0') + (numberY*10);
      k++;
    }
    //creates new object based on inputted fields, pushes to back of vector
    newvect3.push_back(new Movie(director, numberD, numberR, title, numberY));
  }
  else {
    cout << "Incorrect input. Re-enter." << endl;
    type[0] = 0;
  }
}





void remove(vector<Game*> &newvect, vector<Music*> &newvect2, vector<Movie*> &newvect3) {
  //removes based on entered year/title
  char type[20];
  type[0]= 0;
  cout << "Would you like to delete by year or title (ENTER Y/T)" << endl;
  cin.get(type, 2);
  cin.get();
  type[strlen(type)] = '\0';
  if (strcmp(type, "Y") == 0) {
    char nums[20];
    nums[0] = 0;
    cout << "Enter a year (4 digits or less)" << endl;
    cin.get(nums, 5);
    cin.get();
    int i = 0;
    int number  = 0;
    while (nums[i] != 0) {
      number = (nums[i] - '0') + (number*10);
      i++;
    }
    int countG = 0;
    int countM = 0;
    int countMo = 0;
    //counting elements that match user inputted year
    for(vector<Game*>::iterator it = newvect.begin(); it != newvect.end(); it++) {
      if (number == (*it)->getYear()) {
        countG++;
        cout << "Videogame - Title: " << (*it)->getTitle() << ", Publisher: " << (*it)->getPublisher() << ", Rating: " << (*it)->getRating() << ", Year: " << (*it)->getYear() << endl;
      }
    }
    for(vector<Music*>::iterator it = newvect2.begin(); it != newvect2.end(); it++) {
      if (number == (*it)->getYear()) {
        countM++;
	cout << "Music - Title: " << (*it)->getTitle() << ", Publisher: " << (*it)->getPublisher() << ", Artist: " << (*it)->getArtist() << ", Duration: " << (*it)->getDuration() << ", Year: " << (*it)->getYear() << endl;
      }
    }
    for(vector<Movie*>::iterator it = newvect3.begin(); it != newvect3.end(); it++) {
      if (number == (*it)->getYear()) {
        countMo++;
	cout << "Movie - Title: " << (*it)->getTitle() << ", Director: " << (*it)->getDirector() << ", Duration: " << (*it)->getDuration() << ", Rating: " << (*it)->getRating() << ", Year: " << (*it)->getYear() << endl;
      }
    }
    char del[20];
    del[0] = 0;
    //confirming deletion
    cout << "Would you like to delete the items listed? (enter y/n)" << endl;
    cin.get(del, 21);
    cin.get();
    del[strlen(del)] = '\0';
    if (strcmp(del, "y") == 0) {
      //deletes using destructor for char pointers, normal for primitive types
      for (int i = 0; i < countG; i++) {
        for(vector<Game*>::iterator it = newvect.begin(); it != newvect.end(); it++) {
          if (number == (*it)->getYear()) {
            delete(*it); //calling char ptr
            newvect.erase(it);
            break;
          }
        }
      }
      for (int i = 0; i < countM; i++) {
	for(vector<Music*>::iterator it = newvect2.begin(); it != newvect2.end(); it++) {
	  if (number == (*it)->getYear()) {
	    delete(*it);
	    newvect2.erase(it);
	    break;
	  }
	}
      }
      for (int i = 0; i < countMo; i++) {
	for (vector<Movie*>::iterator it = newvect3.begin(); it != newvect3.end(); it++) {
	  if (number == (*it)->getYear()) {
	    delete(*it);
	    newvect3.erase(it);
	    break;
	  }
	}
      }
    }
  }
  else if(strcmp(type, "T") == 0) {
    //delete by title
    char titles[80];
    titles[0] = 0;
    cout << "Enter a title" << endl;
    cin.get(titles, 81);
    cin.get();
    titles[strlen(titles)] = '\0';
    int countG = 0;
    int countM = 0;
    int countMo = 0;
    //counting items that match inputted title
    for(vector<Game*>::iterator it = newvect.begin(); it != newvect.end(); it++) {
      if (strcmp(titles, (*it)->getTitle()) == 0) {
	countG++;
	cout << "Videogame - Title: " << (*it)->getTitle() << ", Publisher: " << (*it)->getPublisher() << ", Rating: " << (*it)->getRating() << ", Year: " << (*it)->getYear() << endl;
	
      }
    }
    for(vector<Music*>::iterator it = newvect2.begin(); it != newvect2.end(); it++) {
      if (strcmp(titles, (*it)->getTitle()) == 0) {
        countM++;
	cout << "Music - Title: " << (*it)->getTitle() << ", Publisher: " << (*it)->getPublisher() << ", Artist: " << (*it)->getArtist() << ", Duration: " << (*it)->getDuration() << ", Year: " << (*it)->getYear() << endl;
      }
    }
    for(vector<Movie*>::iterator it = newvect3.begin(); it != newvect3.end(); it++) {
      if (strcmp(titles, (*it)->getTitle()) == 0) {
        countMo++;
	cout << "Movie - Title: " << (*it)->getTitle() << ", Director: " << (*it)->getDirector() << ", Duration: " << (*it)->getDuration() << ", Rating: " << (*it)->getRating() << ", Year: " << (*it)->getYear() << endl;
      }
    }
    char del[20];
    del[0] = 0;
    cout << "Would you like to delete the items listed? (enter y/n)" << endl;
    //confirming deletion
    cin.get(del, 21);
    cin.get();
    del[strlen(del)] = '\0';
    if (strcmp(del, "y") == 0) {
      //deleting using destructor for char ptr, deleting vector. No destructor needed for primitive types
      for (int i = 0; i < countG; i++) {
        for(vector<Game*>::iterator it = newvect.begin(); it != newvect.end(); it++) {
          if (strcmp(titles, (*it)->getTitle()) == 0) {
            delete(*it);  //calling destructor
            newvect.erase(it);
            break;
          }
        }
      }
      for (int i = 0; i < countM; i++) {
        for(vector<Music*>::iterator it = newvect2.begin(); it != newvect2.end(); it++) {
          if (strcmp(titles, (*it)->getTitle()) == 0) {
            delete(*it);
            newvect2.erase(it);
            break;
          }
        }
      }
      for (int i = 0; i < countMo; i++) {
        for (vector<Movie*>::iterator it = newvect3.begin(); it != newvect3.end(); it++) {
          if (strcmp(titles, (*it)->getTitle()) == 0) {
            delete(*it);
            newvect3.erase(it);
            break;
          }
        }
      }
    }

  }
 else {
    cout << "Incorrect input. Re-enter." << endl;
  }
}

