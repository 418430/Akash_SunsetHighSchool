//Akash Pai
//9/14/22
//This program determines if an input is a palindrome or not

#include <iostream>
#include <cstring>

using namespace std;

int main() {  
  char str[81];
  char str2[81];
  char temp[81];
  cout << "Enter no more than 80 characters" << endl;
  cin.get(str, 81);
  cin.get();


  int spaces = 0;
  int counttemp = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == ' ' || ispunct(str[i])) {
      spaces++;
    }
  }
  

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != '\0' && str[i] != ' ' && !ispunct(str[i])) {
      temp[counttemp] = tolower(str[i]);
      counttemp++;
    }
  }

  temp[strlen(str) - spaces] = '\0';
  
  
  int count = 0;
  for (int i = strlen(str); i >= 0; i--) {
    if (str[i] != '\0' && str[i] != ' ' && !ispunct(str[i])) {
      str2[count] = tolower(str[i]);
      count++;
    }
  }

  str2[strlen(str) - spaces] = '\0';

  if (strcmp(temp, str2) == 0) {
    cout << "Palindrome" << endl;
  }
  else {
    cout << "Not a Palindrome" << endl;
  }
  
}
