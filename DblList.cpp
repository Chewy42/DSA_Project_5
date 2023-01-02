/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file is the implementation for the DblList class. This class is used as a list
build of nodes with left and right pointers so that you can add() to it,
remove() from it, and get() from it.

High Level Decisions Used:
I implemented my own removeSpecific() method that will find a node based
on the value and remove it from the list, then return the value
*/

#include "DblList.h"

/*
Name Of Function: DblList constructor

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
DblList<T>::DblList(){
  m_size = 0;
  m_front = NULL;
  m_back = NULL;
}

/*
Name Of Function: DblList destructor

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
DblList<T>::~DblList(){
  //todo - free memory
  m_size = 0;
  m_front = NULL;
  m_back = NULL;
}

/*
Name Of Function: getSize()

Description of Value Returned: integer of the size of the list

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
int DblList<T>::getSize(){
  return m_size;
}

/*
Name Of Function: isEmpty()

Description of Value Returned: boolean if the size of the list is 0

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
bool DblList<T>::isEmpty(){
  return (m_size==0);
}

/*
Name Of Function: get

Description of Value Returned: T which is the value at the position

Description of Parameters: integer pos which is the position in the dbl list we need to get

Description of exceptions thrown:

*/

template <typename T>
T DblList<T>::get(int pos){
  //first check position is valid, check if empty
  int cPos = 0;
  ListNode<T>* current = m_front;
  while(cPos != pos){
    current = current->m_next;
    ++cPos;
  }
  return current->m_data;
}

/*
Name Of Function: contains()

Description of Value Returned: boolean if the list contains a value

Description of Parameters: T data which is the data we wanna see if it is in the list

Description of exceptions thrown:

*/

template <typename T>
bool DblList<T>::contains(T data){
  bool found = false;
  ListNode<T>* current = m_front;
  while(current != NULL){
    if(data == current->m_data){
      found = true;
      break;
    }else{
      current = current->m_next;
    }
  }
  return found;
}

/*
Name Of Function: addFront()

Description of Value Returned:

Description of Parameters: T data which will be added to the front of the list

Description of exceptions thrown:

*/

template <typename T>
void DblList<T>::addFront(T data){
  ListNode<T>* newNode = new ListNode<T>(data);
  if(!isEmpty()){
    m_front->m_prev = newNode;
    newNode->m_next = m_front;
  } else{ //it's empty
    m_back = newNode;
  }
  m_front = newNode;
  ++m_size;
}

/*
Name Of Function: addBack()

Description of Value Returned:

Description of Parameters: T data which will be added to the back of the list

Description of exceptions thrown:

*/

template <typename T>
void DblList<T>::addBack(T data){
  ListNode<T>* newNode = new ListNode<T>(data);
  if(!isEmpty()){
    m_back->m_next = newNode;
    newNode->m_prev = m_back;
  } else{
    m_front = newNode;
  }
  m_back = newNode;
  ++m_size;
}

/*
Name Of Function: add()

Description of Value Returned:

Description of Parameters: integer position that the data will be added and T data which is the data that will be added

Description of exceptions thrown:

*/

template <typename T>
void DblList<T>::add(int pos, T data){
  if(isEmpty()){ //empty
    addFront(data); //it's empty so ignore position
  } else if(pos==0){ //first pos
    addFront(data);
  } else if(pos>=m_size-1){ //last pos
    addBack(data);
  } else{ //somewhere in middle
    ListNode<T>* current = m_front;
    int cPos = 0;
    while(cPos!=pos){
      current = current->m_next;
      ++cPos;
    }
    ListNode<T>* newNode = new ListNode<T>(data);
    current->m_prev->m_next = newNode;
    newNode->m_prev = current->m_prev;
    current->m_prev = newNode;
    newNode->m_next = current;
    ++m_size;
  }
}

/*
Name Of Function: removeFront()

Description of Value Returned: T which is what was removed

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
T DblList<T>::removeFront(){
  //handling for empty list
  T data;
  data = m_front->m_data;
  if(m_size == 1){
    delete m_front; //free up memory
    m_front = NULL;
    m_back = NULL;
  } else{ //multiple things in list
    ListNode<T>* currFront = m_front;
    m_front = m_front->m_next;
    m_front->m_prev = NULL;
    currFront->m_next = NULL;
    delete currFront;
  }
  --m_size;
  return data;
}

/*
Name Of Function: removeBack()

Description of Value Returned: T which is what was removed

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
T DblList<T>::removeBack(){
  //handling for empty list
  T data;
  data = m_back->m_data;
  if(m_size == 1){
    delete m_front; //free up memory
    m_front = NULL;
    m_back = NULL;
  } else{ //multiple things in list
    ListNode<T>* currBack = m_back;
    m_back = m_back->m_prev;
    m_back->m_next = NULL;
    currBack->m_prev = NULL;
    delete currBack;
  }
  --m_size;
  return data;
}

/*
Name Of Function: remove()

Description of Value Returned: T which was what was removed

Description of Parameters: integer pos for the position we will remove from the list at

Description of exceptions thrown:

*/

template <typename T>
T DblList<T>::remove(int pos){
  //check if empty
  T data;
  if(pos<=0){
    data = removeFront();
  } else if(pos >= m_size-1){
    data = removeBack();
  } else{
    //Find position and remove
    ListNode<T>* current = m_front;
    int cPos = 0;
    while(cPos != pos){
      current = current->m_next;
      ++cPos;
    }
    data = current->m_data;
    current->m_prev->m_next = current->m_next;
    current->m_next->m_prev = current->m_prev;
    current->m_next = NULL;
    current->m_prev = NULL;
    delete current;
    --m_size;
  }
  return data;
}

/*
Name Of Function: removeSpecific

Description of Value Returned: T which is what was removed

Description of Parameters: T data which is the data that will be removed

Description of exceptions thrown:

*/

template <typename T>
T DblList<T>::removeSpecific(T data){
  if(m_front->m_data == data){
    removeFront();
  }else if(m_back->m_data == data){
    removeBack();
  }else{
    ListNode<T>* current = m_front;
    int i = 0;
    while(current->m_data != data && i < m_size){
      cout << i << endl;
      current = current->m_next;
      ++i;
    }
    T d;
    d = current->m_data;
    current->m_prev->m_next = current->m_next;
    current->m_next->m_prev = current->m_prev;
    current->m_next = NULL;
    current->m_prev = NULL;
    delete current;
    --m_size;
    return d;
  }
}

/*
Name Of Function: print(0)

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/


template <typename T>
void DblList<T>::print(){
  ListNode<T>* current = m_front;
  while(current!=NULL){
    cout << current->m_data << endl;
    current = current->m_next;
  }
}