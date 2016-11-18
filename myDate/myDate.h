// myDate.h
// Author: Christian Schaf (016188534)
// Program #2 due date: 09/27/2016
//
// CECS 282
//

#ifndef MYDATE_H
#define MYDATE_H

#include<string>
#include<iostream>
using namespace std;

class myDate
{
public:
    myDate();
    myDate(int m, int d, int y);
    void display();
    void incrDate(int n);
    void decrDate(int n);
    int daysBetween(myDate d);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayOfWeek();

private:
    int day;
    int month;
    int year;

    void gDate(int jd, int &y, int &m, int &d);
    int jD(int y, int m, int d);
    bool isValidDate(int y, int m, int d);
    string getMonthName(int m);
};


#endif // MYDATE_H
