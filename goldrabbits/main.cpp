#include <iostream>
#include<time.h>
#include<iomanip>
#include <algorithm>
#include "bigint.h"
/**
Class:    CECS 282 C++ for Java Developer
Filename: main.cpp
Purpose:  Main method of the goldenrabbits project
@author Christian Schaf
@version 1.0 11/15/16
*/
using namespace std;
static map<int, BigInt> results;

BigInt findResult(int number){

    map<int, BigInt>::iterator it;
    it = results.find(number);
    if(it == results.end()){
        return BigInt(0);

    }
    else{
        return (*it).second;
    }
}

BigInt goldRabbit(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        BigInt right = findResult(n-1);
        if(right == 0){
           right = goldRabbit(n-1);
           results[n-1] = right;
        }
        BigInt left = findResult(n-2);
        if(left == 0){
           left = goldRabbit(n-2);
           results[n-2] = left;
        }
        return left + right;
    }
}

int main()
{
    int const month = 1001;
    int start = time(0); //number of seconds since Jan 1, 1970
    for (int i = 0; i < month; ++i) {
        int current = time(0); // number of seconds since program started
        cout << setw(5)<<current-start <<":"; // print elapsed seconds
        cout << " GoldRabbits(" << setw(2) << i <<") = ";
        cout << setw(11) << goldRabbit(i) << endl;
    }
    return 0;
}

