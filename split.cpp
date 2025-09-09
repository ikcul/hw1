/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  //already sorted

  //check if in is nullptr
  //check if odds is nullptr
  //check if evens is nullptr
  //else add first value into either odds and even
  //unlink the node and attribute it to its respective list


  Node* temp = new Node;
  temp->val = in->val;
  temp->next = in->next;

  if (in == nullptr){
    return;
  }else if(temp->val % 2 == 1 && odds == nullptr){
    odds->val = temp->val;
    odds->next = nullptr;
    //unlink the node from the original list
    temp->next = 
  }


}

/* If you needed a helper function, write it here */
