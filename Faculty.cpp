/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file is the implementation for the Faculty class. In the faculty class we define 
all the attributes of a faculty member including name, level, and department. We also have all
the getter and setter methods

High Level Decisions Used:
Operator overloading
*/

#include "Faculty.h"

/*
Name Of Function: Faculty constructor

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

Faculty::Faculty(){
    m_facultyId = 0;
    m_name = "";
    m_level = "";
    m_department = "";
}

/*
Name Of Function: Faculty overloaded constructor

Description of Value Returned:

Description of Parameters: int m_facultyId, std::string m_name, std::string m_level, std::string m_department, DblList<int>* m_advisees which are the attributes all
faculty members need to store

Description of exceptions thrown:

*/

Faculty::Faculty(int m_facultyId, std::string m_name, std::string m_level, std::string m_department, DblList<int>* m_advisees){
    this->m_facultyId = m_facultyId;
    this->m_name = m_name;
    this->m_level = m_level;
    this->m_department = m_department;
    this->m_advisees = m_advisees;
}

/*
Name Of Function: Faculty destructor

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

Faculty::~Faculty(){
    if(m_advisees != NULL){
        delete m_advisees;
    }
}

/*
Name Of Function: getId()

Description of Value Returned: integer of the faculty members id

Description of Parameters:

Description of exceptions thrown:

*/

int Faculty::getId(){
    return m_facultyId;
}

/*
Name Of Function: setFacultyId()

Description of Value Returned:

Description of Parameters: integer m_facultyId which is the faculty id we will assign to the facutly member

Description of exceptions thrown:

*/

void Faculty::setFacultyId(int m_facultyId){
    this->m_facultyId = m_facultyId;
}

/*
Name Of Function: getName()

Description of Value Returned: string of the faculty members name

Description of Parameters:

Description of exceptions thrown:

*/

std::string Faculty::getName(){
    return m_name;
}

/*
Name Of Function: setName()

Description of Value Returned:

Description of Parameters: string m_name that will be the faculty members name

Description of exceptions thrown:

*/

void Faculty::setName(std::string m_name){
    this->m_name = m_name;
}

/*
Name Of Function: getLevel()

Description of Value Returned: string of the faculty members level

Description of Parameters:

Description of exceptions thrown:

*/

std::string Faculty::getLevel(){
    return m_level;
}

/*
Name Of Function: setLevel()

Description of Value Returned:

Description of Parameters: string m_level will be the faculty members level

Description of exceptions thrown:

*/

void Faculty::setLevel(std::string m_level){
    this->m_level = m_level;
}

/*
Name Of Function: getDepartment

Description of Value Returned: string of faculty members department

Description of Parameters:

Description of exceptions thrown:

*/

std::string Faculty::getDepartment(){
    return m_department;
}

/*
Name Of Function: setDepartment()

Description of Value Returned:

Description of Parameters: string m_department that will be the faculty members department

Description of exceptions thrown:

*/

void Faculty::setDepartment(std::string m_department){
    this->m_department = m_department;
}

/*
Name Of Function: getAdvisees

Description of Value Returned: a list of advisees that are ids of students

Description of Parameters:

Description of exceptions thrown:

*/

DblList<int>*& Faculty::getAdvisees(){
    return m_advisees;
}

/*
Name Of Function: addAdvisee()

Description of Value Returned:

Description of Parameters: integer id is the id added to the front of the list

Description of exceptions thrown:

*/

void Faculty::addAdvisee(int id){
    m_advisees->addFront(id);
}

/*
Name Of Function: removeAdvisee()

Description of Value Returned:

Description of Parameters: integer id is the id removed from the list

Description of exceptions thrown:

*/

void Faculty::removeAdvisee(int id){
    m_advisees->removeSpecific(id);
}

/*
Name Of Function: Operator overload methods

Description of Value Returned: overloaded values 

Description of Parameters: faculty members 1 and 2

Description of exceptions thrown:

*/

bool operator== (const Faculty& c1, const Faculty& c2){
    return c1.m_facultyId == c2.m_facultyId;
}

bool operator!= (const Faculty& c1, const Faculty& c2){
    return c1.m_facultyId != c2.m_facultyId;
}

bool operator< (const Faculty& c1, const Faculty& c2){
    return c1.m_facultyId < c2.m_facultyId;
}

bool operator<= (const Faculty& c1, const Faculty& c2){
    return c1.m_facultyId <= c2.m_facultyId;
}

bool operator> (const Faculty& c1, const Faculty& c2){
    return c1.m_facultyId > c2.m_facultyId;
}

bool operator>= (const Faculty& c1, const Faculty& c2){
    return c1.m_facultyId >= c2.m_facultyId;
    
}

/*
Name Of Function: COUT operator overloading

Description of Value Returned:

Description of Parameters: COUT and faculty c1 that will be overloaded

Description of exceptions thrown:

*/

ostream& operator<<(ostream& COUT, const Faculty& c1){
    COUT << "----- Faculty Information -----" << endl;
    COUT << "Faculty Name: ";
    COUT << c1.m_name << endl;
    COUT << "Faculty ID: ";
    COUT << c1.m_facultyId << endl;
    COUT << "Faculty Level: ";
    COUT << c1.m_level << endl;
    COUT << "Faculty Department: ";
    COUT << c1.m_department << endl;
    COUT << "Faculty's Advisees Id's: " << endl;
    c1.m_advisees->print();
    COUT << "-------------------------------" << endl;
    return COUT;
}