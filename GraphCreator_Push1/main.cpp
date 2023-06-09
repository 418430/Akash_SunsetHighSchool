/*
Akash Pai
6/4/2023
This program utilizes vertices and weighted edges to create a directed graph. An adjacency table is used for the graph (max 20 vertices), and Dijkstra's Algorithm is utilized to find the shortest path.
Received minimal help (lines are cited) from Nikhil Nayak on this.
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int ajMatrix[100][100];
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      ajMatrix[i][j] = 0;
    }
  }
  //the concepts in the following four lines of code were provided to me by Nikhil - he helped out some on it
  map <char, int> indexes;
  char names[20];
  set<int> deleted;
  int size = 0;

  bool playing = true;
  while (playing == true) {
    char input [100];
    cout << "Add Vertex (AV), Remove Vertex (RV), Add Edge (AE), Remove Edge (RE), Shortest Path (SP), Print Matrix (PRINT) or Quit (\
QUIT)" << endl;
    cin >> input;
    if (strcmp(input, "QUIT") == 0) {
      playing = false;
    }
    if (strcmp(input, "AV") == 0) {
      char ch;
      size = size+1;
      cout << "Enter a single character that represents the name of the vertex you would like to add" << endl;
      cin >> ch;
      indexes[ch] = size-1;
      names[size-1] = ch;
    }
    
    if (strcmp(input, "AE") == 0) { //add edge
      cout << "Enter the two vertices and the weight seperated by spaces:" << endl;
      char a, b; cin >> a >> b;
      int n; cin >> n;
      
      ajMatrix[indexes[a]][indexes[b]] = n; //add edge to matrix
    }

    if (strcmp(input, "RV") == 0) {

    }

    if (strcmp(input, "RE") == 0) {
      
    }
    

    if (strcmp(input, "PRINT") == 0) { //print matrix
      cout << "\t";
      for (int i = 0; i < size; i++) { //print labels for ending vertex
        if (names[i] != ' ') {
          cout << names[i] << "\t";
        }
      }
      cout << endl; 
    }  
  }
}
