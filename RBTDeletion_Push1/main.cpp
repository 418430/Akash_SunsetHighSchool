//Akash Pai
//Wednesday, 5/10/2023
//This project is Red-Black-Tree Deletion. This is push 1. Numbers are read in from file only, this time, not from command line, and are sorted in a binary tree that happens to be balanced.
//Each node has a color: obviously red or black. Nodes also have two children. Parents can be referenced, though.
//Credits to Nikhil Nayak and Wongspatt (Uno) for some help throughout the project, especially with the rotate method and the display to terminal.
//In this push, after psuedocoding and plannign the project, I know I need to have a search function that returns a Node * instead of a bool, as well as changes to Node.h & Node.cpp

#include <iostream>
#include <fstream>
#include <cstring>

#include "node.h"

using namespace std;

//functions

void check(Node * current);

void add(Node*& root, Node* current, int value) { //adds numbers to RBT
    if (root == NULL) { //simple basecase check: root is null
        root = new Node(value);
        check(root);
    }

    else if (value < current->getValue()) { //if input value is less that current one
        if (current->getLeft() == NULL) { //add
            current->setLeft(new Node(value));
            current->getLeft()->setParent(current);
            check(current->getLeft()); //checks for violations. then, update tree.
        }
        else { //go intiial direction (left)
            add(root, current->getLeft(), value);
        }
    }

    else if (value > current->getValue()) { //if input value is greater than current one
        if (current->getRight() == NULL) { //add
            current->setRight(new Node(value));
            current->getRight()->setParent(current);
            check(current->getRight()); //checks for violations. then, update tree. and updates tree
        }
        else { //go other direction (rhgt).
            current->getRight();
            add(root, current->getRight(), value);
        }
    }
}



void leftRotate(Node* root, Node* a);
void rightRotate(Node* root, Node* a);
void display(Node* current, int depth);
Node* search(Node* root, int value);

int main() {
    Node* root = NULL;  

    bool stillPlaying = true;
    while (stillPlaying == true) {
        cout << "Enter the diff moves. Input by File (up to 50 nums) (Enter: FILE), by console (ENTER: CONSOLE), display (Enter: DISPLAY), remove (Enter: REMOVE), search (Enter: SEARCH), or quit(Enter: QUIT)" << endl;
        char input[100];
        cin >> input;

        if (strcmp(input, "FILE") == 0) { //file input
            cout << "Enter how many integers you would like to add. Please note, my current file has 50 integers. Create a new file and add to repo if you want more than 50:" << endl;
            int n; cin >> n;
            fstream fin;
            fin.open("numbers.txt"); //open file named numbers.txt in same directory

            int value;
            for (int i = 0; i < n; i++) { //iterates through specified number of integers by user
                fin >> value;
                
                add(root, root, value);
                while (root->getParent() != NULL) { //reset root
                    root = root->getParent();
                }
            }

            fin.close(); //file reader closed.
        }
	if (strcmp(input, "CONSOLE") == 0) {//console input
	  cout << "How many integers would you like to add?" << endl;
	  int n;
	  cin >> n;
	  cout << "Please enter the integers" << endl;
	  int value;
	  for (int i = 0; i < n; i++) {
	    cin >> value;
	    add(root, root, value);
	    while (root->getParent() != NULL) {//reset root
	      root = root->getParent();
	    }
	  }
	}


        if (strcmp(input, "DISPLAY") == 0) { //display tree
            display(root, 0);
        }

        if (strcmp(input, "SEARCH") == 0) { //search for an integer
            cout << "Enter an integer to search for:" << endl;
            int value; cin >> value; 
            
            if (search(root, value) != NULL) { //value found in tree
                cout << "Integer is in the tree." << endl;
            }           
            else { //cehck base case: integer not found in tree.
                cout << "Integer is not located in the tree. Sorry." << endl;
            }
        }

        if (strcmp(input, "REMOVE") == 0) { //deletion
            cout << "Enter an integer you would like to delete:" << endl;
            int value; cin >> value;

            //RBT Part TWO TO-DO!
	    //also apply for robert e. grant funding
	    //finish infinity ed slides
	    //draft one of paper
	    //harvard zhang lab onboarding
	    //sleep by 10 pm every night
	    //study for calc
        }

        if (strcmp(input, "QUIT") == 0) { //quit
            stillPlaying = false;
        }
    }
}


void check(Node* current) {
    Node* parent = NULL; Node* grandparent = NULL; Node* uncle = NULL;
    if (current->getParent() != NULL) { //intialize parent, grandparent and uncle
        parent = current->getParent();
        if (parent->getParent() != NULL) {
            grandparent = parent->getParent();   
            if (grandparent->getLeft() == parent) {
                uncle = grandparent->getRight();
            }
            else {
                uncle = grandparent->getLeft();
            }
        } 
    }

    if (current->getParent() == NULL) { //add to the root
        current->setBlack(); //root must be of color black - req
    } 

    else if (current->getParent()->getColor() == 0) { //if parent is black
    } 

    else if (uncle != NULL && uncle->getColor() == 1) { //if both parent and unc are red
        current->getParent()->setBlack(); //parent and unc become black
        grandparent->setRed(); //grand = red
        uncle->setBlack(); //unc = black
        check(grandparent); //recursion (yay.)
    } 

    else { //parent is red but uncle is black, or simply doesn't exist.
        if (current == parent->getRight() && parent == grandparent->getLeft()) { //current is larger than parent
            leftRotate(current, parent);
            current = current->getLeft();
        } 
        else if (current == parent->getLeft() && parent == grandparent->getRight()) { //current is smaller than parent
            rightRotate(current, parent);
            current = current->getRight();
        }
        parent = current->getParent(); 
        grandparent = parent->getParent();
        if (current == parent->getLeft()) { //case of current is smaller than parent
            rightRotate(current, grandparent);
        } 
        else { //case of other case: current larger than parent
            leftRotate(current, grandparent);
        }
        parent->setBlack();
        grandparent->setRed();
    }
}

void leftRotate(Node* root, Node* a) { //left rotate para balenciar
    Node* b = a->getRight(); 
    a->setRight(b->getLeft()); 
    if (b->getLeft() != NULL) {
        b->getLeft()->setParent(a);
    }
    b->setParent(a->getParent());

    if (a->getParent() == NULL) {
        root = b;
    } 
    else if (a == a->getParent()->getLeft()) {
        a->getParent()->setLeft(b);
    } 
    else {
        a->getParent()->setRight(b);
    }
    b->setLeft(a);
    a->setParent(b);
}

void rightRotate(Node* root, Node* a) { //right rotate para balenciar
    Node* b = a->getLeft();
    a->setLeft(b->getRight());
    if (b->getRight() != NULL) {
        b->getRight()->setParent(a);
    }
    b->setParent(a->getParent());

    if (a->getParent() == NULL) {
        root = b;
    } 
    else if (a == a->getParent()->getLeft()) {
        a->getParent()->setLeft(b);
    } 
    else {
        a->getParent()->setRight(b);
    }
    b->setRight(a); 
    a->setParent(b);
}

void display(Node* current, int depth) { //DISPALY!
    if (current == NULL) { //emppty tree case
        return;
    }

    if (current->getRight() != NULL) { //right side
        display(current->getRight(), depth+1); //recursion (yay.)
    }

    for (int i = 0; i < depth; i++) { //tabs based on depth. learned how to do this from nikhil in heap, i bielieve it was. continuously used since.
        cout << "\t";
    }

    if (current->getColor() == 0) { //black node.
        cout << "B" << current->getValue() << "|";
    }
    else if (current->getColor() == 1) { //red node
        cout << "R" << current->getValue() << "|";
    }

    if (current->getParent() == NULL) { //check cases
        cout << "NULL" << endl;
    }
    else {
        cout << current->getParent()->getValue() << endl;
    }

    if (current->getLeft() != NULL) { //left side
        display(current->getLeft(), depth+1); //recursion (yay.)
    }
}

Node* search(Node* root, int value) { //search function - finally sum easy to implement do this tmrw
    Node* current = root;
    while (current != NULL) {
        if (value < current->getValue()) { //if input value less than current, go left.
            current = current->getLeft();
        }
        else if (value > current->getValue()) { //if input value is greater than current, go right
            current = current->getRight();
        }
        else if (value == current->getValue()) { //if we found the value (how exciting), return true, else return false.
            return current;
        }
    }
    return NULL; //if we reach the final null node (current == NULL) without returning true, we know we have traversed the whole trree without finding the value. in this case, then, yes, return false as value is not there.
}