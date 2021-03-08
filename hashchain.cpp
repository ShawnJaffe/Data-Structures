//Shawn Jaffe Final Project: hashchain.cpp
#include <iostream>
#include <string>
#include "hashchain.hpp"
using namespace std;


HashTable::HashTable(int bsize)
{
    //set table size equal to bsize
    tableSize = bsize;

    //create the hash table array of size tableSize
    table = new node*[tableSize];

    //for loop to initalize all buckets to NULL
    for (int i = 0; i < tableSize; i++)
        table[i] = NULL;    
}


unsigned int HashTable::hashFunction(int key)
{
    //find the index to map the key where it should be inserted
    return key % tableSize;
}

node* HashTable::createNode(int key)
{
    //create a node called newNode
    node *newNode = new node; 
    
    //set newNodes key equal to the key, and make it point to next
    newNode->key = key;
    newNode->next = NULL;

    //return newNode
    return newNode;
}

bool HashTable::insertItem(int key)
{
    //go to hashFunction in order to get the keys hash value
    int hashValue = hashFunction(key);

    //insert the key at the hash value of the table
    node *insert = table[hashValue];

    //check if theres nothing at the place where the key is to be inserted
    if (insert == NULL){
        //create a newNode for the key
        node *newNode = createNode(key);

        //set the pointer at the index of table array to point to newNode
        table[hashValue] = newNode;

        //return true
        return true;
    }

    else{

        //increase number of collisions by 1
        numOfcolision++;

        //create a newNode for the key
        node *newNode = createNode(key);
        
        //while loop to make insert point to the node before the one inserted
        while (insert->next != NULL){

            //move to the next node in LL
            insert = insert->next;
        }
        //make insert point to the newNode 
        insert->next = newNode;

        //return true
        return true;
    }

    //return false if the node was not inserted
    return false;
}

void HashTable :: printTable()
{
    //create currNode to go though LL
    node *currNode;

    //for loop to traverse through table
    for (int i = 0; i < tableSize; i++){
        //set currNode equal to the pointer at that table index
        currNode = table[i];

        //print the bucket
        cout << "In bucket " << i << ": ";

        //while loop to go through all nodes in LL
        while (currNode != NULL){
            //print the keys at that bucket
            cout << currNode->key << "--> ";

            //move currNode over one node
            currNode = currNode->next;
        }

        //end of line after each for loop iteration
        cout << endl;
    }
}

int HashTable::getNumOfCollision()
{ 
    return numOfcolision;
}

int HashTable::getNumOfSearchCollision()
{ 
    return numOfSearchCollisions;
}


node* HashTable::searchItem(int key)
{
    //create currNode to go though bucket
    node *currNode;

    //go to hash function to find the index 
    int index = hashFunction(key);

    //make currNode point to the index of the hash code
    currNode = table[index];

    //check initally if the currentNode matches the key, and there are no collisions
    if (currNode->key == key){
        return currNode;
    }

    //there is a collision therefore increment collisions by 1
    numOfSearchCollisions++;

    //while loop to traverse to go through all nodes at that index
    while (currNode->key != key && currNode != NULL){

        //make currNode point to the next node
        currNode = currNode->next;
    }

    //check to see if the current node key is equal to the key
    if (currNode->key == key){
        return currNode;
    }

    //check if the key was not found
    else{
        cout << "NOT FOUND!" << endl;
        return NULL;
    }

}




