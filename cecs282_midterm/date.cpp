#include "date.h"
#include<iostream>
using namespace std;

Date::Date():Date(5,11,1959){}

Date::Date(int m, int d, int y){
    datePtr = new int[3];
    datePtr[0] = m;
    datePtr[1] = d;
    datePtr[2] = y;
}

Date::~Date(){
    delete []datePtr;
}

void Date::display(){
    cout << datePtr[0] << "/" << datePtr[1] << "/" << datePtr[2] << endl;
}
