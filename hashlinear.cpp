//Shawn Jaffe Final Project: hashlinear.cpp
#include <iostream>
#include <string>
#include "hashlinear.hpp"
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

    //set the keys value to newNode
    newNode->key = key;

    //return the new node
    return newNode;
}

bool HashTable::insertItem(int key)
{
    //go to hashFunction in order to get the keys hash value
    int hashValue = hashFunction(key);

    //check if the index of the bucket for the key to be inserted in is full
    if (table[hashValue] == NULL){

        //go to createNode function to create node with key
        node *newNode = createNode(key);
        
        //set the table at that hashValue to newNode;
        table[hashValue] = newNode;

        //return true
        return true;
    }

    else{
        //increase number of collisions by 1
        numOfcolision++;

        //while loop to keep going until a NULL bucket is found
        while (table[hashValue] != NULL){
            hashValue = (hashValue + 1) % tableSize;
        }
        

        //go to createNode function to create node with key
        node *newNode = createNode(key);

        //set the table at that hashValue to the new node
        table[hashValue] = newNode;

        //return true
        return true;
    }

    //return false
    return false;
}

void HashTable::printTable()
{
    //initalize count to 0
    int count = 0;

    //for loop to print buckets that have something in it
    for(int i = 0; i < tableSize; i++){
        if (table[i] != NULL){
            cout << "Bucket " << i << ": " << table[i]->key << endl;
            count++;
        }
    }
}

int HashTable::getNumOfCollision()
{ 
    return numOfcolision;
}

int HashTable::getNumOfSearchCollision()
{
    return numOfSearchCollision;
}

node* HashTable::searchItem(int key)
{
    //go to hashFunction in order to get the keys hash value
    int hashValue = hashFunction(key);

    //first check if we found key without a collision
    if (table[hashValue]->key == key){
        return table[hashValue];
    }

    //increment numOfSearchCollision by 1
    numOfSearchCollision++;

    //while loop to keep going until the key is found
    while (table[hashValue] != NULL){
    
        //check if the key was found
        if (table[hashValue]->key == key){
            return table[hashValue];
        }
        
        //go to next bucket
        hashValue = (hashValue + 1) % tableSize;
    }

    //if we get out of loop without finding the key then return NULL
    return NULL;
}