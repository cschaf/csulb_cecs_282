#ifndef BIKE_H
#define BIKE_H

#include<iostream>
#include<string>

using namespace std;

class Bike
{
public:
    Bike(string);
    Bike operator +(int gear);
    void operator=(Bike bike);
    void display();
    Bike operator++(int dummy);
    Bike operator++();
    friend Bike operator+(int gear, Bike &bike);
    friend ostream &operator <<(ostream &out, const Bike &bike);



private:
    string name; // initialized in constrctor
    int gear;    // valid range 1 to , default = 1

    bool isValidGear(int gear);
};
#endif // BIKE_H
