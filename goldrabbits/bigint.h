#ifndef BIGINT_H
#define BIGINT_H

/**
Class:    CECS 282 C++ for Java Developer
Filename: bigint.h
Purpose:  Custom data type to store bigger integer values then the normal Integer datatype
@author Christian Schaf
@version 1.0 11/15/16
*/

#include<vector>
#include<map>
#include<string>

using namespace std;

class BigInt
{
public:
    BigInt();
    BigInt(int n);
    BigInt(string n);
    BigInt(const BigInt &n); // copy constructor
    ~BigInt();
    BigInt operator +(BigInt n);
    BigInt operator +(int n);
    BigInt operator -(BigInt n);
    BigInt operator -(int n);
    BigInt operator =(BigInt n);
    bool operator ==(int n);
    bool operator ==(BigInt n);
    bool operator > (BigInt n);
    bool operator < (BigInt n);
    int size();
    friend ostream &operator <<(ostream &out, const BigInt &n);
private:
    vector<int> value;
    std::vector<int>::iterator it;
    std::vector<int>::reverse_iterator rit;
    int next();
    int previous();
    int rNext();
    int rPrevious();
};

#endif // BIGINT_H
