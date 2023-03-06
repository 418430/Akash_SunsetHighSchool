//Akash Pai
//3/5/2023
//This is a heap program: it is a max binary tree, which can print its contents, remove the root, repetitively remove its root, and add numbers from console and file
#include <iostream>
#include <iomanip>
#include <cstring>
#include <array>
#include <fstream>
#include <math.h>
using namespace std;

//print
void print(int* &arr, int length, int index, int rows) {
  if (length >= index * 2 + 1 && arr[index*2+1] != 0) {
    print(arr, length, index*2+1, rows+1); //recursive call
  }
  for (int i = 0; i < rows; i++) {
    cout << "\t";
  }
  cout << arr[index] << endl;
  if (index*2 <= length && arr[index*2] != 0) {
    print(arr, length, index*2, rows+1); //recursive call
  }
}
//test for debugging purposes only
void test(int *&arr, int length) {
  for (int i = 1; i < length+1; i++) {
    cout << arr[i] << endl;
  }
}
//sort utilizes bubble sort from "sorting" project in DC Java
void sort(int * &arr, int length) {
  //cout << "SORTING" << endl;
  for(int j = 0; j < length; j++) {
    for (int i = 1; i < length+1; i++) {
      if (arr[i] < arr[i+1]) {
	int temp = arr[i];
	arr[i] = arr[i+1];
	arr[i+1] = temp;
      }
    }
  }
}
//removes largest number, or root
void removeRoot(int *&arr, int &length) {
  cout << arr[1] << " ";
  if (length == 1) {
    cout << endl;
  }
  //removal
  arr[1] = arr[length];
  arr[length] = 0;
  length = length-1;
  sort(arr, length);
}
//removes all roots, one at a time
void removeAll(int* &arr, int length) {
  int x = length;
  for (int i = 0; i < x; i++) {
    removeRoot(arr, length); //keeps calling removeRoot until all are gone
  }
}
//main function
int main() {
  //variables
  char move[20];
  int counter = 0;
  int entering = -1;
  int totalnums = -1;
  bool playing = true;
  //heap
  int* heap = new int[100];
  //intialize all to 0
  for (int i = 0; i < 100; i++) {
    heap[i] = 0;
  }
  while (playing == true) {
    move[0] = 0;
    cout << "Would you like to enter numbers from command line or file? (Enter CMD/FILE), or Remove One Value (RV), or Remove All (RA), or Quit(QUIT)." << endl;
    cin >> move;
    //entering numbers manually
    if (strcmp(move, "CMD") == 0) {
      cout << "How many numbers would you like to enter (Max: 100)" << endl;
      cin >> totalnums;
      for (int i = 1; i < totalnums+1; i++) {
	cout << "Enter your number" << endl;
	cin >> entering;
	heap[i] = entering;
      }
      
      //sorting function call
      sort(heap, totalnums);
      cout << "-------------------------------------------" << endl;
      print(heap, totalnums, 1, 0);
    }
    //entering from file (numbers.txt)
    else if(strcmp(move, "FILE") == 0) {
      fstream fin;
      fin.open("numbers.txt");
      totalnums = 0;
      int num;
      while (fin >> num) {
	heap[counter] = num;
	counter++;
	totalnums++;
      }
      fin.close();
      
      sort(heap, totalnums);
      
      cout << "------------------------------" << endl;
      print(heap, totalnums, 1, 0);
    }
    //remove one value (root)
    else if(strcmp(move, "RV") == 0) {
      removeRoot(heap, totalnums);
      print(heap, totalnums, 1, 0);
    }
    //remove all roots
    else if(strcmp(move, "RA") == 0) {
      removeAll(heap, totalnums);
    }
    else if(strcmp(move, "QUIT") == 0) {
      playing = false;
    }
  }
  
}
