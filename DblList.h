/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file defines the DblList class

High Level Decisions Used:
N/A
*/

#ifndef DBL_LIST_H
#define DBL_LIST_H
#include "ListNode.cpp"
#include <iostream>
using namespace std;
template <typename T>
class DblList{
public:
  DblList();
  virtual ~DblList();
  void print();
  //vanilla stuff
  int getSize();
  bool isEmpty();
  //additions
  void addBack(T data); //append to back
  void addFront(T data); //append to front
  void add(int pos, T data); //add at specified position
  //removes
  T removeBack();
  T removeFront();
  T remove(int pos);
  T removeSpecific(T data);
  //Accessor
  T get(int pos);
  bool contains(T data);
protected:
  ListNode<T>* m_front;
  ListNode<T>* m_back;
  int m_size;
};
#endif