#include "bigint.h"
#include <iostream>
#include<string>
/**
Class:    CECS 282 C++ for Java Developer
Filename: bigint.cpp
Purpose:  Implementation of a custom data type to store bigger
          integer values then the normal Integer datatype
@author Christian Schaf
@version 1.0 11/15/16
*/
BigInt::BigInt():BigInt("0"){}

BigInt::BigInt(int n):BigInt(to_string(n)){}

//BigInt::BigInt(int n){
//    while(n > 0){
//        int r = n%10;
//        n /= 10;
//        value.push_back(r);
//    }
//}

BigInt::BigInt(string n)
{
    string::reverse_iterator rit;
    for ( rit = n.rbegin(); rit < n.rend(); ++rit){
        value.push_back(*rit - 48);
    }

    this->it = value.begin();
    this->rit = value.rbegin();
}

BigInt::BigInt(const BigInt &n)
{
    value = n.value;
    it = value.begin();
    rit = value.rbegin();

}

BigInt::~BigInt()
{
    this->value.clear();
}

BigInt BigInt::operator +(BigInt n){
    BigInt left(*this);
    BigInt right(n);
    BigInt result;
    result.value.clear();

    int overhead = 0;
    int longest = left.size() < right.size() ? right.size():left.size();

    for (int counter = 0; counter < longest; counter++) {
        int x = left.next();
        int y = right.next();

        int value = x + y + overhead;

        if(value > 9){
            overhead = 1;
            result.value.push_back(value%10);
        }
        else{
            overhead = 0;
            result.value.push_back(value);
        }
    }
    if (overhead == 1) {
        result.value.push_back(1);
    }
    return result;
}

BigInt BigInt::operator +(int n)
{
    BigInt left(*this);
    BigInt right(n);
    return left + right;

}

BigInt BigInt::operator -(BigInt n)
{
    BigInt left(*this);
    BigInt right(n);
    BigInt result;
    if(n > *this)return result;
    result.value.clear();

    int overhead = 0;

    for (int counter = 0; counter < left.size(); counter++) {
        int x = left.next();
        int y = right.next() + overhead;

        if(y > x){
            x += 10;
            overhead = 1;
        }
        else overhead = 0;

        int val = x - y;
        result.value.push_back(val);

    }

    return result;
}

BigInt BigInt::operator -(int n)
{
    BigInt left(*this);
    BigInt right(n);

    return left - right;
}

BigInt BigInt::operator =(BigInt n)
{
    value = n.value;
    it = value.begin();
    rit = value.rbegin();
    return *this;
}

bool BigInt::operator ==(int n)
{
    BigInt other(n);
    return std::equal( value.begin(), value.end(), other.value.begin() );
}

bool BigInt::operator ==(BigInt n)
{
    return std::equal( value.begin(), value.end(), n.value.begin() );
}

bool BigInt::operator >(BigInt n)
{
    int longest = size() < n.size() ? n.size():size();
    bool isleftBigger = false;
    for (int i = 0; i < longest; i++) {
        int left = next();
        int right = n.next();
        if(left > right){
            isleftBigger = true;
        }
        else isleftBigger = false;
    }
    if(isleftBigger)return true;
    else return false;
}

bool BigInt::operator <(BigInt n)
{
    return (*(this) > n);
}

int BigInt::size()
{
    return value.size();
}

int BigInt::next()
{
    int current = *it;
    if(it < value.end()){
        it++;
        return current;
    }
    return 0;

}

int BigInt::previous()
{
    int current = *it;
    if(it < value.end()){
        it--;
        return current;
    }
    return 0;
}

int BigInt::rNext()
{
    int current = *rit;
    if(rit < value.rend()){
        rit++;
        return current;
    }
    return 0;

}

int BigInt::rPrevious()
{
    int current = *rit;
    if(rit < value.rend()){
        rit--;
        return current;
    }
    return 0;
}

ostream &operator <<(ostream &out, const BigInt &n)
{
    BigInt temp(n);
    std::vector<int>::reverse_iterator rit;
    for (rit = temp.value.rbegin(); rit < temp.value.rend(); ++rit) {
        out << *rit;
    }
    return out;
}
