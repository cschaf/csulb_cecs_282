#ifndef BIKE_H
#define BIKE_H

#include<iostream>
#include<string>


class bike
{
public:
    // part 1
    bike(std::string name);
    bike(const bike &b);
    bike operator +=(int gear);
    bike operator -=(int gear);
    void display();
    //part 2
    friend std::ostream& operator << (std::ostream &out, const bike &b);
    bike operator ++(int dummy);
    bike operator ++();
    void operator =(bike b);
private:
    std::string name;
    int gear;
};

#endif // BIKE_H
