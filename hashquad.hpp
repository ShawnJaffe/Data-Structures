//Shawn Jaffe Final Project: hashquad.hpp
#ifndef HASHLQUAD_HPP
#define HASHQUAD_HPP
#include <string>

using namespace std;

struct node
{
    int key;
};

class HashTable
{
private:
    int tableSize;  // No. of buckets (linked lists)
    // Pointer to an array containing buckets
    node **table;
    int numOfcolision =0;
    int numOfSearchCollision = 0;
    node* createNode(int key);

public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();
    int getNumOfSearchCollision();

    node* searchItem(int key);
};

#endif
