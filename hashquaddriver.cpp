//Shawn Jaffe Final Project: hashquaddriver.cpp
#include <iostream>
#include "hashquad.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <random>
using namespace std;

int main()
{
/*********************************************************************************************************\
* ============================================== DATA SET A =============================================\
*********************************************************************************************************\
*/
    
    //declare object of HashTable class
    HashTable Quad(40009);

    //delcare an array to store data
    int testDataA[10000];

    //delcare count 
    int count = 0;

    //declare insert and search array times, as well as collisions
    float insertA[100];
    float searchA[100];
    int insertCollisionsA[100];
    int searchCollisionsA[100];

    //declare file
    ifstream inFile;
    string ID;

    //open the file
    inFile.open("dataSetA.csv");

    //while loop to insert data from file 
    while (getline(inFile, ID, ','))
    {
        //convert the ID from a string to an integer
        int IDNum = stoi(ID);

        //insert ID into array
        testDataA[count] = IDNum;

        //increment count by 1
        count++;
    }

    //initalize currentLowerBound and currentUpperBound
    int currentLowerBound = 0;
    int currentUpperBound = 99;

    //create a variable to store the collisions before its updated, and collisions per 100
    int previousCollisions = 0;
    int per100Collisions = 0;
    int previousSearchCollisions = 0;
    int per100SearchCollisions = 0;

    //for loop to fill insert and search array
    for (int i = 0; i < 100; i++){

    /**************************************************************************
  * ============================== DataAInsert ================================
  * ***************************************************************************
  */

        //start timer before inserting 100 ID's
        auto dataAInsertStart = chrono::steady_clock::now();

        //for loop to insert the ID's within the current range
        for (int j = currentLowerBound; j <= currentUpperBound; j++){
            //insert the ID number into the Hash Table Linear 
            Quad.insertItem(testDataA[j]);
        }
 
        //end timer after inserting 100 ID's
        auto dataAInsertEnd = chrono::steady_clock::now();

        //store the total time it took to insert 100 elements
        auto dataAInsertTotalTime = chrono::duration_cast<chrono::microseconds>(dataAInsertEnd - dataAInsertStart).count();

        //calculate the average it took to insert each element by dividing by 100
        float dataAInsertAverage = (dataAInsertTotalTime * 1.0) / 100 * 1.0;

        //insert the average into the insert array
        insertA[i] = dataAInsertAverage;

        //get the number of total collisions
        int totalCollisions = Quad.getNumOfCollision();

        //find the amount of collisions for the set of 100 ID's inserted
        per100Collisions = (totalCollisions - previousCollisions);

        //insert the collisions into the collisonsA array
        insertCollisionsA[i] = per100Collisions;

        //update the previous collisons to total collisions
        previousCollisions = totalCollisions; 
        
        
    /***************************************************************************
     * ============================= DataASearch ===============================
     * *************************************************************************
     */
 
        //start timer before searching 100 ID's
        auto dataASearchStart = chrono::steady_clock::now();
    
        //for loop to search 100 ID's 
        for (int j = currentLowerBound; j <= currentUpperBound; j++){
            int random = (rand() % 100) + currentLowerBound;
            Quad.searchItem(testDataA[random]);
        }

        //end timer after searching 100 ID's
        auto dataASearchEnd = chrono::steady_clock::now();

        //store the total time it took to search 100 elements
        auto dataASearchTotalTime = chrono::duration_cast<chrono::microseconds>(dataASearchEnd - dataASearchStart).count();

        //calculate the average it took to search each element by dividing by 100
        float dataASearchAverage = (dataASearchTotalTime * 1.0)  / 100 * 1.0;

        //insert the average into the insert array
        searchA[i] = dataASearchAverage;

        //get the number of total collisions
        int totalSearchCollisions = Quad.getNumOfSearchCollision();

        //find the amount of collisions for the set of 100 ID's inserted
        per100SearchCollisions = (totalSearchCollisions - previousSearchCollisions);

        //insert the collisions into the collisons A array
        searchCollisionsA[i] = per100SearchCollisions;

        //update the previous collisons to total collisions
        previousSearchCollisions = totalSearchCollisions;
        
        //increase the lower and upper bound
        currentLowerBound = currentLowerBound + 100;
        currentUpperBound = currentUpperBound + 100;
    } 
    
 
    //create ofstream object
    ofstream outFile;

    //open outFile
    outFile.open("DataSetAQuad.csv");

    //print insert times to the output file
    outFile << "Insert times: " << endl;

    //insert the insert times for data set A into DataSetAQuad.csv
    for (int i = 0; i < 100; i++){
        outFile << insertA[i] << endl;
    }

    //print search times to the output file
    outFile << "Search times: " << endl;

    //insert the search times for data set A into DataSetAQuad.csv
    for (int i = 0; i < 100; i++){
        outFile << searchA[i] << endl;
    }

    //print insert collisions to the output file
    outFile << "Insert collisions: " << endl;

    //insert the insert collisions for data set A into DataSetAQuad.csv
    for (int i = 0; i < 100; i++){
        outFile << insertCollisionsA[i] << endl;
    }

    //print search collisions to the output file
    outFile << "Search collisions: " << endl;
    
    //insert the search collisions for data set A into DataSetAQuad.csv
    for (int i = 0; i < 100; i++){
        outFile << searchCollisionsA[i] << endl; 
    }

    //print the total number of insert and search collisions at the end of the output file
    outFile << "Insert Collisions: " << Quad.getNumOfCollision() << endl;
    outFile << "Search Collisions: " << Quad.getNumOfSearchCollision() << endl; 



/*********************************************************************************************************\
* ============================================== DATA SET B =============================================\
*********************************************************************************************************\
*/
    
    //declare object of HashTable class
    HashTable Quad2(40009);

    //delcare an array to store data
    int testDataB[10000];

    //delcare count 
    int count2 = 0;

    //declare insert and search array times, as well as collisions
    float insertB[100];
    float searchB[100];
    int insertCollisionsB[100];
    int searchCollisionsB[100];

    //declare file
    ifstream inFile2;
    string ID2;

    //open the file
    inFile2.open("dataSetB.csv");

    //while loop to insert data from file 
    while (getline(inFile2, ID2, ','))
    {
        //convert the ID from a string to an integer
        int IDNum = stoi(ID2);

        //insert ID into array
        testDataB[count2] = IDNum;

        //increment count by 1
        count2++;
    }

    //initalize currentLowerBound and currentUpperBound
    currentLowerBound = 0;
    currentUpperBound = 99;

    //create a variable to store the collisions before its updated, and collisions per 100
    previousCollisions = 0;
    per100Collisions = 0;
    previousSearchCollisions = 0;
    per100SearchCollisions = 0;

    //for loop to fill insert and search array
    for (int i = 0; i < 100; i++){

    /**************************************************************************
  * ============================== DataBInsert ================================
  * ***************************************************************************
  */

        //start timer before inserting 100 ID's
        auto dataBInsertStart = chrono::steady_clock::now();
    
        //for loop to insert the ID's within the current range
        for (int j = currentLowerBound; j <= currentUpperBound; j++){
            //insert the ID number into the Hash Table Linear 
            Quad2.insertItem(testDataB[j]);
        }
 
        //end timer after inserting 100 ID's
        auto dataBInsertEnd = chrono::steady_clock::now();

        //store the total time it took to insert 100 elements
        auto dataBInsertTotalTime = chrono::duration_cast<chrono::microseconds>(dataBInsertEnd - dataBInsertStart).count();

        //calculate the average it took to insert each element by dividing by 100
        float dataBInsertAverage = (dataBInsertTotalTime * 1.0) / 100 * 1.0;

        //insert the average into the insert array
        insertB[i] = dataBInsertAverage;

        //get the number of total collisions
        int totalCollisions = Quad2.getNumOfCollision();

        //find the amount of collisions for the set of 100 ID's inserted
        per100Collisions = (totalCollisions - previousCollisions);

        //insert the collisions into the collisons B array
        insertCollisionsB[i] = per100Collisions;

        //update the previous collisons to total collisions
        previousCollisions = totalCollisions; 
        
        
    /***************************************************************************
     * ============================= DataBSearch ===============================
     * *************************************************************************
     */
 
        //start timer before searching 100 ID's
        auto dataBSearchStart = chrono::steady_clock::now();
    
        //for loop to search 100 ID's 
        for (int j = currentLowerBound; j <= currentUpperBound; j++){
            int random = (rand() % 100) + currentLowerBound;
            Quad2.searchItem(testDataB[random]);
        }

        //end timer after searching 100 ID's
        auto dataBSearchEnd = chrono::steady_clock::now();

        //store the total time it took to search 100 elements
        auto dataBSearchTotalTime = chrono::duration_cast<chrono::microseconds>(dataBSearchEnd - dataBSearchStart).count();

        //calculate the average it took to search each element by dividing by 100
        float dataBSearchAverage = (dataBSearchTotalTime * 1.0)  / 100 * 1.0;

        //insert the average into the insert array
        searchB[i] = dataBSearchAverage;

        //get the number of total collisions
        int totalSearchCollisions = Quad2.getNumOfSearchCollision();

        //find the amount of collisions for the set of 100 ID's inserted
        per100SearchCollisions = (totalSearchCollisions - previousSearchCollisions);

        //insert the collisions into the collisons B array
        searchCollisionsB[i] = per100SearchCollisions;

        //update the previous collisons to total collisions
        previousSearchCollisions = totalSearchCollisions;
        
        //increase the lower and upper bound
        currentLowerBound = currentLowerBound + 100;
        currentUpperBound = currentUpperBound + 100;
    } 
    

 
    //create ofstream object
    ofstream outFile2;

    //open outFile
    outFile2.open("DataSetBQuad.csv");

    //print insert times to the output file
    outFile2 << "Insert times: " << endl;

    //insert the insert times for data set B into DataSetBQuad.csv
    for (int i = 0; i < 100; i++){
        outFile2 << insertB[i] << endl;
    }

    //print search times to the output file
    outFile2 << "Search times: " << endl;

    //insert the search times for data set B into DataSetBQuad.csv
    for (int i = 0; i < 100; i++){
        outFile2 << searchB[i] << endl;
    }

    //print insert collisions to the output file
    outFile2 << "Insert collisions: " << endl;

    //insert the insert collisions for data set B into DataSetBQuad.csv
    for (int i = 0; i < 100; i++){
        outFile2 << insertCollisionsB[i] << endl;
    }

    //print search collisions to the output file
    outFile2 << "Search collisions: " << endl;

    //insert the search collisions for data set B into DataSetBQuad.csv
    for (int i = 0; i < 100; i++){
        outFile2 << searchCollisionsB[i] << endl; 
    }

    //print the total number of insert and search collisions at the end of the output file    
    outFile2 << "Insert Collisions: " << Quad2.getNumOfCollision() << endl;
    outFile2 << "Search Collisions: " << Quad2.getNumOfSearchCollision() << endl; 


    return 0;

}
