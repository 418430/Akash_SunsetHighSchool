//Akash Pai
//Friday May 19, 2023
//This project is Red-Black-Tree Deletion RBT Part 2 . Numbers are read in from file only, this time, not from command line, and are sorted in a binary tree that happens to be balanced. Additionally, in this part of the project, nodes cna be deleted
//Each node has a color: obviously red or black. Nodes also have two children. Parents can be referenced, though.
//Credits to Nikhil Nayak and Wongspatt (Uno) for some help throughout the project, especially with the rotate method and the display to terminal.
//This is the final push of this project. Comments have been added, the remove function was finished, as was the case checking functions.

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
Node* sibling(Node* current);
Node* findHeir(Node* current);
void remove(Node* root, Node* v);
void checkCaseTwoBlack(Node* root, Node* v);

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
                cout << "Integer is in the tree!" << endl;
            }           
            else { //value not found in tree
                cout << "Integer is not in the tree!" << endl;
            }
        }

        if (strcmp(input, "REMOVE") == 0) { //deletion
            cout << "Enter an integer to remove:" << endl;
            int value; cin >> value;

            if (search(root, value) != NULL) {
                remove(root, search(root, value));
                while (root->getParent() != NULL) { //reset root
                    root = root->getParent();
                }
            }
            else {
                cout << "Integer is not in the tree!" << endl;
            }
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

Node* search(Node* root, int value) { //function that searches for a value in the tree
    Node* current = root;
    while (current != NULL) {
        if (value < current->getValue()) { //if value is less than current go left
            current = current->getLeft();
        }
        else if (value > current->getValue()) { //if value is greater than current go right
            current = current->getRight();
        }
        else if (value == current->getValue()) { //value is found and true is returned
            return current;
        }
    }
    return NULL; //if NULL node is reached without finding the value then we know it doesn't exist in the tree
}

Node* sibling(Node* current) {
    if (current == current->getParent()->getLeft()) {
        return current->getParent()->getRight();
    }
    else {
        return current->getParent()->getLeft();
    }
}

Node* findHeir(Node* current) {
    current = current->getRight();
    while(current->getLeft() != NULL) {
        current = current->getLeft();
    }

    return current;
}

void remove(Node* root, Node* v) { //watch out for issues with root
    Node* u;

	//i was doing integration by parts with u's and v's, did it here. i realize in hindsight, bad move becuase u's and v's look similar...

    if (v->getLeft() != NULL && v->getRight() != NULL)  { //IF V HAS TWO CHILDREN
        u = findHeir(v);

        int temp = v->getValue(); //SWAP V AND U
        v->setValue(u->getValue());
        u->setValue(temp);
        remove(root, u); //recursion (recursive call), but with u
    } 

    else if (v->getLeft() == NULL && v->getRight() == NULL)  { //CASE OF V HAVING NO CHILDREN (v is a leaf)???
        if (v == root) { //v is the only one, easy delete
            root = NULL;
        }
        else { //v is not root
            if (v->getColor() == 0) { //check for if both v and u are black
                //run code for both black
                checkCaseTwoBlack(root, v); //function call see below
            }
            else { //v is red
                if (sibling(v) != NULL) {
                    sibling(v)->setRed();
                }
            }
            if (v == v->getParent()->getLeft()) { //Removal from tree
                v->getParent()->setLeft(NULL);
            }
            else {
                v->getParent()->setRight(NULL);
            }
        }
    } 

    else { //V is not childless, v has one child
        if (v->getLeft() != NULL) { //LEFT
            u = v->getLeft();
        }
        else { //RIGHT CHILD
            u = v->getRight();
        }

        if (v == root) { //V IS ROOT -->received help from uno on this
            v->setValue(u->getValue());
            v->setLeft(NULL); 
            v->setRight(NULL);
        }
        else { 
	  if (v == v->getParent()->getLeft()) { //if none of the above, replace v with u
                v->getParent()->setLeft(u);
            }
            else {
                v->getParent()->setRight(u);
            }
            u->setParent(v->getParent());
            if (u->getColor() == 0 && v->getColor() == 0) {//same thing again both u and v are black
                //run function that checks for double black
                checkCaseTwoBlack(root, u);
            }
            else {
                u->setBlack();
            }
        }
    }
}

void checkCaseTwoBlack(Node* root, Node* v) {
    if (v == root) {//no need, can simply return
        //return;
 	  //do nothing
    }

    else if (sibling(v) == NULL) { //v doesn't have a sibling
        checkCaseTwoBlack(root, v->getParent()); //recursion call
        //checkCaseTwoBlack(root, v);
    }

    else {
        if (sibling(v)->getColor() == 1) { //v has red sibling
            v->getParent()->setRed();
            sibling(v)->setBlack();
            if (sibling(v) == v->getParent()->getLeft()) { //left sibling
                rightRotate(root, v->getParent());
            }
            else { //right sibling
                leftRotate(root, v->getParent());
            }
            checkCaseTwoBlack(root ,v); //recursive call  
        }

        else { //v has black sibling
            if ((sibling(v)->getLeft() != NULL && sibling(v)->getLeft()->getColor() == 1) || (sibling(v)->getLeft() != NULL && sibling(v)->getRight()->getColor() == 1)) { //received help on this code from a friend in college (family friend visited house)
                if (sibling(v)->getLeft() != NULL && sibling(v)->getLeft()->getColor() == 1) { //The left to the sibling is red and is not null (obv)
                    if (sibling(v) == v->getParent()->getLeft()) { //check child -> left child in this case
                        sibling(v)->getLeft()->setColor(sibling(v)->getColor());
                        sibling(v)->setColor(v->getParent()->getColor());
                        rightRotate(root, v->getParent()); //BALANCE
                    } 
                    else { //sibling is all of the above, but right child instead of left
                        sibling(v)->getLeft()->setColor(v->getParent()->getColor());
                        rightRotate(root, sibling(v)); //BALANCE
                        leftRotate(root, v->getParent()); //BALANCE
                    }
                } 
                else { //Right of sibling is red, and sibiling is not null
                    if (sibling(v) == v->getParent()->getLeft()) { ////sibling is left child
                        sibling(v)->getRight()->setColor(v->getParent()->getColor());
                        leftRotate(root, sibling(v)); //balance
                        rightRotate(root, v->getParent()); //balance
                    } 
                    else { //sibling is right child
                        sibling(v)->getRight()->setColor(sibling(v)->getColor());
                        sibling(v)->setColor(v->getParent()->getColor());
                        leftRotate(root, v->getParent());
                    }
                }
                v->getParent()->setBlack();
            } 

            else { //SIBLING TIENE DOS (word for black) NINOS
                sibling(v)->setRed();
                if (v->getParent()->getColor() == 0) {
                    checkCaseTwoBlack(root, v->getParent()); //recursion (mickey mouse)
                }
                else {
                    v->getParent()->setBlack();
                }
            }
        }
    }
}
