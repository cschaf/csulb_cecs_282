#ifndef STUDENT_H
#define STUDENT_H
/**
    Class:    CECS 282 C++ for Java Developer
    Filename: student.h
    Purpose:  Represents the datatype of a student
    @author Christian Schaf
    @version 1.0 10/11/16
*/
#include<string>
#include "myDate.h"

struct Student
{
char name[11];
char grade;
int id;
MyDate bDay;
string homeTown;
};

#endif // STUDENT_H
