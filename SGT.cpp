/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file is the implementation for the SGT (Scape Goat Tree) class. This class is the
main functionality behind our database. Here we handle all the key methods such as
insert(), contains(), remove().

High Level Decisions Used:
The highest level decisions I used was creating the recursive methods because it put's
you in a completly different mindset when you think about how your code runs.
*/

#include "SGT.h"
#include "TreeNode.cpp"
#include <cmath>

/*
Name Of Function: log32()

Description of Value Returned: integer of log32 function

Description of Parameters: integer n which is the length

Description of exceptions thrown:

*/

static int const log32(int n)
{
  double const log23 = 1.7;
  return (int)ceil(log23 * log(n));
}

/*
Name Of Function: SGT constructor

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
SGT<T>::SGT(){
  m_root = NULL;
  m_size = 0;
}

/*
Name Of Function: SGT destructor

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
SGT<T>::~SGT(){
  if(m_root != NULL){
    delete m_root;
  }
}

/*
Name Of Function: getSize()

Description of Value Returned: integer of SGT size

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
int SGT<T>::getSize(){
  return m_size;
}

/*
Name Of Function: insert

Description of Value Returned: boolean if height >= 0

Description of Parameters: T d is the data being inserted

Description of exceptions thrown:

*/

template <typename T>
bool SGT<T>::insert(T d){
  TreeNode<T>* node = new TreeNode<T>(d);
  int height = insertWithDepth(node);
  ++m_m;
  if (height > log32(m_size)){
    TreeNode<T>* parent = node->m_parent;
    while (3 * getNodeSize(parent) <= 2 * getNodeSize(parent->m_parent)){
      parent = parent->m_parent;
    }
    rebuildTree(parent->m_parent);
  }
  return height >= 0;
}

/*
Name Of Function: insertWithDepth

Description of Value Returned: integer of depth

Description of Parameters: TreeNode<T>* insertNode is the node being inserted

Description of exceptions thrown:

*/

template <typename T>
int SGT<T>::insertWithDepth(TreeNode<T>* insertNode){
  TreeNode<T>* curr = m_root;
  if (curr == NULL){
    m_root = insertNode;
    m_size++;
    return 0;
  }
  bool isInserted = false;
  int depth = 0;
  do{
    if(*insertNode->m_data < *curr->m_data){
      if(curr->m_left == NULL){
        curr->m_left = insertNode;
        insertNode->m_parent = curr;
        isInserted = true;
      }else{
        curr = curr->m_left;
      }
    }else if(*insertNode->m_data > *curr->m_data){
      if(curr->m_right == NULL){
        curr->m_right = insertNode;
        insertNode->m_parent = curr;
        isInserted = true;
      }else{
        curr = curr->m_right;
      }
    }else{
      return -1;
    }
    depth++;
  }
  while (!isInserted);
  m_size++;
  return depth;
}

/*
Name Of Function: contains()

Description of Value Returned: boolean if the SGT contains the data

Description of Parameters: T d is the data being checked

Description of exceptions thrown:

*/

template <typename T>
bool SGT<T>::contains(T d){
    return containsHelper(m_root,d);
}

/*
Name Of Function: containsHelper

Description of Value Returned: boolean if the SGT contains the data

Description of Parameters: TreeNode<T>* subTreeRoot is the root being passed recursively, T d is the data being checked

Description of exceptions thrown:

*/

template <typename T>
bool SGT<T>::containsHelper(TreeNode<T>* subTreeRoot, T d){
  if(subTreeRoot == NULL){
    return false;
  } else if (subTreeRoot->m_data == d){
    return true;
  } else if(d < subTreeRoot->m_data){
    return containsHelper(subTreeRoot->m_left,d);
  } else{
    return containsHelper(subTreeRoot->m_right,d);
  }
}

/*
Name Of Function: findTarget

Description of Value Returned:

Description of Parameters: T key is the key, TreeNode<T>*& target is the target we wanna get by address, and TreeNode<T>*& parent is the parent node

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
  while(target != NULL && target->m_data != key){
    parent = target;
    if(key < target->m_data){
      target = target->m_left;
    } else{
      target = target->m_right;
    }
  }
}

/*
Name Of Function: remove()

Description of Value Returned:

Description of Parameters: T d is the data we are removing

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::remove(T d){
  //make sure to free memory
  //check for follishness
  TreeNode<T>* parent = NULL; //keep track of what needs to be deleted and patched
  TreeNode<T>* target = NULL;
  //do the remove
  target = m_root;
  findTarget(d,target,parent);
   if(target == NULL){ //not in tree
    return;
  }
  //do some real work
  if(target->m_left == NULL && target->m_right == NULL ){ //it's a leaf
    if(target == m_root){
      m_root = NULL;
      --m_size;
      if(m_m > 2 * m_size){
        rebuildTree(m_root);
        m_m = m_size;
      }
    } else{
      if(target == parent->m_left){
        parent->m_left = NULL;
        --m_size;
        if(m_m > 2 * m_size){
        rebuildTree(m_root);
        m_m = m_size;
      }
      } else{
        parent->m_right = NULL;
        --m_size;
        if(m_m > 2 * m_size){
        rebuildTree(m_root);
        m_m = m_size;
        }
      }
    }
  } else if(target->m_left != NULL && target->m_right != NULL){ //2 children
    T succValue = getSuccessor(target->m_right);
    remove(succValue);
    target->m_data = succValue;
  } else{ // 1 child
    TreeNode<T>* child;
    if(target->m_left != NULL){
      child = target->m_left;
    } else{
      child = target->m_right;
    }
    if(target == m_root){
      m_root = child;
    } else{
      if(target == parent->m_left){
        parent->m_left = child;
      } else{
        parent->m_right = child;
      }
    }
  }
}

/*
Name Of Function: storeInArray()

Description of Value Returned: integer of null nodes

Description of Parameters: TreeNode<T>* node is the node being added recursively, the array of nodes is being passed recursively and adding the nodes to it from
left to right

Description of exceptions thrown:

*/

template <typename T>
int SGT<T>::storeInArray(TreeNode<T>* node, TreeNode<T>* arr[], int i)
{
  if (node == NULL){
    return i;
  }
  
  i = storeInArray(node->m_left, arr, i);
  arr[i++] = node;
  return storeInArray(node->m_right, arr, i);
}

/*
Name Of Function: getNodeSize()

Description of Value Returned: integer of the nodes size / how many nodes this node has

Description of Parameters: Node that will be checked the size of

Description of exceptions thrown:

*/

template <typename T>
int SGT<T>::getNodeSize(TreeNode<T>* node){
    if (node == NULL){
        return 0;
    }else{
        return(getNodeSize(node->m_left) + 1 + getNodeSize(node->m_right));
    }
}

/*
Name Of Function: buildBalancedFromArray()

Description of Value Returned: Node that is the root

Description of Parameters: Array of nodes, integer i is the iteration number, integer n is the length

Description of exceptions thrown:

*/

template <typename T>
TreeNode<T>* SGT<T>::buildBalancedFromArray(TreeNode<T>** arr, int i, int n){
    if (n == 0){ //length is 0
        return NULL;
    }

    int center = n / 2; //center = length / 2

    arr[i + center]->m_left = buildBalancedFromArray(arr, i, center); // build left sub tree
 
    if (arr[i + center]->m_left != NULL){
        arr[i + center]->m_left->m_parent = arr[i + center];
    }

    arr[i + center]->m_right = buildBalancedFromArray(arr, i + center + 1, n - center - 1); // build right sub tree

    if (arr[i + center]->m_right != NULL){
        arr[i + center]->m_right->m_parent = arr[i + center];
    }

    return arr[i + center];
}

/*
Name Of Function: rebuildTree()

Description of Value Returned:

Description of Parameters: Node that is being rebuilt 

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::rebuildTree(TreeNode<T>* node){
  int n = getNodeSize(node);
  TreeNode<T>* parent = node->m_parent;
  TreeNode<T>** arr = new TreeNode<T>*[n];
  storeInArray(node, arr, 0);
  if (parent == NULL)
  {
    m_root = buildBalancedFromArray(arr, 0, m_size);
    m_root->m_parent = NULL;
  }
  else if (parent->m_right == node)
  {
    parent->m_right = buildBalancedFromArray(arr, 0, m_size);
    parent->m_right->m_parent = parent;
  }
  else
  {
    parent->m_left = buildBalancedFromArray(arr, 0, m_size);
    parent->m_left->m_parent = parent;
  }
}

/*
Name Of Function: getSuccessor()

Description of Value Returned: T which is the data of the successor

Description of Parameters: Node that is the node we want to get a successor from

Description of exceptions thrown:

*/

template <typename T>
T SGT<T>::getSuccessor(TreeNode<T>* node){ //assume node starts at right child
  while(node->m_left != NULL){
    node = node->m_left;
  }
  return node->m_data;
}

/*
Name Of Function: getMedian()

Description of Value Returned: T is the data of the median node or root node

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
T SGT<T>::getMedian(){
  return m_root->m_data;
}

/*
Name Of Function: getMin()

Description of Value Returned: T is the data of the smallest node

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
T SGT<T>::getMin(){
  return getMinHelper(m_root);
}

/*
Name Of Function: getMax()

Description of Value Returned: T is the data of the biggest node

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
T SGT<T>::getMax(){
  return getMaxHelper(m_root);
}

/*
Name Of Function: getMinHelper()

Description of Value Returned: T is the data of the smallest node

Description of Parameters: Node of the sub tree root being passed recursively

Description of exceptions thrown:

*/

template <typename T>
T SGT<T>::getMinHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_left == NULL){
    return subTreeRoot->m_data;
  } else{
    return getMinHelper(subTreeRoot->m_left);
  }
}

/*
Name Of Function: getMaxHelper()

Description of Value Returned: T is the data of the biggest node being passed recursively

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
T SGT<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_right == NULL){
    return subTreeRoot->m_data;
  } else{
    return getMaxHelper(subTreeRoot->m_right);
  }
}

/*
Name Of Function: printInOrder()

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::printInOrder(){
  printInOrderHelper(m_root);
}

/*
Name Of Function: printInOrderHelper

Description of Value Returned:

Description of Parameters: Node subtreeroot being passed recursively

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::printInOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printInOrderHelper(subTreeRoot->m_left);
    cout << subTreeRoot->m_data->getId() << endl;
    printInOrderHelper(subTreeRoot->m_right);
  }
}

/*
Name Of Function: printPostOrder()

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::printPostOrder(){
  printPostOrderHelper(m_root);
}

/*
Name Of Function: printPostOrderHelper()

Description of Value Returned:

Description of Parameters: Node subtreeroot being passed recursively

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::printPostOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printPostOrderHelper(subTreeRoot->m_left);
    printPostOrderHelper(subTreeRoot->m_right);
    cout << subTreeRoot->m_data << endl;
  }
}

/*
Name Of Function: getRoot

Description of Value Returned: Node that is the root of the SGT

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
TreeNode<T>* SGT<T>::getRoot(){
  return m_root;
}

/*
Name Of Function: getById

Description of Value Returned: T is the data retrieved by id

Description of Parameters: integer id is the id of the record we wanna find

Description of exceptions thrown:

*/

template <typename T>
T SGT<T>::getById(int id){
  getByIdHelper(m_root, id);
  return found;
}

/*
Name Of Function: getByIdHelper()

Description of Value Returned:

Description of Parameters: Node subtreeroot being passed recursively, integer id for the id of the record we wanna find

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::getByIdHelper(TreeNode<T>* subTreeRoot, int id){
  if(subTreeRoot == NULL){
        found = NULL;
    }else if(id == subTreeRoot->getData()->getId()){
        found = subTreeRoot->getData();
    }else if(id < subTreeRoot->getData()->getId()){
        getByIdHelper(subTreeRoot->getLeft(), id);
    }else{
        getByIdHelper(subTreeRoot->getRight(), id);
    }
}

/*
Name Of Function: getByIdAndPrint()

Description of Value Returned:

Description of Parameters: integer id of the id we wanna find and print

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::getByIdAndPrint(int id){
  getByIdAndPrintHelper(m_root, id);
}

/*
Name Of Function: getByIdAndPrint()

Description of Value Returned: 

Description of Parameters: Node subtreeroot that is being passed recursively, integer id of the record we wanna find

Description of exceptions thrown:

*/

template <typename T>
TreeNode<T>* SGT<T>::getByIdAndPrintHelper(TreeNode<T>* subTreeRoot, int id){
  if(subTreeRoot == NULL){
        return NULL;
    }else if(id == subTreeRoot->getData()->getId()){
        cout << *subTreeRoot->getData() << endl;
        return subTreeRoot;
    }else if(id < subTreeRoot->getData()->getId()){
        getByIdAndPrintHelper(subTreeRoot->getLeft(), id);
    }else{
        getByIdAndPrintHelper(subTreeRoot->getRight(), id);
    }
}

/*
Name Of Function: idExists()

Description of Value Returned: boolean if the id exists

Description of Parameters: integer id of record we wanna find

Description of exceptions thrown:

*/

template <typename T>
bool SGT<T>::idExists(int id){
  if(id == -1){
    return false;
  }else if(id == m_root->getData()->getId()){
      return true;
  }else{
      idExistsHelper(m_root, id);
      return m_unique == 1;
  }
}

/*
Name Of Function: idExistsHelper()

Description of Value Returned:

Description of Parameters: Node subtreeroot being passed recursively, integer id of the record we wanna find

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::idExistsHelper(TreeNode<T>* subTreeRoot, int id){
    if(subTreeRoot == NULL){
        m_unique = false;
    }else if(subTreeRoot->getData()->getId() == id){
        m_unique = true;
    }else if(subTreeRoot->getData()->getId() > id){
        idExistsHelper(subTreeRoot->getLeft(), id);
    }else{
        idExistsHelper(subTreeRoot->getRight(), id);
    }
}

/*
Name Of Function: printInfo()

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::printInfo(){
    printInfoHelper(m_root);
}

/*
Name Of Function: printInfoHelper()

Description of Value Returned:

Description of Parameters: Node subtreeroot being passed recursively

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::printInfoHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
      printInfoHelper(subTreeRoot->getLeft());
      cout << *subTreeRoot->getData() << endl;
      printInfoHelper(subTreeRoot->getRight());
  }
}

/*
Name Of Function: outputInfo()

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::outputInfo(){
  outputInfoHelper(m_root);
}

/*
Name Of Function: outputInfoHelper()

Description of Value Returned:

Description of Parameters: Node subtreeroot being passed recursively

Description of exceptions thrown:

*/

template <typename T>
void SGT<T>::outputInfoHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    outputInfoHelper(subTreeRoot->getLeft());
    std::ofstream file;
    file.open("runLog.txt", std::ios_base::app);
    file << *subTreeRoot->getData() << endl;
    file.close();
    outputInfoHelper(subTreeRoot->getRight());
  }
}