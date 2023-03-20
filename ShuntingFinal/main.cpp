//Akash Pai
//3/15/2023
//Shunting Yard - Sorts math equations into different notations
//Received help on developing the stack and heap from zayeed saffat

#include <iostream>
#include <cstring>

using namespace std;

typedef struct Node{ //essentially a linked list but does stack and queue stuff too.
  char value;
  Node* next;
} Node;

class Tree{ // Tree filled with chars from
public:
Tree* left;
Tree* right;
Tree* more;
char data;
	Tree(char data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

};

class Stack{
Node* head = NULL;
public:

	void pop(){ // deletion
		this->head = head->next;
	}

	char peek(){ // printing
		return head->value;
	}

	void push(char c){ // adding
		Node* n = new Node();
		n->value = c;
		n->next = head;
		this->head = n;
	}
	bool empty(){ // empty check
		return head == NULL;
	}
};


class BinaryTreeStack{ // holds nodes but a stack of binary tree ones
Tree* head = NULL;
public:
	void pop(){
		if(head == NULL){
			
		}
		else{
			this->head = head->more;
		}
	}

	Tree* peek(){ // peeks, essentially same as stack
		return head;
	}

	void push(Tree* in){ // pushes, essentially same as stack
		in->more = head;
		this->head = in;
	}
	bool empty(){ // checks if empty
		return head == NULL;
	}
};



class Queue{ // essentially operates like a stack but in a first in first out method kinda like a movie theater
Node* head = NULL;
public:
	void enterqueue(char c){ // adds

		Node* n = new Node();
		n->value = c;
		n->next = NULL;

		if(this->head == NULL){
			this->head = n;
			return;
		}

		Node* atp = this->head;
		while(atp->next != NULL){
			atp = atp->next;

		}
		atp->next = n;
	}

	char deletequeue(){ // deletes from queue as name implies
		char c = head->value;
		head = head->next;
		return c;
	}

	bool empty(){ //again checks if empty
		return head == NULL;
	}

};


int orderofop(char c){ //decides which operators go first using order of operations (PEMDAS)
  if(c == '+' || c == '-') {
    return 1;
  }
  else if(c == '*' || c == '/') {
    return 2;
  }
  else if(c == '^') {
    return 3;
  }
  else {
    return 0;
  }
}



Queue* postfixDev(char* input){ // infix -> postfix
	Queue* queue = new Queue(); // this is where the output queue is initialized
	Stack* stack = new Stack(); // this is where the output stack is initialized

	for(int i = 0; i < strlen(input); i++){ // uses a for loop to iterate over the characters in an input
		char tempC = input[i];
		if(tempC == ' '){
			continue; //saw this in a utube video interesting
		}
		if(isdigit(tempC)){ // add to que
			queue->enterqueue(tempC);
		}
		else if(tempC == '+' || tempC == '-' || tempC == '/' || tempC == '*' || tempC == '^'){ // add to stack
			char o1 = tempC;
			while(true){
				if(stack->empty()){
					break;
				}
				char o2 = stack->peek();
				if(o2 == '+' || o2 == '-' || o2 == '/' || o2 == '*' || o2 == '^' || o2 == ')'){
					if(orderofop(o2) > orderofop(o1)){ // checks for operator precedence using PEMDAS function defined above

					}
					else if(orderofop(o2) == orderofop(o1) && o1 != '^'){ // operators are the same as defined by PEMDAS function

					}
					else{
						// dont add from stack to que
						break;
					}
					queue->enterqueue(stack->peek());
					stack->pop();
				}
				else{
					break;
				}
			}
			stack->push(o1); //add
		}
		else if(tempC == '('){ // add LEFT PARENTHESES ONLY
			stack->push('(');
		}
		else if(tempC == ')'){
			while(stack->peek() != '('){
				queue->enterqueue(stack->peek());
				stack->pop();
			}
			stack->pop();
		}
	}
	while(!stack->empty()){
		queue->enterqueue(stack->peek());
		stack->pop();
	}
	return queue;
}


Tree* maketree(char* infix){
	Queue* quehead = postfixDev(infix);
	


	BinaryTreeStack* stack = new BinaryTreeStack();

	Tree* head = new Tree(' ');
	while(!quehead->empty()){
		char data = quehead->deletequeue();	
		Tree* t = new Tree(data);
		if(orderofop(data) == 0){ //chekcs for operator
			stack->push(t);
		}
		else{

			t->right = stack->peek();
			stack->pop();

			t->left = stack->peek();
			stack->pop();

			stack->push(t);

			head = t;
		}
	}

	if(!stack->empty()){
	}

	return head;
}


void postfix(Tree* tree){//postfix esentially print at the end (notice location of cout in comparison to others)
	if(tree->left != NULL){
		postfix(tree->left);
	}
	if(tree->right != NULL){
		postfix(tree->right);
	}
	cout << tree->data;
}

void prefix(Tree* tree){//prefix essentialy print at the beginning (notice location of cout in comparison to others)
	cout << tree->data;
	if(tree->left != NULL){
		prefix(tree->left);
	}
	if(tree->right != NULL){
		prefix(tree->right);
	}
}

void infix(Tree* tree){//infix essentially print in middle (notice location of cout in comparison to others)
	if(tree->right != NULL){
		infix(tree->right);
	}

	cout << tree->data;

	if(tree->left != NULL){
		infix(tree->left);
	}
	
}

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
