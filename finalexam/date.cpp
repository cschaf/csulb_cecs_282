#include "date.h"
#include <iostream>
using namespace std;

date::date():date(5,11,1959){}

date::date(int m, int d, int y)
{
    datePtr = new int[3];
    datePtr[0] = m;
    datePtr[1] = d;
    datePtr[2] = y;
}

date::~date()
{
    delete datePtr;
}

ostream & operator <<(ostream &out, const date &d)
{
    out << d.datePtr[0] << "/" <<d.datePtr[1]<< "/" <<d.datePtr[2];
    return out;
}

date::date(const date &d):date(d.datePtr[0], d.datePtr[1], d.datePtr[2]){}


