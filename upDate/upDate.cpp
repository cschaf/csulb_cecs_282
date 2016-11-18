#include "upDate.h"

int upDate::counter = 0;

upDate::upDate() : upDate(5, 11, 1959) { }

upDate::upDate(const upDate &date) : upDate(date.dptr[0], date.dptr[1], date.dptr[2]) { }

upDate::upDate(int M, int D, int Y)
{
    dptr = new int[3];
	setDate(M, D, Y);
    counter++;
}

upDate::~upDate()
{
    delete[] dptr;
    --counter;
}

void upDate::setDate(int M, int D, int Y) {
	if (isValidDate(M, D, Y))
	{
		dptr[0] = M;
		dptr[1] = D;
		dptr[2] = Y;
	}
	else {
		dptr[0] = 5;
		dptr[1] = 11;
		dptr[2] = 1959;
	}
}

int upDate::getMonth()const
{
    return dptr[0];
}

int upDate::getDay()const
{
    return dptr[1];
}

int upDate::getYear()const
{
    return dptr[2];
}

string upDate::getMonthName() const
{
    
	string result = to_string(dptr[0]);

    switch (getMonth()) {
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

int upDate::daysBetween(upDate other)
{
    int jD1 = julian();
    int jD2 = other.julian();

    return jD2 - jD1;
}

int upDate::julian() const
{
    int d = dptr[1];
    int m = dptr[0];
    int y = dptr[2];
    return d-32075+1461*(y+4800+(m-14)/12)/4+367*(m-2-(m-14)/12*12)/12-3*((y+4900+(m-14)/12)/100)/4;
}

/*
 * calculates the gregorien date from a julian date
 *
 * Source: http://aa.usno.navy.mil/faq/docs/JD_Formula.php (09/27/2016)
 */
void upDate::gDate(int jd, int &y, int &m, int &d)
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

int upDate::GetDateCount()
{
    return counter;
}

/*
 * return true or false if date is valid or not
 */
bool upDate::isValidDate(int m, int d, int y)
{   bool validDay = false;
    bool validMonth = false;
    bool validYear = false;

    if(d >= 1 && d <= 31)validDay = true;
    if(m >= 1 && m <= 12)validMonth = true;
    if(y >= -4713 && y <= 2099) validYear = true;

    return validDay && validMonth && validYear;
}

void upDate::incrDate(int n)
{
    int julianDate = julian();
    julianDate += n;
    gDate(julianDate, dptr[2], dptr[0], dptr[1]);
}

void upDate::decrDate(int n)
{
    int julianDate = julian();
    julianDate -= n;
    gDate(julianDate, dptr[2], dptr[0], dptr[1]);
}

void upDate::operator=(upDate date)
{
    int julianDate = date.julian();
    gDate(julianDate, dptr[2], dptr[0], dptr[1]);
}

bool upDate::operator==(upDate date)
{
    return julian() == date.julian();
}

bool upDate::operator!=(upDate date)
{
    return !(*this == date);
}

// Operator extensions
upDate upDate::operator+(int n)
{
    upDate temp(*this);
    temp.incrDate(n);
    return temp;
}

upDate upDate::operator-(int n)
{
    upDate temp(*this);
    temp.decrDate(n);
    return temp;
}

bool upDate::operator>(upDate date)
{
    return julian() > date.julian();
}

bool upDate::operator<(upDate date)
{
    return date > *this;
}

upDate upDate::operator++()
{
    incrDate(1);
    return *this;
}

upDate upDate::operator++(int days)
{
    upDate temp(*this);
    incrDate(1);
    return temp;
}

upDate upDate::operator--()
{
    decrDate(1);
    return *this;
}

upDate upDate::operator--(int days)
{
    upDate temp(*this);
    decrDate(1);
    return temp;
}

// Operator extensions
upDate operator+(int x, upDate &date)
{
    return date + x;
}

int operator-(upDate &date1, upDate &date2)
{
    return date1.julian() - date2.julian();
}

ostream& operator<<(ostream& os, const upDate& dt)
{
    os << dt.getMonthName() << " " << dt.getDay() << ", " << dt.getYear();
    return os;
}
