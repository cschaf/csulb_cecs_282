#include<string>
#include "bike.h"

//------------- 1 start ---------------------
Bike::Bike(string name)
{
    this->gear = 1;
    this->name = name;
}

//Bike::Bike(const Bike &bike):Bike(bike.name){}

void Bike::operator =(Bike bike){
    this->gear = bike.gear;
    //this->name = bike.name; // we dont want to change the names
}
bool Bike::isValidGear(int gear){
    if(gear > 0 && gear <=5 )return true;
    return false;
}

void Bike::display()
{
    cout<<name<<":"<<gear<<endl;
}

Bike Bike::operator +(int gear){
    Bike temp(*this);
    if(isValidGear(temp.gear + gear)){
        temp.gear += gear;
    }
    return temp;
}

Bike operator +(int gear, Bike &bike){
    return bike + gear;
}

//------------- 1 end -----------------------
//------------- 2 start ---------------------

Bike Bike::operator ++(int dummy){;
    Bike temp(*this);
    gear++;
    return temp;
}

Bike Bike::operator ++(){
    gear++;
    return (*this);
}

ostream &operator <<(ostream &out,const Bike &bike){
    out << bike.name << ":" <<bike.gear;
    return out;
}
