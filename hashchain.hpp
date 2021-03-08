//Shawn Jaffe Final Project: hashchain.hpp
#ifndef HASHCHAIN_HPP
#define HASHCHAIN_HPP
#include <string>

using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node **table;
    int numOfcolision =0;
    int numOfSearchCollisions=0;
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
