//Shawn Jaffe Final Project: hashquad.cpp
#include <iostream>
#include <string>
#include "hashquad.hpp"
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
        //declare i
        int i = 1;

        //create a newHashValue
        int newHashValue = hashValue;

        //increase number of collisions by 1
        numOfcolision++;

        //while loop to keep going until a NULL bucket is found
        while (table[newHashValue] != NULL){
            //find the newHashValue by adding the original hash value to i squared, and taking the module of tableSize
            newHashValue = (hashValue + (i * i))% tableSize;

            //increment i by 1
            i++;
        }

        //check to see after going through while loop if the bucket to insert in is empty
        if (table[newHashValue] == NULL){
            //go to createNode function to create node with key
            node *newNode = createNode(key);

            //set the table at that hashValue to the new node
            table[newHashValue] = newNode;

            //return true
            return true;
        }

        //array is full, so return false
        else{
            return false;
        }
        
    }
}

void HashTable::printTable()
{
    //for loop to print buckets that have something in it
    for(int i = 0; i < tableSize; i++){
        if (table[i] != NULL){
            cout << "Bucket " << i << ": " << table[i]->key << endl;
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

    //declare newhashValue, and i
    int newHashValue = hashValue;
    int i = 1;

    //first check to see if we can find the key without a collision
    if (table[newHashValue]->key == key){
        return table[newHashValue];
    }
    
    //increase the number of collisons by 1
    numOfSearchCollision++;

    //while loop to keep going until the key is found
    while (table[newHashValue]->key != key){
        newHashValue = (hashValue + (i * i)) % tableSize;
        i++;
    }

    //check if the key was found in the hash table
    if (table[newHashValue]->key == key){
        return table[newHashValue];
    }
    
    //key was not found in table
    else{
        cout << "NOT FOUND!" << endl; 
        return NULL; 
    }
}