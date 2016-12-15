#include <iostream>
#include "sort3.cpp"
#include "date.h"
#include "bike.h"
using namespace std;

int main()
{
// sort3

//    int a,b,c;
//    a = 9;
//    b = 3;
//    c = 5;
//    sort3(a,b,c);
//    cout << a << ", " << b <<", " << c << endl;
//    return 0;

//    date

//    date D1;
//    date D2(3,27,2007);
//    date D3(D1);
//    cout << D1 << endl;

//    return 0;

//  bike

// part 1
//    bike B1("trek");
//    B1.display();
//    B1 += 7;
//    B1.display();
//    bike B2(B1);
//    B2.display();
//    B2 -= 9;
//    B2.display();
//    return 0;

// part2
    bike B1("trek");
    bike B2("huffy");
    bike B3("schwinn");

    B1 = B3++;
    cout << B1 <<endl;
    cout << B3 <<endl;
    B2 = ++B3;
    cout << B1 <<endl;
    cout << B2 <<endl;
    cout << B3 <<endl;
    return 0;
}
