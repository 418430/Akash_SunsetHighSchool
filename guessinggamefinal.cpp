#include <iostream>
//Akash Pai
//9/11/2023
//This project is a simple guessing game where the user must guess a randomly generated number
//1. No Global Variables
//2, No strings
//3. Include <iostream> not stdio

using namespace std;

int main() {

  
  bool playing = true;
  while (playing == true) {
    int count = 0;
    char again = 'n';
    int input = -1;
    srand(time(NULL));
    int x = (rand()%100) + 1;
    while ((input != x) && playing == true) {
      cout << "What is your guess?" << endl;
      cin >> input;
      count++;
      if (input > x) {
	cout << "Your guess was too high." << endl;
      }
      else if (input < x) {
	cout << "Your guess was too low." << endl;
      }
      else if (input == x) {
	cout << "Your guess was correct!" << endl;
	cout << "It took you " << count << " guesses" << endl;
	count = 0;
	input = -1;
	break;
      }
    }
    cout << "Would you like to play again (y/n)?" << endl;
    cin >> again;
    if (again == 'y') {
      cout << "Great! The number to be guessed and your total guesses have been reset!" << endl;
    }
    else {
      cout << "Thank you for playing";
      playing = false;
      break;
    }
    
  }
  
 return 0;
}
