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
  if (in == nullptr) { // basecase
    return;
  }

  Node* nextNode = in->next;

  if (in->value % 2 == 1) { // if the value that is being pointed at is odd
    in->next = odds; // sets pointer to point at odds
    odds = in; // updates head of odd to be the current node
  }

  else {
    in->next = evens; // sets pointer to point at evens
    evens = in; // updates head of even to be the current node
  }

  split(nextNode, odds, evens); // when using nextNode to update, keeps failing input set to nulldfiojasdf;jkfsadj;k

  if (nextNode == nullptr) { // modify original list pointer
    in = nullptr;
  }

}

/* If you needed a helper function, write it here */
