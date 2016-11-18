// studentlist.cpp
// Author: Christian Schaf
// Program #3 due date: 10/11/2016
//
// All rights and lefts reserved.
//
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstring>

#include "studentlist.h"
using namespace std;

StudentList::StudentList()
{
    srand ( (unsigned) time(NULL) );
    createStudents(cecs282);

    for (int i = 0; i < 10; ++i) {
        idPtr[i] = &cecs282[i];
        namePtr[i] = &cecs282[i];
        gradePtr[i] = &cecs282[i];
        birthdayPtr[i] = &cecs282[i];
        homeTownPtr[i] = &cecs282[i];
    };
    bubbleSortById(idPtr, 10);
    bubbleSortByName(namePtr, 10);
    bubbleSortByAge(birthdayPtr, 10);
    bubbleSortByGrade(gradePtr, 10);
    bubbleSortByHomeTown(homeTownPtr, 10);


}

void StudentList::createStudents(Student students[]){
    char sNames[10][11] = {"Peter P.", "Dieter S.", "Steffen A.", "Allen B.", "Steve C.", "Daniel K.", "Chris S.", "Bastian I.", "Leon U.", "Rene N."};
    string sHomeTowns[10] = {"Berlin", "Long Beach", "Compton", "Hamburg", "Los Angeles", "Bremen", "Madrid", "Rom", "Paris", "Bikini Bottom"};
    int ids[10];
    createIds(ids);
    for (int i = 0; i < 10; i++) {
        students[i].id = ids[i];
        strcpy(students[i].name, sNames[i]);
        students[i].bDay = createRandomBirthday();
        students[i].grade = createRandomGrade();
        students[i].homeTown = sHomeTowns[i];
    };
}

bool StudentList::contains(int ids[], int value){
    for(int i = 0; i < 10; i++){
         if(ids[i] == value){
             return true;
         }
    }
    return false;
}

void StudentList::createIds(int ids[]){
    for (int i = 0; i < 10; ++i) {
        int randomNumber = 1000 + ( rand() % ( 9999 - 1000 + 1 ) );
        while(contains(ids, randomNumber)){
            randomNumber = 1000 + ( rand() % ( 9999 - 1000 + 1 ) );
        };
        ids[i]= randomNumber;
    };
}

MyDate StudentList::createRandomBirthday(){
    int year;
    int month;
    int day;
    int j1 = MyDate::jD(1994, 1, 1);
    int j2 = MyDate::jD(1998,12, 31);
    int randomJd = j1 + ( rand() % ( j2 - j1 + 1 ) );
    MyDate::gDate(randomJd, year, month, day);
    MyDate result = MyDate(month, day, year);

    return result;
}

char StudentList::createRandomGrade(){
    char const grades[6] = "ABCDF";
    return grades[rand() % 4];
}

void StudentList::displayByHomeTown(){

    cout << left << setw(20) << "Student ID" << setw(20) << "Name" << setw(30) << "Birthday" << setw(20) << "Grade" << setw(20) << "Home Town" << endl;
    cout << left << setw(20) << "----------" << setw(20) << "----" << setw(30) << "--------" << setw(20) << "-----" << setw(20) << "---------" << endl;
    for (int j = 0; j < 10; ++j) {
        cout << left << setw(20)<< homeTownPtr[j]->id << setw(20) << homeTownPtr[j]->name << setw(30) << homeTownPtr[j]->bDay.getValue()<< setw(20)<< homeTownPtr[j]->grade << setw(20) << homeTownPtr[j]->homeTown << endl;
    }
}

void StudentList::displayByGrade(){

    cout << left << setw(20) << "Student ID" << setw(20) << "Name" << setw(30) << "Birthday" << setw(20) << "Grade" << setw(20) << "Home Town" << endl;
    cout << left << setw(20) << "----------" << setw(20) << "----" << setw(30) << "--------" << setw(20) << "-----" << setw(20) << "---------" << endl;
    for (int j = 0; j < 10; ++j) {
        cout << left << setw(20)<< gradePtr[j]->id << setw(20) << gradePtr[j]->name << setw(30) << gradePtr[j]->bDay.getValue()<< setw(20)<< gradePtr[j]->grade << setw(20) << gradePtr[j]->homeTown << endl;
    }
}

void StudentList::displayByAge(){

    cout << left << setw(20) << "Student ID" << setw(20) << "Name" << setw(30) << "Birthday" << setw(20) << "Grade" << setw(20) << "Home Town" << endl;
    cout << left << setw(20) << "----------" << setw(20) << "----" << setw(30) << "--------" << setw(20) << "-----" << setw(20) << "---------" << endl;
    for (int j = 0; j < 10; ++j) {
        cout << left << setw(20)<< birthdayPtr[j]->id << setw(20) << birthdayPtr[j]->name << setw(30) << birthdayPtr[j]->bDay.getValue()<< setw(20)<< birthdayPtr[j]->grade << setw(20) << birthdayPtr[j]->homeTown << endl;
    }
}

void StudentList::displayByName(){

    cout << left << setw(20) << "Student ID" << setw(20) << "Name" << setw(30) << "Birthday" << setw(20) << "Grade" << setw(20) << "Home Town" << endl;
    cout << left << setw(20) << "----------" << setw(20) << "----" << setw(30) << "--------" << setw(20) << "-----" << setw(20) << "---------" << endl;
    for (int j = 0; j < 10; ++j) {
        cout << left << setw(20)<< namePtr[j]->id << setw(20) << namePtr[j]->name << setw(30) << namePtr[j]->bDay.getValue()<< setw(20)<< namePtr[j]->grade << setw(20) << namePtr[j]->homeTown << endl;
    }
}

void StudentList::displayByStudentId(){

    cout << left << setw(20) << "Student ID" << setw(20) << "Name" << setw(30) << "Birthday" << setw(20) << "Grade" << setw(20) << "Home Town" << endl;
    cout << left << setw(20) << "----------" << setw(20) << "----" << setw(30) << "--------" << setw(20) << "-----" << setw(20) << "---------" << endl;
    for (int j = 0; j < 10; ++j) {
        cout << left << setw(20)<< idPtr[j]->id << setw(20) << idPtr[j]->name << setw(30) << idPtr[j]->bDay.getValue()<< setw(20)<< idPtr[j]->grade << setw(20) << idPtr[j]->homeTown << endl;
    }
}

void StudentList::displayByOriginalValues(){

    cout << left << setw(20) << "Student ID" << setw(20) << "Name" << setw(30) << "Birthday" << setw(20) << "Grade" << setw(20) << "Home Town" << endl;
    cout << left << setw(20) << "----------" << setw(20) << "----" << setw(30) << "--------" << setw(20) << "-----" << setw(20) << "---------" << endl;
    for (int j = 0; j < 10; ++j) {
        cout << left << setw(20)<< cecs282[j].id << setw(20) << cecs282[j].name << setw(30) << cecs282[j].bDay.getValue()<< setw(20)<< cecs282[j].grade << setw(20) << cecs282[j].homeTown << endl;
    }
}

void StudentList::swap(Student **x, Student **y){
    Student *temp = *x;
    *x = *y;
    *y = temp;
}

void StudentList::bubbleSortById( Student *values[10], int lenght )
{
  int i, j; // counter variables

  // interate over the while array beginning at the 1st element
  for( i = 0; i < lenght; i++ )
  {
    // interate over the while array beginning at the last element, looking for the lowest item

    for( j = lenght - 1; j > i; j-- )
    {
      // checks if element is smaller as the previous one
      if( values[j]->id < values[j - 1]->id )
      {
        // swap references
        this->swap(&values[j], &values[j-1]);
      }
    }
  }
}

void StudentList::bubbleSortByName( Student *values[10], int lenght )
{
  int i, j;

  for( i = 0; i < lenght; i++ )
  {
    for( j = lenght - 1; j > i; j-- )
    {
      if( strcmp (values[j]->name, values[j-1]->name) < 0)
      {
        this->swap(&values[j], &values[j-1]);
      }
    }
  }
}

void StudentList::bubbleSortByAge( Student *values[10], int lenght )
{
  int i, j;

  for( i = 0; i < lenght; i++ )
  {
    for( j = lenght - 1; j > i; j-- )
    {
      int j1 = values[j]->bDay.toJd();
      int j2 = values[j-1]->bDay.toJd();
      if( j1 < j2)
      {
        this->swap(&values[j], &values[j-1]);
      }
    }
  }
}

void StudentList::bubbleSortByGrade( Student *values[10], int lenght )
{
  int i, j;

  for( i = 0; i < lenght; i++ )
  {
    for( j = lenght - 1; j > i; j-- )
    {
      if(values[j]->grade < values[j-1]->grade)
      {
        this->swap(&values[j], &values[j-1]);
      }
    }
  }
}

void StudentList::bubbleSortByHomeTown( Student *values[10], int lenght )
{
  int i, j;

  for( i = 0; i < lenght; i++ )
  {
    for( j = lenght - 1; j > i; j-- )
    {
      if(values[j]->homeTown < values[j-1]->homeTown)
      {
        this->swap(&values[j], &values[j-1]);
      }
    }
  }
}
