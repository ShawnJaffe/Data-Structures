//Shawn Jaffe Final Project: dlldriver.cpp
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <random>
#include "dll.hpp"
using namespace std;

int main()
{

  /*********************************************************************************************************\
   * ============================================== DATA SET A =============================================\
   *********************************************************************************************************\
   */

  //declare object of dll class
  DoublyLinkedList DLL;

  //delcare an array to store data
  int testDataA[10000];

  //delcare count 
  int count = 0;

  //declare insert and search array times
  float insertA[100];
  float searchA[100];

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
      //insert the ID number into the DLL 
      DLL.insert(testDataA[j]);
    }

    //end timer after inserting 100 ID's
    auto dataAInsertEnd = chrono::steady_clock::now();

    //store the total time it took to insert 100 elements
    auto dataAInsertTotalTime = chrono::duration_cast<chrono::microseconds>(dataAInsertEnd - dataAInsertStart).count();

    //calculate the average it took to insert each element by dividing by 100
    float dataAInsertAverage = (dataAInsertTotalTime * 1.0) / 100 * 1.0;

    //insert the average into the insert array
    insertA[i] = dataAInsertAverage;


  /***************************************************************************
   * ============================= DataASearch ===============================
   * *************************************************************************
  */

    //start timer before searching 100 ID's
    auto dataASearchStart = chrono::steady_clock::now();

    //for loop to search 100 ID's 
    for (int j = currentLowerBound; j <= currentUpperBound; j++){
      int random = (rand() % 100) + currentLowerBound;
      DLL.search(testDataA[random]);
    }

    //end timer after searching 100 ID's
    auto dataASearchEnd = chrono::steady_clock::now();

    //store the total time it took to search 100 elements
    auto dataASearchTotalTime = chrono::duration_cast<chrono::microseconds>(dataASearchEnd - dataASearchStart).count();

    //calculate the average it took to search each element by dividing by 100
    float dataASearchAverage = (dataASearchTotalTime * 1.0)  / 100 * 1.0;

    //insert the average into the insert array
    searchA[i] = dataASearchAverage;


    //increase the lower and upper bound
    currentLowerBound = currentLowerBound + 100;
    currentUpperBound = currentUpperBound + 100;
}

  //create ofstream object
  ofstream outFile;

  //open outFile
  outFile.open("DataSetADLL.csv");

  //print insert times to the output file
  outFile << "Insert times: " << endl;

  //insert the insert times for data set A into DataSetADLL.csv
  for (int i = 0; i < 100; i++){
    outFile << insertA[i] << endl;
  }

  //print search times to the output file
  outFile << "Search times: " << endl;

  //insert the search times for data set A into DataSetADLL.csv
  for (int i = 0; i < 100; i++){
    outFile << searchA[i] << endl;
  }



  /*********************************************************************************************************\
   * ============================================== DATA SET B =============================================\
   *********************************************************************************************************\
   */

  //declare object of dll class
  DoublyLinkedList DLL2;

  //delcare an array to store data
  int testDataB[10000];

  //delcare count 
  count = 0;

  //declare insert and search array times
  float insertB[100];
  float searchB[100];

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
    testDataB[count] = IDNum;

    //increment count by 1
    count++;
  }

  //reset currentLowerBound and currentUpperBound
  currentLowerBound = 0;
  currentUpperBound = 99;

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
      //insert the ID number into the DLL
      DLL2.insert(testDataB[j]);
    }

    //end timer after inserting 100 ID's
    auto dataBInsertEnd = chrono::steady_clock::now();

    //store the total time it took to insert 100 elements
    auto dataBInsertTotalTime = chrono::duration_cast<chrono::microseconds>(dataBInsertEnd - dataBInsertStart).count();

    //calculate the average it took to insert each element by dividing by 100
    float dataBInsertAverage = (dataBInsertTotalTime * 1.0) / 100 * 1.0;

    //insert the average into the insert array
    insertB[i] = dataBInsertAverage;


    /***************************************************************************
     * ============================= DataBSearch ===============================
     * *************************************************************************
    */

    //start timer before searching 100 ID's
    auto dataBSearchStart = chrono::steady_clock::now();

    //for loop to search 100 ID's 
    for (int j = currentLowerBound; j <= currentUpperBound; j++){
      int random = (rand() % 100) + currentLowerBound;
      DLL2.search(testDataB[random]);
    }

    //end timer after searching 100 ID's
    auto dataBSearchEnd = chrono::steady_clock::now();

    //store the total time it took to search 100 elements
    auto dataBSearchTotalTime = chrono::duration_cast<chrono::microseconds>(dataBSearchEnd - dataBSearchStart).count();

    //calculate the average it took to search each element by dividing by 100
    float dataBSearchAverage = (dataBSearchTotalTime * 1.0)  / 100 * 1.0;

    //insert the average into the insert array
    searchB[i] = dataBSearchAverage;


    //increase the lower and upper bound
    currentLowerBound = currentLowerBound + 100;
    currentUpperBound = currentUpperBound + 100;
}

  //create ofstream object
  ofstream outFile2;

  //open outFile2
  outFile2.open("DataSetBDLL.csv");

  //print insert times to the output file
  outFile2 << "Insert times: " << endl;

  //insert the insert times for data set B into DataSetBDLL2.csv
  for (int i = 0; i < 100; i++){
    outFile2 << insertB[i] << endl;
  }

  //print search times to the output file
  outFile2 << "Search times: " << endl;
  //insert the search times for data set B into DataSetBDLL2.csv
  for (int i = 0; i < 100; i++){
    outFile2 << searchB[i] << endl;
  }

    
  return 0;
}