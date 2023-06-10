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
  int ajMatrix[100][100]; //intiialize adjacency matrix
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      ajMatrix[i][j] = 0; //fill it with zeros as starting values -> to be replaced by 1s / weights later on
    }
  }
  //the concepts in the following four lines of code were provided to me by Nikhil - he helped out some on it
  map <char, int> indexes; //holds lookupable index to name correlation for matrix
  char names[20];
  set<int> deleted; //indexes of deleted vertuces
  int size = 0; //total dynamic size of adjacency matrix

  bool playing = true;
  while (playing == true) {
    char input [100];
    cout << "Add Vertex (AV), Remove Vertex (RV), Add Edge (AE), Remove Edge (RE), Shortest Path (SP), Print Matrix (PRINT) or Quit (QUIT)" << endl;
    cin >> input;
    if (strcmp(input, "PATH") == 0) {
      //psuedocode:
      //for each vertex A in B
      //distance is inf
      //prev is NULL
      //some sort of queue implementation if A != B
      //... not sure how to implement rest, will have to spend more time learning.
    }
    
    if (strcmp(input, "QUIT") == 0) {
      playing = false;
    }
    if (strcmp(input, "AV") == 0) {//Add vertex
      char ch; //input variable
      size = size+1; //adjjacency matrix is one more full ->one more vertex
      cout << "Enter a single character that represents the name of the vertex you would like to add" << endl;
      cin >> ch;
      indexes[ch] = size-1; //index
      names[size-1] = ch; //name
    }
    
    if (strcmp(input, "AE") == 0) { //add edge
      cout << "Enter the two vertices and the weight seperated by spaces:" << endl;
      char chA;
      char chB;
      cin >> chA >> chB;
      int n;
      cin >> n;
      
      ajMatrix[indexes[chA]][indexes[chB]] = n; //adds the edge, and the edges wait to the adewquate corresponding section in the AJM
    }

    if (strcmp(input, "RV") == 0) {
      cout << "Enter the name of the vertex you would like to delete (Must be a Character)" << endl;
      char ch; //input var
      cin >> ch;
      if (indexes.count(ch) == 1) { //check vertex exists
        deleted.insert(indexes[ch]); //add vIndex to deleted list
        names[indexes[ch]] = ' '; //in the names array, replace the letter with a space to indicate an empty spot
        indexes.erase(ch); //map delete function (removes index:name correlaiton as it does not exist anymore)
      }
    }

    if (strcmp(input, "RE") == 0) {
      cout << "Enter the two vertices seperated by a space (effectively removes an edge):" << endl;
      char chA; //vertice 1
      char chB; //vertice 2 - weight in between these two vertices is made 0
      cin >> chA >> chB;

      if (indexes.count(chB) == 1 && indexes.count(chA) == 1) { //check both vertices exist
        ajMatrix[indexes[chA]][indexes[chB]] = 0; //make the weight between these vertices 0 (no edge)
      }
      else {
        cout << "One of the inputted vertices is non-existent." << endl;
      }
    }
    

    if (strcmp(input, "PRINT") == 0) { //print matrix
      cout << "\t";
      for (int i = 0; i < size; i++) {
        if (names[i] != ' ') {
          cout << names[i] << "\t";
        }
      }
      cout << endl;
      
      for (int i = 0; i < size; i++) {
        if (deleted.count(i) != 1) {
          cout << names[i] << "\t";
          for (int j = 0; j < size; j++) {
            if (deleted.count(j) != 1) {
              cout << ajMatrix[i][j] << "\t";
            }
          }
          cout << endl;
        }
      }
    }  
  }
}
