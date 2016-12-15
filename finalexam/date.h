#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class date
{
public:
    date();
    date(int,int,int);
    date(const date &d);
    friend ostream& operator <<(ostream &out, const date &d);
    ~date();

private:
    int *datePtr;
};

#endif // DATE_H
