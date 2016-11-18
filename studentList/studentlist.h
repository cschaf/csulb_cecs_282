#ifndef STUDENTLIST_H
#define STUDENTLIST_H
/**
    Class:    CECS 282 C++ for Java Developer
    Filename: studentlist.h
    Purpose:  Represents a list of stundets, which can be sorted by
              ID, Name, Age, Grade and HomeTown

    @author Christian Schaf (016188534)
    @version 1.0 10/11/16
*/
#include "student.h"

class StudentList
{
public:
    StudentList();
    void displayByStudentId();
    void displayByName();
    void displayByOriginalValues();   
    void displayByAge();
    void displayByGrade();
    void displayByHomeTown();
private:
    Student cecs282[10];
    Student *idPtr[10];
    Student *namePtr[10];
    Student *gradePtr[10];
    Student *homeTownPtr[10];
    Student *birthdayPtr[10];

    void createStudents(Student students[]);
    void createIds(int ids[]);
    void swap(Student **x, Student **y);
    void bubbleSortById(Student *values[10], int lenght);
    void bubbleSortByName(Student *values[10], int lenght);
    void bubbleSortByAge(Student *values[], int lenght);
    void bubbleSortByGrade(Student *values[], int lenght);
    void bubbleSortByHomeTown(Student *values[], int lenght);

    bool contains(int ids[], int value);
    char createRandomGrade();
    MyDate createRandomBirthday();


};

#endif // STUDENTLIST_H
