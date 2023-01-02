Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA5

Source Files:
* main.cpp
* DB.cpp
* DB.h
* SGT.cpp
* SGT.h
* Student.cpp
* Student.h
* Faculty.cpp
* Faculty.h
* TreeNode.cpp
* TreeNode.h
* ListNode.cpp
* ListNode.h
* DblList.cpp
* DblList.h
* README.md
* app -- compiled file

Compile Errors: None

Deviations From Assignment: None

Known Issues: Outside of docker, when creating a new student and typing a string
instead of an integer the error message works fine. But inside docker, the error message
seems to bug out and keep printing.

Background info before running: I have preloaded some students and faculty members for an
easier grading process in the DB class at the start of MainLoop() (Line 76). Comment it out
if you would not like to use the preloaded student and faculty members.

Compile Command: g++ *.cpp -o app

To Run: ./app

References:
- Old Projects
- https://www.cs.umd.edu/class/fall2020/cmsc420-0201/Lects/lect12-scapegoat.pdf
- https://www.youtube.com/watch?v=PjLkqHSs6pY
- https://www.geeksforgeeks.org/find-the-maximum-depth-or-height-of-a-tree/
- https://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/
- https://www.geeksforgeeks.org/scapegoat-tree-set-1-introduction-insertion/
- https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/
- https://www.w3schools.com/cpp/cpp_switch.asp
- https://www.sololearn.com/discuss/555234/how-to-check-if-the-input-is-an-integer-in-c