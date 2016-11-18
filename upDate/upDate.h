#ifndef UPDATE_H
#define UPDATE_H
/**
Class:    CECS 282 C++ for Java Developer
Filename: upDate.h
Purpose:  Updated version of a own date class
@author Christian Schaf
@version 1.0 10/25/16
*/
#include<iostream>
#include<string>
using namespace std;

class upDate
{
public:
    upDate();
    upDate(int M, int D, int Y);
    upDate(const upDate &date);
    ~upDate();
    int getYear()const;
    int getMonth()const;
    int getDay()const;
    static int GetDateCount();
    void operator=(upDate date);
    upDate operator+(int n); // Addition
    upDate operator-(int n); // Subtraction
    friend upDate operator+(int x, upDate &date); // extension or addtion with
    friend int operator- (upDate &date1, upDate &date2);
    friend ostream& operator<<(ostream& os, const upDate& dt);
    bool operator== (upDate date);
    bool operator!= (upDate date);
    bool operator> (upDate date);
    bool operator< (upDate date);
    upDate operator++();
    upDate operator++(int);   
    upDate operator--();
    upDate operator--(int);
    int julian() const;
    string getMonthName()const ;
    void incrDate(int n);
    void decrDate(int n);
    int daysBetween(upDate date);
private:
    int *dptr;
    static int counter;
    void gDate(int jd, int &y, int &m, int &d);
	void setDate(int m, int d, int y);
    bool isValidDate(int m, int d, int y);
};
#endif // UPDATE_H