/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file defines the Tree Node class

High Level Decisions Used:
N/A
*/

#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <cstdlib>
#include <iostream>
template <typename T>
class TreeNode{
public:
    TreeNode(T d);
    virtual ~TreeNode();
    T getData();
    TreeNode<T>* getLeft();
    TreeNode<T>* getRight();
    template <typename S>
    friend class SGT;
private:
    T m_data;
    TreeNode<T>* m_parent;
    TreeNode<T>* m_left;
    TreeNode<T>* m_right;
};

#endif