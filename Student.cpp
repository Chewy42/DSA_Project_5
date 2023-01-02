/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file is the implementation for the Student class. In the student class we define 
all the attributes of a student including name, level, and major. We also have all
the getter and setter methods

High Level Decisions Used:
Operator overloading
*/


#include "Student.h"

/*
Name Of Function: Student constructor

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

Student::Student(){
    m_studentId = 0;
    m_name = "";
    m_level = "";
    m_major = "";
    m_gpa = 0.0;
    m_advisorId = 0;
}

/*
Name Of Function: Student overloaded constructor

Description of Value Returned:

Description of Parameters: int m_studentId, std::string m_name, std::string m_level, std::string m_major, double m_gpa, int m_advisorId are the
attributes a student record will need in our database

Description of exceptions thrown:

*/

Student::Student(int m_studentId, std::string m_name, std::string m_level, std::string m_major, double m_gpa, int m_advisorId){
    this->m_studentId = m_studentId;
    this->m_name = m_name;
    this->m_level = m_level;
    this->m_major = m_major;
    this->m_gpa = m_gpa;
    this->m_advisorId = m_advisorId;
}

/*
Name Of Function: Student destructor

Description of Value Returned:

Description of Parameters: 

Description of exceptions thrown:

*/

Student::~Student(){

}

/*
Name Of Function: getId()

Description of Value Returned: integer of record id

Description of Parameters: 

Description of exceptions thrown:

*/

int Student::getId(){
    return m_studentId;
}

/*
Name Of Function: setStudentId

Description of Value Returned:

Description of Parameters: integer id that will update record

Description of exceptions thrown:

*/

void Student::setStudentId(int m_studentId){
    this->m_studentId = m_studentId;
}

/*
Name Of Function: getName()

Description of Value Returned: string of record name

Description of Parameters: 

Description of exceptions thrown:

*/

std::string Student::getName(){
    return m_name;
}

/*
Name Of Function: setName

Description of Value Returned:

Description of Parameters: string name that will update the record

Description of exceptions thrown:

*/

void Student::setName(std::string m_name){
    this->m_name = m_name;
}

/*
Name Of Function: getLevel()

Description of Value Returned: string of records level

Description of Parameters: 

Description of exceptions thrown:

*/

std::string Student::getLevel(){
    return m_level;
}

/*
Name Of Function: setLevel

Description of Value Returned:

Description of Parameters: string level that will update the records level

Description of exceptions thrown:

*/

void Student::setLevel(std::string m_level){
    this->m_level = m_level;
}

/*
Name Of Function: getMajor()

Description of Value Returned: string of records major

Description of Parameters: 

Description of exceptions thrown:

*/

std::string Student::getMajor(){
    return m_major;
}

/*
Name Of Function: setMajor()

Description of Value Returned:

Description of Parameters: string major that will be the records updated major

Description of exceptions thrown:

*/

void Student::setMajor(std::string m_major){
    this->m_major = m_major;
}

/*
Name Of Function: getGPA()

Description of Value Returned: double gpa that is the records gpa

Description of Parameters: 

Description of exceptions thrown:

*/

double Student::getGPA(){
    return m_gpa;
}

/*
Name Of Function: setGPA()

Description of Value Returned:

Description of Parameters: double GPA that will update the GPA record

Description of exceptions thrown:

*/

void Student::setGPA(double m_gpa){
    this->m_gpa = m_gpa;
}

/*
Name Of Function: getAdvisorId()

Description of Value Returned: integer of records advisor id

Description of Parameters: 

Description of exceptions thrown:

*/

int Student::getAdvisorId(){
    return m_advisorId;
}

/*
Name Of Function: setAdvisorId()

Description of Value Returned:

Description of Parameters: integer advisor id that will update record

Description of exceptions thrown:

*/

void Student::setAdvisorId(int m_advisorId){
    this->m_advisorId = m_advisorId;
}

/*
Name Of Function: Operator overloading

Description of Value Returned: overloaded values

Description of Parameters: student 1 and 2 

Description of exceptions thrown:

*/

bool operator== (const Student& c1, const Student& c2){
    return c1.m_studentId == c2.m_studentId;
}

bool operator!= (const Student& c1, const Student& c2){
    return c1.m_studentId != c2.m_studentId;
}

bool operator< (const Student& c1, const Student& c2){
    return c1.m_studentId < c2.m_studentId;
}

bool operator<= (const Student& c1, const Student& c2){
    return c1.m_studentId <= c2.m_studentId;
}

bool operator> (const Student& c1, const Student& c2){
    return c1.m_studentId > c2.m_studentId;
}

bool operator>= (const Student& c1, const Student& c2){
    return c1.m_studentId >= c2.m_studentId;
}

ostream& operator<<(ostream& COUT, const Student& c1){
    COUT << "----- Student Information -----" << endl;
    COUT << "Student Name: ";
    COUT << c1.m_name << endl;
    COUT << "Student ID: ";
    COUT << c1.m_studentId << endl;
    COUT << "Student Level: ";
    COUT << c1.m_level << endl;
    COUT << "Student Major: ";
    COUT << c1.m_major << endl;
    COUT << "Student GPA: ";
    COUT << c1.m_gpa << endl;
    COUT << "Student's Faculty Advisor ID: ";
    COUT << c1.m_advisorId << endl;
    COUT << "-------------------------------" << endl;
    return COUT;
}