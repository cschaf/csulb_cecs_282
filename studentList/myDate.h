#ifndef MYDATE_H
#define MYDATE_H
/**
    Class:    CECS 282 C++ for Java Developer
    Filename: myDate.h
    Purpose:  Represents a date
    @author Christian Schaf
    @version 2.0 10/11/16
*/
#include<string>
#include<iostream>
using namespace std;

class MyDate
{
public:
    MyDate();
    MyDate(int m, int d, int y);
    void display();
    void incrDate(int n);
    void decrDate(int n);
    int daysBetween(MyDate d);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayOfWeek();

    static void gDate(int jd, int &y, int &m, int &d);
    static int jD(int y, int m, int d);
    string getValue();
    int toJd();
private:
    int day;
    int month;
    int year;

    bool isValidDate(int y, int m, int d);
    string getMonthName(int m);
};


#endif // MYDATE_H
