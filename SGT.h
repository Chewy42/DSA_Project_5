/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file defines the SGT (Scape Goat Tree) class. This is where all of our methods are stored that we will
need for our scape goat tree that also support what we will need for our database.

High Level Decisions Used:
I used my knowledge of OOP to create methods that would apply to both student and faculty records to be used
in the database class which made my code a lot cleaner even though I had to rewrite it a few times.
*/

#ifndef SGT_H
#define SGT_H
#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
template <typename T>
class SGT{
public:
  SGT();
  virtual ~SGT();
  bool insert(T d);
  void remove(T d);
  bool contains(T d);
  void printInOrder();
  void printPostOrder();
  int getSize();
  T getMedian();
  T getMin();
  T getMax();
  TreeNode<T>* getRoot();
  T getById(int id);
  void getByIdAndPrint(int id);
  bool idExists(int id);
  void printInfo();
  void outputInfo();
private:
  TreeNode<T>* m_root;
  int m_size;
  int m_m; // tracked deletions
  bool m_unique;
  T found;
  bool containsHelper(TreeNode<T>* subTreeRoot, T d);
  void printInOrderHelper(TreeNode<T>* subTreeRoot);
  void printPostOrderHelper(TreeNode<T>* subTreeRoot);
  T getMinHelper(TreeNode<T>* subTreeRoot);
  T getMaxHelper(TreeNode<T>* subTreeRoot);
  void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
  T getSuccessor(TreeNode<T>* node);
  int storeInArray(TreeNode<T>* ptr, TreeNode<T>* arr[], int i);
  TreeNode<T>* buildBalancedFromArray(TreeNode<T>** arr, int i, int n);
  int insertWithDepth(TreeNode<T>* node);
  int getNodeSize(TreeNode<T>* node);
  void rebuildTree(TreeNode<T>* node);
  void getByIdHelper(TreeNode<T>* subTreeRoot, int id);
  TreeNode<T>* getByIdAndPrintHelper(TreeNode<T>* subTreeRoot, int id);
  void idExistsHelper(TreeNode<T>* subTreeRoot, int id);
  void printInfoHelper(TreeNode<T>* subTreeRoot);
  void outputInfoHelper(TreeNode<T>* subTreeRoot);
};

#endif