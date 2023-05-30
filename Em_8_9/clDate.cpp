#include "clDate.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

clDate::clDate() // конструктор по умолчанию !!!не может быть возвращ знач(даже void)!!!
{
    day = 0; month = 0; year = 0;
}

clDate::clDate(int d, int m, int y)
{
    day = d; month = m; year = y;
}

bool clDate:: operator > (const clDate& pt)
{
    return month > pt.month;
}

bool clDate:: operator < (const clDate& pt)
{
    return month < pt.month;
}

clDate& clDate::operator =(const clDate& pt)
{
    this->day = pt.day;
    this->month = pt.month;
    this->year = pt.year;
    return *this;
}

ostream& operator << (ostream& os, const clDate& pt)
{
    os << pt.day << ' ' << pt.month << ' ' << pt.year << endl;
    return os;
}

istream& operator >> (istream& os, clDate& pt)
{
    while (true)
    {
        cout << "¬ведите день: "; os >> pt.day; if (Check(pt.day) && pt.day > 0 && pt.day < 32) { break; }
        else { cout << "„исло вне диапазона [1,31]"; }
    }
    cin.clear(); cin.ignore(INT_MAX, '\n');
    while (true)
    {
        cout << "¬ведите мес€ц: "; os >> pt.month; if (Check(pt.month) && pt.month > 0 && pt.month < 13) { break; }
        else { cout << "„исло вне диапазона [1,12]"; }
    }
    cin.clear(); cin.ignore(INT_MAX, '\n');
    while (true)
    {
        cout << "¬ведите год: "; os >> pt.year; if (Check(pt.year)) { break; }
    }
    cin.clear(); cin.ignore(INT_MAX, '\n');
    //os >> pt.day>> pt.month>> pt.year;
    return os;
}