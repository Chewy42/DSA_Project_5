/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Brief Overview:
This file is the main code for the entire database. It includes all types of error checks and carries out 
all the methods that will be needed for this database.

High Level Decisions Used:
Using OOP to not have to have multiple of the same code for both student and faculty records, then using it
to simulate a database.
*/

#include "DB.h"
#include "Faculty.h"
#include "Student.h"
#include "DblList.h"
#include <iostream>
#include <string>

using namespace std;

/*
Name Of Function: DB constructor

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

DB::DB(){
    StudentRecords = new SGT<Student*>();
    FacultyRecords = new SGT<Faculty*>();
}

/*
Name Of Function: DB destructor

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

DB::~DB(){
    if(StudentRecords != NULL){
        delete StudentRecords;
    }
    if(FacultyRecords != NULL){
        delete FacultyRecords;
    }
}

/*
Name Of Function: MainLoop

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

void DB::MainLoop(){

    // PRELOADED STUDENTS AND FACULTY MEMBERS
    DblList<int>* preloadFaculty1Advisees = new DblList<int>();
    preloadFaculty1Advisees->addFront(1);
    preloadFaculty1Advisees->addFront(2);
    DblList<int>* preloadFaculty2Advisees = new DblList<int>();
    preloadFaculty2Advisees->addFront(3);
    preloadFaculty2Advisees->addFront(4);
    Faculty* preloadFaculty1 = new Faculty(1, "Erik Linstead", "Coding God", "Fowler School Of Engineering", preloadFaculty1Advisees);
    Faculty* preloadFaculty2 = new Faculty(2, "Elizabeth Stevens", "Coding Goddess", "Fowler School Of Engineering", preloadFaculty2Advisees);
    Student* preloadStudent1 = new Student(1, "Matt Favela", "Sophomore", "Data Science", 4.0, 1);
    Student* preloadStudent2 = new Student(2, "John Appleseed", "Senior", "Computer Science", 3.75, 1);
    Student* preloadStudent3 = new Student(3, "Adam James", "Freshman", "Data Science", 2.0, 2);
    Student* preloadStudent4 = new Student(4, "Chris Ton", "Sophomore", "Electrical Engineering", 3.5, 2);
    FacultyRecords->insert(preloadFaculty1);
    FacultyRecords->insert(preloadFaculty2);
    StudentRecords->insert(preloadStudent1);
    StudentRecords->insert(preloadStudent3);
    StudentRecords->insert(preloadStudent2);
    StudentRecords->insert(preloadStudent4);

    bool dbOpen = true;

    std::ofstream file;
    file.open("runLog.txt", std::ios_base::out);
    file << "";
    file.close();

    while(dbOpen){
        int choice;
        showMenu();
        while(!(cin >> choice)){ // These while loops check if the input is an integer, and keeps asking for input if it is not
            cout << "Ooops! Non integer value entered! Try again please. " << endl;
            cin.clear();
            cin.ignore(40,'\n');
        }
        switch(choice){
            case 1:
                StudentRecords->printInfo();
                break;
            case 2:
                FacultyRecords->printInfo();
                break;
            case 3:
            {
                int sId;
                cout << "-- FIND STUDENT BY ID --" << endl;
                cout << "Please enter a students id: ";
                while(!(cin >> sId) || !StudentRecords->idExists(sId)){ // Essentially saying while either the input is not an integer OR student id does not exist, then...
                    if(sId == -1){
                        break;
                    }
                    cout << "Ooops! Non integer value entered OR id does not exist! Try again please or type -1 to exit. " << endl;
                    cin.clear();
                }
                if(sId != -1){
                    cout << endl;
                    StudentRecords->getByIdAndPrint(sId); // Gets by id and prints
                }
                break;
            }
            case 4:
            {
                int facultyId;
                cout << "-- FIND FACULTY MEMBER BY ID --" << endl;
                cout << "Please enter a faculty member's id: ";
                while(!(cin >> facultyId) || !FacultyRecords->idExists(facultyId)){
                    if(facultyId == -1){
                        break;
                    }
                    cout << "Ooops! Non integer value entered OR id does not exist! Try again please or type -1 to exit. " << endl;
                    cin.clear();
                }
                if(facultyId != -1){
                    cout << endl;
                    FacultyRecords->getByIdAndPrint(facultyId);
                }
                break;
            }
            case 5:
            {
                if(FacultyRecords->getSize() == 0){ // Makes sure there is a faculty member before adding any students, so a student can have an advisor
                    cout << "Please add a faculty member before adding a student. Current faculty size is 0." << endl;
                }else{
                    int newStudentId;
                    std::string newStudentName, newStudentLevel, newStudentMajor;
                    double newStudentGPA;
                    int newStudentAdvisorId;
                    cout << "-- ADD STUDENT --" << endl;
                    cout << "Please enter a new students unique id number: ";
                    while(!(cin >> newStudentId) || StudentRecords->idExists(newStudentId)){ // Keeps asking if a student id already exists
                        if(newStudentId == -1){
                            break;
                        }
                        cout << "Ooops! Non integer value entered OR id already exists! Try again please or type -1 to cancel. " << endl;
                        cin.clear();
                        cin.ignore(40,'\n');
                    }
                    if(newStudentId == -1){
                        break;
                    }
                    cout << endl;
                    cout << "Please enter the new students name: ";
                    getline(cin.ignore(1, '\n'), newStudentName); // Get line methods for strings
                    cout << endl;
                    cout << "Please enter the new students school standing: ";
                    getline(cin, newStudentLevel);
                    cout << endl;
                    cout << "Please enter the new students major: ";
                    getline(cin, newStudentMajor);
                    cout << endl;
                    cout << "Please enter the new students gpa: ";
                    while(!(cin >> newStudentGPA)){
                        cout << "Ooops! Non decimal value entered! Try again please. " << endl;
                        cin.clear();
                        cin.ignore(40,'\n');
                    }
                    cout << endl;
                    cout << "Please enter the new students advisors id number or type -1 to cancel: ";
                    while(!(cin >> newStudentAdvisorId) || !FacultyRecords->idExists(newStudentAdvisorId)){
                        if(newStudentAdvisorId == -1){
                            break;
                        }
                        cout << "Ooops! Non integer value entered or Faculty ID does not exist! Try again please. " << endl;
                        cin.clear();
                        cin.ignore(40,'\n');
                    }
                    if(newStudentAdvisorId == -1){
                            break;
                    }
                    cout << endl;
                    /*
                    1. Get faculty by id
                    2. Add advisee to faculty
                    3. Create new student
                    4. Insert into student records database
                    */

                    FacultyRecords->getById(newStudentAdvisorId)->addAdvisee(newStudentId);
                    Student* stud = new Student(newStudentId, newStudentName, newStudentLevel, newStudentMajor, newStudentGPA, newStudentAdvisorId);
                    StudentRecords->insert(stud);
                    cout << "Student successfully added to database." << endl;   
                }
                break;
            }
            case 6:
            {
                int deleteStudentId;
                cout << "-- DELETE STUDENT --" << endl;
                cout << "Please enter the id of the student you would like to delete or -1 to exit: ";
                while(!(cin >> deleteStudentId) || !StudentRecords->idExists(deleteStudentId)){
                    if(deleteStudentId == -1){
                        break;
                    }
                    cout << "Ooops! Non integer value entered or Student ID does not exist! Try again please or type -1 to cancel. " << endl;
                    cin.clear();
                    cin.ignore(40,'\n');
                }
                if(deleteStudentId != -1){
                    /*
                    1. Get the student to delete's advisor id
                    2. Make sure that advisor actually contains that student as their advisee
                        2.5 If so remove advisee from list
                    3. Delete student from student records
                    */
                    int advisorId = StudentRecords->getById(deleteStudentId)->getAdvisorId();
                    if(FacultyRecords->getById(advisorId)->getAdvisees()->contains(deleteStudentId)){ 
                        FacultyRecords->getById(advisorId)->getAdvisees()->removeSpecific(deleteStudentId);
                    }
                    StudentRecords->remove(StudentRecords->getById(deleteStudentId));
                }
                break;
            }
            case 7:
            {
                int newFacultyId;
                std::string newFacultyName, newFacultyLevel, newFacultyDepartment;
                DblList<int>* newFacultyAdvisees = new DblList<int>();
                cout << "-- ADD FACULTY MEMBER --" << endl;
                cout << "Please enter a new faculty members unique id number: ";
                while(!(cin >> newFacultyId) || FacultyRecords->idExists(newFacultyId)){
                    cout << "Ooops! Non integer value entered OR id already exists! Try again please. " << endl;
                    cin.clear();
                    cin.ignore(40,'\n');
                }
                cout << endl;
                cout << "Please enter the new faculty member's name: ";
                getline(cin.ignore(1, '\n'), newFacultyName);
                cout << endl;
                cout << "Please enter the new faculty member's level: ";
                getline(cin.ignore(1, '\n'), newFacultyLevel);
                cout << endl;
                cout << "Please enter the new faculty member's department: ";
                getline(cin.ignore(1, '\n'), newFacultyDepartment);
                cout << endl;
                bool isDoneAddingAdvisees = false;
                while(isDoneAddingAdvisees == false){
                    cout << "Please enter the id number of a advisee for this faculty member or type -1 to stop: ";
                    int temp;
                    while(!(cin >> temp) || !StudentRecords->idExists(temp)){
                        if(temp == -1){
                            break;
                        }
                        cout << "Ooops! Non integer value entered OR id does not exist! Try again please or type -1 to exit. " << endl;
                        cin.clear();
                        cin.ignore(40,'\n');
                    }
                    if(temp == -1){
                        isDoneAddingAdvisees = true;
                        break;
                    }
                    cout << "You are attempting to override student: " << StudentRecords->getById(temp)->getName(); // List out the student that is being overriden for confirmation
                    cout << " with ID number: " << temp << endl;
                    cout << "Please type 1 to confirm and -1 to cancel: ";
                    int confirm;
                    while(!(cin >> confirm)){
                        cout << "Ooops! Non integer value entered! Try again please. " << endl;
                        cin.clear();
                        cin.ignore(40,'\n');
                    }
                    if(confirm == 1){
                        /*
                        1. Get student to override's current factuly advisor by id and remove the student from their list
                        2. Set the student to override's advisor id to the new advisor's id
                        3. Add the student's id to the new advisor's advisee's list
                        */
                        FacultyRecords->getById(StudentRecords->getById(temp)->getAdvisorId())->removeAdvisee(temp);
                        StudentRecords->getById(temp)->setAdvisorId(newFacultyId);
                        newFacultyAdvisees->addFront(temp);
                    }else{
                        continue;
                    }
                    cout << endl;
                }
                /// Create faculty member and insert into faculty records
                Faculty* fac = new Faculty(newFacultyId, newFacultyName, newFacultyLevel, newFacultyDepartment, newFacultyAdvisees);
                FacultyRecords->insert(fac);
                cout << "Faculty member successfully added to database." << endl;
                break;
            }
            case 8:
            {
                int deleteFacultyId;
                cout << "-- DELETE FACULTY MEMBER --" << endl;
                cout << "Please enter the id of the faculty member you would like to delete or type -1 to exit: ";
                while(!(cin >> deleteFacultyId) || !FacultyRecords->idExists(deleteFacultyId)){
                    if(deleteFacultyId == -1){
                        break;
                    }
                    cout << "Ooops! Non integer value entered OR id does not exist! Try again please or type -1 to exit. " << endl;
                    cin.clear();
                    cin.ignore(40,'\n');
                }
                if(deleteFacultyId == -1){
                    break;
                }else if(FacultyRecords->getById(deleteFacultyId)->getAdvisees()->getSize() == 0){
                    
                    FacultyRecords->remove(FacultyRecords->getById(deleteFacultyId));
                    cout << "Successfully removed faculty member" << endl;
                }else{
                    // VERY IMPORTANT! Here we transfer the advisees to a new faculty member if the faculty
                    // member we are deleting has any
                    cout << "You are attempting to remove a faculty member ";
                    cout << "that has advisees, please enter a new faculty member ";
                    cout << "id to transfer advisees or type -1 to cancel: ";
                    int newDeleteFacultyId;
                    while(!(cin >> newDeleteFacultyId) || !FacultyRecords->idExists(newDeleteFacultyId)){
                        if(newDeleteFacultyId == -1){
                            break;
                        }
                        cout << "Ooops! Non integer value entered OR id does not exist! Try again please or type -1 to cancel. " << endl;
                        cin.clear();
                        cin.ignore(40,'\n');
                    }
                        if(newDeleteFacultyId != -1){
                            while(FacultyRecords->getById(deleteFacultyId)->getAdvisees()->getSize() != 0){
                                FacultyRecords->getById(newDeleteFacultyId)->addAdvisee(FacultyRecords->getById(deleteFacultyId)->getAdvisees()->removeFront());
                            }
                            FacultyRecords->remove(FacultyRecords->getById(deleteFacultyId));
                        }
                }
                break;
            }
            case 9:
            {
                int studentsId;
                int advisorsId;
                cout << "--  CHANGE STUDENTS ADVISOR --" << endl;
                cout << "Please type the student id of the student that will be updated: ";
                while(!(cin >> studentsId) || !StudentRecords->idExists(studentsId)){
                    if(studentsId == -1){
                        break;
                    }
                    cout << "Ooops! Non integer value entered OR id does not exist! Try again please or type -1 to cancel. " << endl;
                    cin.clear();
                    cin.ignore(40,'\n');
                }
                if(studentsId == -1){
                    break;
                }
                cout << endl;
                cout << "Please type the faculty members id that will be the new students advisor: ";
                while(!(cin >> advisorsId) || !FacultyRecords->idExists(advisorsId)){
                    if(advisorsId == -1){
                        break;
                    }
                    cout << "Ooops! Non integer value entered OR id does not exist! Try again please or type -1 to cancel. " << endl;
                    cin.clear();
                    cin.ignore(40,'\n');
                }
                if(advisorsId == -1){
                    break;
                }
                cout << endl;
                /*
                1, Remove student from their current faculty advisors list
                2. Set the student's advisor to the new advisors id
                3. Add the student to the new faculty members advisee list
                */
                FacultyRecords->getById(StudentRecords->getById(studentsId)->getAdvisorId())->removeAdvisee(studentsId);
                StudentRecords->getById(studentsId)->setAdvisorId(advisorsId);
                FacultyRecords->getById(advisorsId)->addAdvisee(studentsId);
                cout << "Successfully updated students advisor." << endl;
                break;
            }
            case 10:
            {
                if(FacultyRecords->getSize() > 1){
                    int facultyToEdit;
                    int adviseeToRemove;
                    int newFaculty;
                    cout << "-- REMOVE ADVISEE FROM FACULTY --" << endl;
                    cout << "Please enter the id of the faculty member you would like to edit: ";
                    while(!(cin >> facultyToEdit) || !FacultyRecords->idExists(facultyToEdit)){
                        if(facultyToEdit == -1){
                            break;
                        }
                        cout << "Ooops! Non integer value entered OR id does not exist! Try again please or type -1 to cancel. " << endl;
                        cin.clear();
                        cin.ignore(40,'\n');
                    }
                    if(facultyToEdit == -1){
                            break;
                        }
                    cout << endl;
                    cout << "Please enter the id of the advisee you would like to remove: ";
                    while(!(cin >> adviseeToRemove) || !StudentRecords->idExists(adviseeToRemove) || !FacultyRecords->getById(facultyToEdit)->getAdvisees()->contains(adviseeToRemove)){
                        if(adviseeToRemove == -1){
                            break;
                        }
                        cout << "Ooops! Non integer value entered OR id does not exist! Try again please or type -1 to cancel. " << endl;
                        cin.clear();
                        cin.ignore(40,'\n');
                    }
                    if(adviseeToRemove == -1){
                            break;
                        }
                    cout << endl;
                    cout << "Please enter the id of the new faculty member you would like to assign to the advisee: ";
                    while(!(cin >> newFaculty) || !FacultyRecords->idExists(newFaculty)){
                        if(newFaculty == -1){
                            break;
                        }
                        cout << "Ooops! Non integer value entered OR id does not exist OR id already entered! Try again please or type -1 to cancle. " << endl;
                        cin.clear();
                        cin.ignore(40,'\n');
                    }
                    if(newFaculty == -1){
                            break;
                        }
                    cout << endl;
                    /*
                    1. Set students advisor to new advisors id
                    2. Add student to new advisors advisee list
                    3. Remove student from old advisees list
                    */
                    StudentRecords->getById(adviseeToRemove)->setAdvisorId(newFaculty);
                    FacultyRecords->getById(newFaculty)->addAdvisee(adviseeToRemove);
                    FacultyRecords->getById(facultyToEdit)->getAdvisees()->removeSpecific(adviseeToRemove);
                    cout << "Successfully removed advisee from faculty member" << endl;
                }else{
                    cout << "Sorry that action is not possible with only 1 faculty member." << endl;
                }
                break;
            }
            case 11:
            {
                // close db
                StudentRecords->outputInfo();
                FacultyRecords->outputInfo();
                cout << "-- DB CLOSING, GOODBYE --" << endl;
                dbOpen = false;
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

/*
Name Of Function: showMenu()

Description of Value Returned:

Description of Parameters:

Description of exceptions thrown:

*/

void DB::showMenu(){
    cout << "University Database" << endl;
    cout << "(1) Print all students and their information (sorted by ascending id #)" << endl;
    cout << "(2) Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "(3) Find and display student information given the students id" << endl;
    cout << "(4) Find and display faculty information given the faculty id" << endl;
    cout << "(5) Add a new student" << endl;
    cout << "(6) Delete a student given the id" << endl;
    cout << "(7) Add a new faculty member" << endl;
    cout << "(8) Delete a faculty member given the id." << endl;
    cout << "(9) Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "(10) Remove an advisee from a faculty member given the ids" << endl;
    cout << "(11) Exit" << endl;
    cout << "Please enter the EXACT number of the action you would like to take: " << endl;
}