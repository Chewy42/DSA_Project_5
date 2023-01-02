/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file is the implementation for the List Node class. This class acts as a node in our
doubly linked list and store a value, a left and right pointer

High Level Decisions Used:
N/A
*/

#include "ListNode.h"

/*
Name Of Function: ListNode overloaded constructor

Description of Value Returned:

Description of Parameters: T data is the data of the node

Description of exceptions thrown:

*/

template <typename T>
ListNode<T>::ListNode(T data){
  m_data = data;
  m_next = NULL;
  m_prev = NULL;
}

/*
Name Of Function: ListNode destructor

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
ListNode<T>::~ListNode(){
  m_next = NULL;
  m_prev = NULL;
}