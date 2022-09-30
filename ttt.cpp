#include <iostream>
#include <cstring>

//Akash Pai
//9/30/22
//This program is a 2 player tictactoe

using namespace std;

//methods
void clearBoard(int board[][3]);
void printBoard(int board[][3]);
bool checkWin(int board[][3], int player);
bool checkTie(int board[][3]);

int main () {
//variables
  int board[3][3];
  char rowcol[80];
  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  int X_TURN = 0;
  int O_TURN = 1;
  int turn = X_TURN;
  int X_WINS = 0;
  int O_WINS = 0;

  bool playing = true;
  bool notFilled = true;
  clearBoard(board);
  
  while(playing == true) {
    while (checkWin(board, 1) == false && checkWin(board, 2) == false && checkTie(board) == false) {
      printBoard(board);
      //get input
      cin.get(rowcol, 81);
      cin.get();
      int length = strlen(rowcol);
      rowcol[length] = '\0';
 
      if (strlen(rowcol) != 2) {
        rowcol[0] = 0;
        cout << "Re-enter a letter followed by a number (row/col)" << endl;
      }
      else if (rowcol[0] != 'a' && rowcol[0] != 'b' && rowcol[0] != 'c') {
        rowcol[0] = 0;
        cout << "Row must be an a, b, or c" << endl;
      }
      else if (rowcol[1] != '1' && rowcol[1] != '2' && rowcol[1] != '3') {
        rowcol[0] = 0;
        cout << "Column must be a 1, 2, or 3" << endl;
      }
      else {
        int row = -1;
        int col = -1;
        if (rowcol[0] == 'a') {
          row = 0;
        }
        else if (rowcol[0] == 'b') {
          row = 1;
        }
        else {
          row = 2;
        }
        if (rowcol[1] == '1') {
          col = 0;
        }
        else if (rowcol[1] == '2') {
          col = 1;
        }
        else {
          col = 2;
        }
       //put piece 
       if (board[row][col] == 0) {
          if (turn == X_TURN) {
            board[row][col] = 1;
            turn = O_TURN;
          }
          else {
            board[row][col] = 2;
            turn = X_TURN;
          }
        }
        else {
          cout << "There is a piece there" << endl;
        }
      }
      
    }
    //if win/tie, print out some stuff
    if (checkWin(board, 1) == true && checkTie(board) == false) {
      cout << "X Wins!" << endl;
      ++X_WINS;
      turn = X_TURN;
      cout << "Times X has won: " << X_WINS << ". Times O has won: " << O_WINS << endl;
    }
    else if (checkWin(board, 2) == true && checkTie(board) == false) {
      cout << "O Wins!" << endl;
      ++O_WINS;
      cout << "Times X has won: " << X_WINS << ". Times O has won: " << O_WINS << endl;
    }
    else if (checkTie(board) == true) {
      cout << "It was a tie!" << endl;
      cout << "Times X has won: " << X_WINS << ". Times O has won: " << O_WINS << endl;
    }
    char again[2];
    cout << "Woudl you like to play again(enter y/n)?" << endl;
    cin.get(again, 2);
    cin.get();
    again[1] = '\0';
    if (again[0] == 'y') {
      cout << "A new board has been generated." << endl;
      again[0] = 0;
      clearBoard(board);
      playing = true;
    }
    else {
      playing = false;
    }
  }
  cout << "Thanks for playing!" << endl;
}
//clear board method
void clearBoard(int board[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = 0;
    }
  }
}
//printboard method
void printBoard(int board[][3]) {
  cout << " \t1\t2\t3" << endl;
  int count = 0;
  char temp[80];
  for(int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (row == 0 && column == 0) {
	temp[count] = 'a';
	temp[count+1] = '\t';
	count = count+2;
      }
      else if(row == 1 && column == 0) {
	temp[count] = 'b';
	temp[count+1] = '\t';
	count = count+2;
      }
      else if(row == 2 && column == 0) {
	temp[count] = 'c';
	temp[count+1] = '\t';
	count = count+2;
      }
      
      if (board[row][column] == 0) {
	temp[count] = '\t';
	count = count+1;
      }
      else if(board[row][column] == 1) {
	temp[count] = 'X';
	temp[count+1] = '\t';
	count = count+2;
      }
      else if(board[row][column] == 2) {
	temp[count] = 'O';
	temp[count+1] = '\t';
	count = count+2;
      }
      if (column == 2 && row != 2) {
	temp[count] = '\n';
	count++;
      }
    } 
  }
  temp[count] = '\0';
  cout << temp << endl;
}
//checkwin method
bool checkWin(int board[][3], int player) {
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
    return true;
  }
  return false;
}
//checktie method
bool checkTie(int board[][3]) {
  int numFilled = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != 0) {
	numFilled++;
      }
      if (numFilled == 9 && checkWin(board, 1) == false && checkWin(board, 2) == false) {
	return true;
      }
    }
  }
  return false;
}
  
