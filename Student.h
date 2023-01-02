/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file defines the Student class. This is where all the information about
the students are as well as the getter and setter methods.

High Level Decisions Used:
N/A
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <ostream>

using namespace std;

class Student{
    public:
    Student();
    Student(int m_studentId, std::string m_name, std::string m_level, std::string m_major, double m_gpa, int m_advisorId);
    virtual ~Student();
    int getId();
    void setStudentId(int m_studentId);
    std::string getName();
    void setName(std::string m_name);
    std::string getLevel();
    void setLevel(std::string m_level);
    std::string getMajor();
    void setMajor(std::string m_major);
    double getGPA();
    void setGPA(double m_gpa);
    int getAdvisorId();
    void setAdvisorId(int m_advisorId);
    friend bool operator== (const Student& c1, const Student& c2);
    friend bool operator!= (const Student& c1, const Student& c2);
    friend bool operator< (const Student& c1, const Student& c2);
    friend bool operator<= (const Student& c1, const Student& c2);
    friend bool operator> (const Student& c1, const Student& c2);
    friend bool operator>= (const Student& c1, const Student& c2);
    friend ostream& operator<< (ostream& COUT, const Student& c1);
    private:
    int m_studentId;
    std::string m_name;
    std::string m_level;
    std::string m_major;
    double m_gpa;
    int m_advisorId;
};

#endif