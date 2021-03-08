//Shawn Jaffe Final Project: dll.cpp
#include <iostream>
#include "dll.hpp"
using namespace std;


DoublyLinkedList::DoublyLinkedList()
{
    //initalize head and tail to NULL
    head = NULL;
    tail = NULL;

}

void DoublyLinkedList::insert(int key)
{
    //create a new Node for the key
    Node *newNode = new Node;
    newNode->key = key;

    //check if newNode is the first Node in the doubly linked list
    if (head == NULL && tail == NULL){
        //set newNodes next and prev pointers to NULL
        newNode->next = NULL;
        newNode->prev = NULL;

        //set head and tail to point to newNode
        head = newNode;
        tail = newNode;

        //exit function
        return;
    }

    else{
        //make the previous Node point to newNode
        tail->next = newNode;

        //set newNodes previous to the Node before
        newNode->prev = tail;

        //set newNodes next pointer to NULL
        newNode->next = NULL;

        //move tail to point to newNode
        tail = tail->next;

        //exit function
        return;
    }
}

Node* DoublyLinkedList::search(int key)
{
    //create currNode to traverse through list, and set it to the beginning of DLL
    Node *currNode = head;

    //while loop to traverse through double linked list
    while (currNode != NULL){

        //check if key is found and if so return the Node
        if (currNode->key == key){
            return currNode;
        }

        //move currNode to next Node to traverse through DLL
        currNode = currNode->next;
    }

    //if the key was not found return NULL
    return NULL;
}

void DoublyLinkedList::print()
{
    //create currNode to traverse through list, and set it to the beginning of DLL
    Node *currNode = head;

    //while loop to traverse through double linked list
    while (currNode != NULL){
        //print the key currNode is pointing at
        cout << currNode->key << endl;

        //make currNode point to next node in DLL
        currNode = currNode->next;
    }

}
