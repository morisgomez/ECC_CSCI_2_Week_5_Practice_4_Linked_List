/*
 Program Name: main.cpp
 Programmer: Moris Gomez
 Date: Saturday 03/14/2024
 Version Control: 1.0
 About: Week 5, CSCI 2, More Practice.
 Description:
   Create a simple Linked List for practice and 1) add a Node to the front and 2) display said Linked List.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next; //contains address.
public:
    //default constructor:
    Node()
    {
        data = 0;
        next = NULL;
    }
    
    //constructor w/ 1 argument:
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};//end Node class.


//function to display linked list:
void display(Node *current)
{
    int counter = 1; //tracks each Node passed in current.
    while(current != NULL)
    {
        cout << "this is Node " << counter << " with address of: " << current << endl;
        cout << "it has a data value of: " << current->data << endl;
        cout << "it points to next address of: " << current->next << endl;
        cout << "----------------" << endl;
        current = current->next; //current is Node #2 via 'next' attribute.
        counter = counter + 1;
    } //end while loop.
} //end display function.

//function to add Node at front of linked list:
void addNodeFront(Node *&temp, int num) //takes in num of data for new Node.
{
    Node *n; //create empty pointer.
    n = new Node(num); //create new Node w/ num data & make n point to its address.
    
    //n Node has to point to header Node via next.
    n->next = temp; // n pointing to temp which is address of passed pointer (head in this case)
    
    //header now becomes n and original header is Node #2
    temp = n;
    
} //end addNodeFront function.

int main()
{
//STEP 1) Create empty pointers:
    Node *head; //pointer for Node #1.
    Node *second; //pointer for Node #2.
    Node *third; //pointer for Node #3.
    Node *tail; //pointer for Node #4.

//STEP 2) Create Nodes for each pointer above using 1 argu. constructor:
    head = new Node(2); //head has address of Node #1.
    second = new Node(4); //second has address of Node #2.
    third = new Node(6); //third has address of Node #3.
    tail = new Node(8); //tail has address of Node #4.
    
//STEP 3) link the Nodes:
    head->next = second; //'next' value of Node #1 is address Node #2.
    second->next = third; //'next' value of Node #2 is address Node #3.
    third->next = tail; //'next' value of Node #3 is address Node #4.
    tail->next = NULL; //'next' value of Node #4 NULL.

//STEP 4) print linked list w/ while loop:
    //call display function w/ 'head' Node as argument:
    display(head);

//STEP 5) add a new Node to front of Linked List:
    addNodeFront(head, -1); //passing Node pointer as reference to see changes outside function
    cout << endl << endl << "below we added a new node to very front of the linked list, w/ value -1. previous head becomes second." << endl << endl;
    display(head); //
    
    return 0;
}










//NOTE: professor's example makes it more complicated than needed to be. he combines steps 3 and 4 which makes it confusing.
//step 1: create empty pointers.
//step 2: create Nodes
//step 3: assign nodes to corresponding pointers
//step 4: link all noes
//step 5: print

