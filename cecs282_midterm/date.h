#ifndef DATE_H
#define DATE_H


class Date
{
public:
    Date();
    Date(int,int,int);
    ~Date();
    void display();
private:
    int *datePtr;
};

#endif // DATE_H
