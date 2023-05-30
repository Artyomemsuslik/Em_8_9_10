#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool Check(int n);

class clDate
{
private:
    int year;
    int month;
    int day;
public:
    clDate();// конструктор по умолчанию !!!не может быть возвращ знач(даже void)!!!
    clDate(int d, int m, int y);
    ~clDate() {/* cout << "Привет из Деструктора "; */ } //Диструктор

    bool operator > (const clDate& pt);

    bool operator < (const clDate& pt);

    clDate& operator =(const clDate& pt);

    friend ostream& operator << (ostream& os, const clDate& pt);

    friend istream& operator >> (istream& os, clDate& pt);
};

