//Shawn Jaffe Final Project: dll.hpp
#pragma once
#include <iostream>


//create a struct for DLL
struct Node{
    int key;
    Node *next;
    Node *prev;
};

//class for manipulating double linked-list
class DoublyLinkedList {
    private:
        //pointer to head of the first node in the doubly linked list
        Node *head;
        Node *tail;
    public:
        DoublyLinkedList(); //Constructor
        void insert(int key); //insert a new Node in the doubly linked list, with the value of int key
        Node* search(int key); //search the doubly linked list to find key
        void print(); //print the doubly linked list
};