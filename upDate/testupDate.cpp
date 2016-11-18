// testupDate.cpp
// Author: Steven H Gold
// Program #4 due date: 10/25/2016
// 
// 
//
// All rights and lefts reserved.
//

#include "upDate.h"
#include <iostream>
using namespace std;
int main()
{

	upDate Bday;
    upDate duedate(10,25,2016);
	upDate today(duedate);


	cout << endl;
	cout << "Today is " << today << endl;
	cout << "This program is due on " << duedate;
	cout << endl;

    cout << "(3)Right now there are "<<upDate::GetDateCount() << " upDate objects\n";
    {
        upDate d1, d2, d3;
        cout << "(6)Inside this block there are "<<upDate::GetDateCount() << " upDate objects\n";
    }
    cout << "(3)Outside the block there are "<<upDate::GetDateCount() << " upDate objects\n";

    upDate dtemp(duedate);
    dtemp++;
    cout << "If you turn this assignment in on "<<dtemp<<" then is will be late.\n";
    cout << "It is due on "<<--dtemp<<" so don't be late.\n";
    cout << "One week from due date is "<<duedate+7<<endl;
    cout << "One week from due date is "<<7+duedate<<endl;
    cout << "One week earlier from due date is "<<duedate-7<<endl;

    cout << "Your professor was born on "<<Bday<<" : ";
    cout << "Master Goldis "<< duedate - Bday << " days old today\n";
	
    cout << "Today is Julian date "<<duedate.julian()<<endl;;
    cout << "Tomorrrow is Julian date "<<(++duedate).julian()<<endl;;

    cout << "The very first Julian date was " << upDate(10,25,2016) - upDate(10,25,2016).julian()<<endl;

    cout << "The very first Julian date was " << today - today.julian()<<endl;


    upDate yesterday, tomorrow;
    yesterday = today-1;
    tomorrow = today+1;
	
    cout << "Yesterday was "<<yesterday << endl;
    cout << "Today is "<<today<<endl;
    cout << "Tomorrow is "<<tomorrow<<endl;

    cout << "Today is ";
    cout << ((today>tomorrow)?"greater than":"not greater than");
    cout << " than tomorrow\n";

    cout << "Today is ";
    cout << ((today<tomorrow)?"less than":"not less than");
    cout << " than tomorrow\n";

    cout << "Today is ";
    cout << ((today==tomorrow)?"equal to":"not equal to");
    cout << " tomorrow\n";

	
    upDate halloween(10,31,2016);

    cout << "Hallowwn is on "<< halloween << endl;
    halloween.~upDate(); // deleting halloween
    cout << "Halloween is cancelled: "<<halloween<< endl;


	int dummy;
	cin >> dummy;
	return 0;
}	

	

