/*Akash Pai
  4/5/2023
  This project cretes a binary tree which sorts numbers, held by nodes. Nodes can be inputted by file or by console. The tree can be displayed. Nodes can be removed, or searched for.
  NOTE: received help on the displaying of the tree and file input from Nikhil Nayak.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "node.h"

using namespace std;

//function prototypes
void add(Node*& head, Node* current, int num);
void display(Node* current, int depth);
Node* remove(Node* current, int value);
bool search(Node* head, int value);

int main() {
    Node* head = NULL;
    bool playing = true;
    while (playing == true) {
        cout << "Would you like to enter numbers by console (Enter: CONSOLE), by file (Enter: FILE), display the tree(Enter: DISPLAY), delete a node(Enter: DELETE), search for a node(Enter: SEARCH), or quit(Enter: QUIT)?" << endl;
        char input[100];
        cin >> input;

        if (strcmp(input, "FILE") == 0) { //add by file
            cout << "How many integers you would like to add?:" << endl;
            int n;
	    cin >> n;
            fstream fin;
            fin.open("numbers.txt"); // open file (numbers used by me are in my github: 418430 is the username
            int value;
	    
            for (int i = 0; i < n; i++) { //iterates through integers in file (specified by user)
                fin >> value;
                add(head, head, value);
            }
            fin.close(); //close file
        }

        if (strcmp(input, "CONSOLE") == 0) { //add by input (console / manual enter)
            cout << "How many integers would you like to add?:" << endl;
            int n;
	    cin >> n;
            cout << "Please enter the integers:" << endl;
            int value;
	    for (int i = 0; i < n; i++) {
                cin >> value;
                add(head, head, value);
            }
        }

	//remind to finish AAV science fair project board and cut wood to hold trifold together
	//TO-DO LIST
	//1. AAV Slides
	//2. Diamond Challenge
	//3. TEAMS
	//4. Finish add function, and test cases for delete
	//5. Calc Midterm, Chem Test Study
	
	//if (strcpt(input, "SEARCH") == 0) {
	//cout "enter:" << endl;
	// int value;
	//cin >> value;
	//  if (search(head, value) == true) {
	//    cout << "Present integer" << endl;
	//  }
	//  else {
	//    //not there
	//  }
	//}

        if (strcmp(input, "SEARCH") == 0) { //search
            cout << "Enter an integer:" << endl;
            int value;
	    cin >> value; 
            if (search(head, value) == true) { //value is there
                cout << "The integer is present." << endl;
            }           
            else { //integer not there
                cout << "The intereger is not there." << endl;
            }
        }

        if (strcmp(input, "QUIT") == 0) { //quit
            playing = false;
        }

	if (strcmp(input, "DISPLAY") == 0) { //display tree
	  display(head, 0);
	}

	if (strcmp(input, "DELETE") == 0) { //delete node, based on numerical value which user inputs
	  cout << "Enter an integer you would like to delete:" << endl;
	  int value;
	  cin >> value;
	  head = remove(head, value);
	}

    }
}

void add(Node*& head, Node* current, int value) { //add function
    if (head == NULL) { //Empty tree case - trivial, add a head node w/ specified value.
        head = new Node(value);
    }

    else if (value < current->getValue()) { //if value is less than current's value
        if (current->getLeft() == NULL) { //add value to tree in corerect place
            current->setLeft(new Node(value));
        }
        else { //go left
            add(head, current->getLeft(), value);
        }
    }

    else if (value > current->getValue()) { //if value is greater than current's value
        if (current->getRight() == NULL) { //add value to tree
            current->setRight(new Node(value));
        }
        else { //go right in this case
            add(head, current->getRight(), value);
        }
    }
}

void display(Node* current, int depth) { //function that displays tree
    if (current == NULL) { //if tree is empty and head is NULL exit function (test case)
        return;
    }

    if (current->getRight() != NULL) {
        display(current->getRight(), depth+1); //recursive call, increment both by 1
    }

    for (int i = 0; i < depth; i++) { //tabs by depth
        cout << "\t";
    }
    cout << current->getValue() << endl; //print current value

    if (current->getLeft() != NULL) {
        display(current->getLeft(), depth+1); //recursive call
    }
}

bool search(Node* head, int value) { //Searches for the Value in the Tree
    Node* curr = head;
    while (curr != NULL) {
        if (value < curr->getValue()) { //if value is less than current go left
            curr = curr->getLeft();
        }
        else if (value > curr->getValue()) { //if value is greater than current go right
            curr = curr->getRight();
        }
        else if (value == curr->getValue()) { //value is found and true is returned
            return true;
        }
    }
    return false; //if NULL node is reached without finding the value then we know it doesn't exist in the tree
}


Node* remove(Node* current, int value) { //Deletion of Node from Tree
    if (current == NULL) { //Test Cases for Deletion (Empty Tree)
        cout << "The tree is empty." << endl;
        return current; //could also return NULL i suppose, or a current node with data value of 0, something like that
    } 

    else if (value < current->getValue()) { //if value is less than current go left
        current->setLeft(remove(current->getLeft(), value));
    } 

    else if (value > current->getValue()) { //if value is greater than current go right
        current->setRight(remove(current->getRight(), value));
    } 

    else { //found value (finally)
        if (current->getLeft() == NULL && current->getRight() == NULL) { //check if the given node has children
            return NULL;
        } 
        else if (current->getLeft() == NULL) { //check if given node has no left child
            Node* temp = current->getRight();
            delete current;
            return temp;
        } 
        else if (current->getRight() == NULL) { //check if given node has no right child
            Node* temp = current->getLeft();
            delete current;
            return temp;
        }

        //search and find the smallest node that is still larger than current (will need to update current later w/ that)
        Node* temp = current->getRight();
        while (temp != NULL && temp->getLeft() != NULL) {
            temp = temp->getLeft();
        }
        current->setValue(temp->getValue()); //update current (done here)
        current->setRight(remove(current->getRight(), temp->getValue())); //recursive call
    }

    return current;
}

