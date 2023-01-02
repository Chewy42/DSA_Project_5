/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file is the implementation for the Tree Node class. This class acts as a node in our
scape goat tree and store a value, a left, right, and parent pointer.

High Level Decisions Used:
N/A
*/

#include "TreeNode.h"

/*
Name Of Function: TreeNode overloaded constructor

Description of Value Returned:

Description of Parameters: T d is the data in the node

Description of exceptions thrown:

*/

template <typename T>
TreeNode<T>::TreeNode(T d){
    m_data = d;
    m_left = NULL;
    m_right = NULL;
}

/*
Name Of Function: TreeNode destructor

Description of Value Returned:

Description of Parameters: 

Description of exceptions thrown:

*/

template <typename T>
TreeNode<T>::~TreeNode(){
    if(m_left != NULL){
        delete m_left;
    }
    if(m_right != NULL){
        delete m_right;
    }
}

/*
Name Of Function: getData()

Description of Value Returned: T is the data in the node

Description of Parameters: 

Description of exceptions thrown:

*/

template <typename T>
T TreeNode<T>::getData(){
    return m_data;
}

/*
Name Of Function: getLeft()

Description of Value Returned: Node to the left

Description of Parameters: 

Description of exceptions thrown:

*/

template <typename T>
TreeNode<T>* TreeNode<T>::getLeft(){
    return m_left;
}

/*
Name Of Function: getRight()

Description of Value Returned: Node to the right

Description of Parameters: 

Description of exceptions thrown:

*/

template <typename T>
TreeNode<T>* TreeNode<T>::getRight(){
    return m_right;
}