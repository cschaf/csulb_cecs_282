// myDate.cpp
// Author: Christian Schaf
// Program #2 due date: 09/27/2016
//
// All rights and lefts reserved.
//

#include "myDate.h"
#include<iostream>

using namespace std;
/*
 * Default constructor.
 * This will set the date to May 11, 1959
 * */
myDate::myDate()
{
   day = 11;
   month = 5;
   year = 1959;
}
/*
* Overloaded constructor.
* This will set the date to the values passed in through the parameter list represented by Month, Day and Year
*/
myDate::myDate(int m, int d, int y): myDate()
{
    if(isValidDate(m,d,y)){
        day = d;
        month = m;
        year = y;
    }
}
/*
 * Display the date in the following format (May 11, 1959)
 */
void myDate::display()
{
    cout << getMonthName(month) << ' ' << getDay() << ", " << getYear();
}

/*
 * Iincrement the date by N days
 */
void myDate::incrDate(int n)
{
    int jd = jD(year, month, day);
    jd += n;
    gDate(jd, year, month, day);
}

/*
 * Decrement the date by N days
 */
void myDate::decrDate(int n)
{
    int jd = jD(year, month, day);
    jd -= n;
    gDate(jd, year, month, day);
}

/*
 * return the number of days between this date and the date D.
 * If date D is a future date, the return value will be a positive int.
 * If date D is in the past, the return value will be a negative int.
 */
int myDate::daysBetween(myDate d)
{
    int jD1 = jD(year, month, day);
    int jD2 = jD(d.year, d.month, d.day);

    return jD2 - jD1;

}

/*
 *return the month in integer form
 */
int myDate::getMonth()
{
    return month;
}

/*
 * return the day of the month
 */
int myDate::getDay()
{
    return day;
}

/*
 * return the year
 */
int myDate::getYear()
{
    return year;
}

/*
 * return the number of days since the current year began. Example Jan 1 is 1, Feb 1 is 32
 */
int myDate::dayOfYear()
{
    int days = 0;
    myDate temp(month, day, year);
    int jd = jD(temp.year,temp.month, temp.day);
    while(temp.year == year){
        jd--;
        temp.gDate(jd, temp.year, temp.month, temp.day);
        days++;
    }
    return days;
}

/*
 * returns Monday, Tuesday, etc according to the day of the week.
 */
string myDate::dayOfWeek()
{
    string dayName = "unknown";
    int jd = jD(year, month, day);
    int modDay = jd % 7;
    switch (modDay) {
    case 0:
        dayName = "Monday";
        break;
    case 1:
        dayName = "Tuesday";
        break;
    case 2:
        dayName = "Wednesday";
        break;
    case 3:
        dayName = "Thursday";
        break;
    case 4:
        dayName = "Friday";
        break;
    case 5:
        dayName = "Saturday";
        break;
    case 6:
        dayName = "Sunday";
        break;
    default:
        break;
    }
    return dayName;

}

/*
 * calculates the gregorien date from a julian date
 *
 * Source: http://aa.usno.navy.mil/faq/docs/JD_Formula.php (09/27/2016)
 */
void myDate::gDate(int jd, int &y, int &m, int &d)
{
    int L= jd+68569;
    int N= 4*L/146097;
    L= L-(146097*N+3)/4 ;
    int I= 4000*(L+1)/1461001;
    L= L-1461*I/4+31;
    int J= 80*L/2447;
    int K= L-2447*J/80;
    L= J/11;
    J= J+2-12*L;
    I= 100*(N-49)+I+L;

    y= I;
    m= J;
    d= K;
}

/*
 * calculates the julian date from a gregorien date
 *
 * Source: http://aa.usno.navy.mil/faq/docs/JD_Formula.php (09/27/2016)
 */
int myDate::jD(int y, int m, int d)
{
    return d-32075+1461*(y+4800+(m-14)/12)/4+367*(m-2-(m-14)/12*12)/12-3*((y+4900+(m-14)/12)/100)/4;
}

/*
 * return true or false if date is valid or not
 */
bool myDate::isValidDate(int m, int d, int y)
{   bool validDay = false;
    bool validMonth = false;
    bool validYear = false;

    if(d >= 1 && d <= 31)validDay = true;
    if(m >= 1 && m <= 12)validMonth = true;
    if(y >= 1801 && y <= 2099) validYear = true;

    return validDay && validMonth && validYear;
}

/*
 * return the name of the month
 */
string myDate::getMonthName(int m)
{
    string result = "unknown";

    switch (m) {
    case 1:
        result = "January";
        break;
    case 2:
        result = "February";
        break;
    case 3:
        result = "March";
        break;
    case 4:
        result = "April";
        break;
    case 5:
        result = "May";
        break;
    case 6:
        result = "June";
        break;
    case 7:
        result = "July";
        break;
    case 8:
        result = "August";
        break;
    case 9:
        result = "September";
        break;
    case 10:
        result = "October";
        break;
    case 11:
        result = "November";
        break;
    case 12:
        result = "December";
        break;
    default:
        break;
    }

    return result;
}

