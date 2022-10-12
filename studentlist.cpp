//Akash Pai
//10/12/22
//This program creates a studentlist where students can be added, deleted. The list can then be printed
#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <cstring>

using namespace std;

//struct where students are held
struct Student {
  char fname[10];
  char lname[10];
  int id;
  float gpa;
};

//print function
void print(vector<Student*> v) {
  for (Student* vtemp: v) {
    cout << vtemp->fname << " " << vtemp->lname << ", " << vtemp->id << ", ";
    cout << setprecision(2) << fixed << vtemp->gpa << endl;
    
  }
}

//deletes students
void remove(vector<Student*> &v) {
  char nums[20];
  nums[0] = 0;
  cout << "Enter a 6-digit ID. Individual with this ID will get deleted from list." << endl;
  cin.get(nums, 7);
  cin.get();
  nums[strlen(nums)] = '\0';
  //converts char array to integer. needed to get id for deletion
  int i = 0;
  int number  = 0;
  while (nums[i] != 0) {
    number = (nums[i] - '0') + (number*10);
    i++;
  }
  
  int count = 0;
  for (Student* vtemp: v) {
    if(vtemp->id == number) {
      v.erase(v.begin()+count);
    }
    count++;
  }
}

//adds students
void add(vector<Student*> &v) {
  Student* s = new Student();
  cout << "Enter a first name." << endl;
  cin >> s->fname;
  cin.ignore(10, '\n');
  cout << "Enter a last name." << endl;
  cin >> s->lname;
  cin.ignore(10, '\n');
  cout << "Enter an ID number." << endl;
  cin >> s->id;
  cin.ignore(10, '\n');
  cout << "Finally, enter a GPA (2 decimal digits maximum)" << endl;
  cin >> s->gpa;
  cin.ignore(10, '\n');
  //cout << s->fname << s->lname << s->id << s->gpa << endl;
  v.push_back(s);
}

int main() {
  //vector with student pointers
  vector<Student*>v;
  int temp = -1;
  char move[20];
  while (temp == -1) {
    cout << "Would you like to quit, add to, delete from, or print the student list? (Enter QUIT, ADD, PRINT, or DELETE)" << endl;
    cin.get(move, 21);
    cin.get();
    move[strlen(move)] = '\0';
    if(strcmp(move, "QUIT") == 0) {
      temp = 0;
      move[0] = 0;
    }
    else if(strcmp(move, "ADD") == 0) {
      add(v);
      move[0] = 0;
    }
    else if(strcmp(move, "PRINT") == 0) {
      print(v);
      move[0] = 0;
    }
    else if(strcmp(move, "DELETE") == 0) {
      remove(v);
      move[0] = 0;
    }
    else {
      cout << "Incorrect input. Re-enter." << endl;
      move[0] = 0;
    }
      
  }
  cout << "Thank you." << endl;
}
