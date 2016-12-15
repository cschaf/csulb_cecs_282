#include "bike.h"
#include<iostream>
#include<string>

using namespace std;

bike::bike(string name)
{
  this->gear = 1;
  this->name = name;
}

bike::bike(const bike &b){
    this->name = b.name;
    this->gear = b.gear;
}

bike bike::operator +=(int gear)
{
    if((this->gear + gear) <= 5)this->gear += gear;
    else this->gear = 5;
    return *this;
}
bike bike::operator -=(int gear)
{
    if((this->gear - gear) >= 1)this->gear -= gear;
    else this->gear = 1;
    return *this;
}

void bike::display()
{
    cout << name << ":"<< gear << endl;
}

void bike::operator =(bike b){
    this->gear = b.gear;
}

bike bike::operator++(int dummy){
    bike temp(*this);
    this->gear += 1;
    return temp;
}

bike bike::operator ++(){
    this->gear +=1;
    return *this;
}

ostream& operator << (ostream &out, const bike &b){
    out << b.name << ":"<< b.gear;
    return out;
}
