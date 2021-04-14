#include<iostream>
#include<stdio.h>
#include "linkedList.h"

using namespace std;


int main() {
  int randNums[LIST_SIZE];
  
  randNumGen(randNums);
  cout << "Originally Generated Array:" << endl;
  
  
  for(int i = 0; i < LIST_SIZE; i++){
    cout << randNums[i] << " " ;
    copyList[i] = randNums[i];
    addNode(randNums[i]);
  }

  cout << endl;
  cout << endl;
  
  displayLinkedList(); // displays the linkedList to both the consle and a text file.
  
  
}