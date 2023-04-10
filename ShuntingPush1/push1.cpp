//Akash Pai
//3/15/2023
//Shunting Yard - Sorts math equations into different notations
//Received help on developing the stack and heap from zayeed saffat

#include <iostream>
#include <cstring>

using namespace std;

struct Node{
  char value;
  Node* next;
  Node;
}

class Tree {
public:
Tree* left;
Tree* right;
Tree* more;
char data;
	Tree(char data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL:
	}
};

class Stack {
Node* head = NULL;
public:
	//insert pop
	//insert peek
	//insert push
	//check if list is empty to avoid accessing unallocated memory
}

class BtreeS {

}

class Q {

}

int oop(); //make order of operations;
Queue* postfixDevelopment(input) //make postfix work, enter into queues, stacks, make oop precedence work
Tree* makeTree([]);

void postfix();
void prefix();
void infix();

int main(){ //main function
	while(true){
		cout << "Input equation in infix form: ";
		char input[256]; //input
		cin >> input;

		Tree* temporary = maketree(input); //make tree
		int count = 0;
		while(count != 1){ //print one time all forms
			cout << "Infix Form" << endl;
			infix(temporary);
			cout << endl;
			cout << "Postfix Form" << endl;
			postfix(temporary);
			cout << endl;
			cout << "Prefix Form" << endl;
			prefix(temporary);
			cout << endl;
			count = count+1;
		}

	}

}