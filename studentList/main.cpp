// main.cpp
// Author: Christian Schaf
// Program #3 due date: 10/11/2016
//
// All rights and lefts reserved.
//
#include <iostream>
#include "student.h"
#include "studentList.h"

void handleMainMenuInput(int result, StudentList &sList)
{
    switch (result) {
    case 1:
        sList.displayByOriginalValues();
        break;
    case 2:
        sList.displayByStudentId();
        break;
    case 3:
        sList.displayByAge();
        break;
    case 4:
        sList.displayByName();
        break;
    case 5:
        sList.displayByGrade();
        break;
    case 6:
        sList.displayByHomeTown();
        break;
    case 7:
        cout << "Goodbye!" << endl;
        exit(0);
        break;
    default:
        break;
    }
}

int displayMainMenu(StudentList &sList)
{
    int result;
    bool resultIsInt = false;
    cout << "\n1) Display original list" << endl;
    cout << "2) Display list sorted by Student ID" << endl;
    cout << "3) Display list sorted by Student Age" << endl;
    cout << "4) Display list sorted by Name" << endl;
    cout << "5) Display list sorted by Grade" << endl;
    cout << "6) Display list sorted by Home Town" << endl;
    cout << "7) Exit\n" << endl;
    cout << "Choose menu option (1-7): " << endl;

    while(!resultIsInt){
        resultIsInt = true;
        cin >> result;

        if(cin.fail() || result > 7){
            cin.clear();
            cin.ignore();
            cout << "Please enter an Integer (1-7) only: " << endl;
            resultIsInt = false;
        }
    }
    handleMainMenuInput(result, sList);
    return result;
}



int main()
{
    StudentList students;

    int result = displayMainMenu(students);
    while(result < 7){
        result = displayMainMenu(students);
    }
    return 0;
}
