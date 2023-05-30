#pragma once
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include "clDate.h"

using namespace std;

bool Check_string(string word);

class clStudent
{
protected:
    string name;
    string surename;
    string lastname;
    clDate birthday;
    char gender;
    clDate admission;
    float money;
public:
    clStudent();
    friend ostream& operator << (ostream& os, const clStudent& pt);//потоковый вывод класса clStudent
    friend istream& operator >> (istream& os, clStudent& pt);//потоковый ввод класса clStudent 
    bool operator > (const clStudent& pt);//проверка стипендии
    bool operator < (const clStudent& pt);//проверка стипендии
    void operator =(const clStudent& pt);    
    ~clStudent();
};
