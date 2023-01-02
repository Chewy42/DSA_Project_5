/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file is the implementation for the Faculty class. In the student class we define 
all the attributes of a faculty member including name, level, and department. We also have all
the getter and setter methods

High Level Decisions Used:
Operator overloading
*/

#ifndef FACULTY_H
#define FACULTY_H

#include "DblList.cpp"
#include <string>
#include <ostream>

using namespace std;

class Faculty{
    public:
    Faculty();
    Faculty(int m_facultyId, std::string m_name, std::string m_level, std::string m_department, DblList<int>* m_advisees);
    virtual ~Faculty();
    int getId();
    void setFacultyId(int m_facultyId);
    std::string getName();
    void setName(std::string m_name);
    std::string getLevel();
    void setLevel(std::string m_level);
    std::string getDepartment();
    void setDepartment(std::string m_department);
    DblList<int>*& getAdvisees();
    void addAdvisee(int id);
    void removeAdvisee(int id);
    friend bool operator== (const Faculty& c1, const Faculty& c2);
    friend bool operator!= (const Faculty& c1, const Faculty& c2);
    friend bool operator< (const Faculty& c1, const Faculty& c2);
    friend bool operator<= (const Faculty& c1, const Faculty& c2);
    friend bool operator> (const Faculty& c1, const Faculty& c2);
    friend bool operator>= (const Faculty& c1, const Faculty& c2);
    friend ostream& operator<< (ostream& COUT, const Faculty& c1);
    private:
    int m_facultyId;
    std::string m_name;
    std::string m_level;
    std::string m_department;
    DblList<int>* m_advisees;
};

#endif