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
    friend ostream& operator << (ostream& os, const clStudent& pt);//��������� ����� ������ clStudent
    friend istream& operator >> (istream& os, clStudent& pt);//��������� ���� ������ clStudent 
    bool operator > (const clStudent& pt);//�������� ���������
    bool operator < (const clStudent& pt);//�������� ���������
    void operator =(const clStudent& pt);    
    ~clStudent();
};
