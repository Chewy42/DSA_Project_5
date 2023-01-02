/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file defines the DB (database) class

High Level Decisions Used:
N/A
*/

#ifndef DB_H
#define DB_H

#include "SGT.cpp"
#include "Student.h"
#include "Faculty.h"
#include "TreeNode.h"
#include "DblList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DB{
    public:
    DB();
    virtual ~DB();
    void MainLoop();
    private:
    SGT<Student*>* StudentRecords;
    SGT<Faculty*>* FacultyRecords;
    void showMenu();
    void printStudentInfo();
    void printStudentInfoHelper(TreeNode<Student*>* subTreeRoot);
    void printFacultyInfo();
    void printFacultyInfoHelper(TreeNode<Faculty*>* subTreeRoot);
};

#endif