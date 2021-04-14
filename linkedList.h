#include<iostream>
#include<stdio.h>
#include<ctime>
#include <fstream>

using namespace std;
const int LIST_SIZE = 30;
int copyList[60];
int duplicateList[60];
int count = 0;

//node structure
struct ListNode {
  int data; //data
  ListNode *next; //pointer to next node
};

ListNode *head; 

//number generator
void randNumGen(int *randNums){
  srand((unsigned)time( 0 )); // setting seed
  
  for(int i = 0; i < 30; i++){ 
    randNums[i] = (rand()% 58 + 1); 
  }
}

//inserting/sorting the nodes 
void addNode(int randNums){
  //memory allocation and object type

  ListNode* newNode;
  ListNode* nodePntr; //used for list traversal
  
  newNode = new ListNode;
  newNode -> data = randNums;
  newNode -> next = NULL;
   
 
  if(!head || head -> data >= newNode -> data ){ 
    newNode -> next = head;
    head = newNode; //makes head point to the new node
     
  }

  else{ //inserting at the head of the list
    nodePntr = head; //start at the head of the list
  
    while(nodePntr -> next != NULL && nodePntr -> next -> data < newNode -> data){
      
      nodePntr = nodePntr -> next; //advance to next node

    }
    
    newNode -> next = nodePntr -> next;
    nodePntr -> next = newNode; // gives nodePntr access to the next value in the struct (since nodePntr is a pointer to the ListNode structure)
  }

}
 


// counting the duplicate nodes within the linked list
int getCount(ListNode* head){
  int *tempVal;
  

  while (head -> next != NULL){
    
    ListNode *pntr = head -> next;
    while (pntr != NULL){
      
      if(head -> data == pntr -> data){
        *tempVal = head -> data;
		count++;
        break;
      
	  }
      
      pntr = pntr -> next;
    }

    head = head -> next;
  }
  return count;
}


//displays the linked list in both main and a new text file
void displayLinkedList(){
  ListNode* nodePntr;
  nodePntr = head;
  ofstream linkedListData;
  

  cout << "Sorted Linked List Values:" << endl;
  
  
  //printing to text file
  linkedListData.open("results.txt");
  linkedListData << "Originally Generated Array" << endl;
  
  for(int i = 0; i < LIST_SIZE; i++){
    linkedListData << copyList[i] << " ";
  }

  linkedListData << endl; //formatting the layout of the text file
  linkedListData << endl;
  
  linkedListData << "Sorted Linked List Values:" << endl;


  while(nodePntr){
    printf("%d ", nodePntr -> data); // outputs linked list to console
    linkedListData  << nodePntr -> data << " "; //outputs linked list to .txt file
    nodePntr = nodePntr -> next;
  }

  //switiching back to printing to the console for layout consistency
  cout << endl;
  cout << endl;

  cout << "The current size of the Linked List is " << LIST_SIZE << " and it contains " << getCount(head) << " duplicates" << endl;
  
  //printing to text file again
  linkedListData << endl; //formatting the layout of the text file
  linkedListData << endl;

  linkedListData << "The current size of the Linked List is " << LIST_SIZE << " and it contains " << count << " duplicates" << endl; 



  linkedListData.close();


}
