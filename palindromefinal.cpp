//Akash Pai
//9/14/22
//This program determines if an input is a palindrome or not

#include <iostream>
#include <cstring>

using namespace std;

int main() {  
//creates char array to read in string
  char str[81];
  char str2[81];
  char temp[81];
  cout << "Enter no more than 80 characters" << endl;
  cin.get(str, 81);
  cin.get();

//counts spaces and characters
  int spaces = 0;
  int counttemp = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ' ' || ispunct(str[i])) {
      spaces++;
    }
  }
  
//makes everything lowercase
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != '\0' && str[i] != ' ' && !ispunct(str[i])) {
      temp[counttemp] = tolower(str[i]);
      counttemp++;
    }
  }

  temp[strlen(str) - spaces] = '\0';
  
  //makes everything in this char array lowercase as well
  int count = 0;
  for (int i = strlen(str); i >= 0; i--) {
    if (str[i] != '\0' && str[i] != ' ' && !ispunct(str[i])) {
      str2[count] = tolower(str[i]);
      count++;
    }
  }

  str2[strlen(str) - spaces] = '\0';
//checks if palindrome or not
  if (strcmp(temp, str2) == 0) {
    cout << "Palindrome" << endl;
  }
  else {
    cout << "Not a Palindrome" << endl;
  }
  
}
