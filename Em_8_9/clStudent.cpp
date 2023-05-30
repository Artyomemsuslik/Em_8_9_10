#include "clStudent.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include "clDate.h"

using namespace std;

clStudent::clStudent()
{
    name, surename, lastname = '\0', '\0', '\0'; gender = '\0'; money = 0;
}

ostream& operator << (ostream& os, const clStudent& pt)//��������� ����� ������ clStudent
{
    os << "���: " << pt.name << ' ' << pt.surename << ' ' << pt.lastname << endl \
        << "���� ��������: " << pt.birthday \
        << "���: " << pt.gender << endl\
        << "���� �����������: " << pt.admission \
        << "���������: " << pt.money << endl;
    return os;
}

istream& operator >> (istream& os, clStudent& pt)//��������� ���� ������ clStudent
{
    system("cls");
    int gender_number;
    while (true)
    {
        cout << "������� ��� ��������: "; os >> pt.name; if (Check_string(pt.name)) { break; }
    }
    while (true)
    {
        cout << "������� ������� ��������: "; os >> pt.surename; if (Check_string(pt.surename)) { break; }
    }
    while (true)
    {
        cout << "������� �������� ��������: "; os >> pt.lastname; if (Check_string(pt.lastname)) { break; }
    }
    cout << "���� �������� ��������: "; os >> pt.birthday;
    while (true)
    {
        cout << "������� ��� ��������:\n1 - �������\n2 - �������\n"; cin >> gender_number;
        if (Check(gender_number))
        {
            if (gender_number == 1) { pt.gender = '�'; break; }
            else if (gender_number == 2) { pt.gender = '�'; break; }
            else { cout << "������ �����"; }
        }
    }
    cin.clear(); cin.ignore(INT_MAX, '\n');
    cout << "���� ����������� ��������: "; os >> pt.admission;
    while (true)
    {
        cout << "������� ��������� ��������: "; os >> pt.money;
        if (!cin.fail())
        {
            break;
        }
        else { cin.clear(); cin.ignore(INT_MAX, '\n'); cout << "ERROR: ����������� ������� �����" << endl; }
    }
    cin.clear(); cin.ignore(INT_MAX, '\n');
    //os >> pt.name >> pt.surename >> pt.lastname >> pt.birthday >> pt.gender >> pt.admission >> pt.money ;
    return os;
}

bool clStudent::operator > (const clStudent& pt)//�������� ���������
{
    if (money != pt.money)
    {
        return money > pt.money;
    }
    else { return birthday > pt.birthday; }
}

bool clStudent::operator < (const clStudent& pt)//�������� ���������
{
    if (money != pt.money)
    {
        return money < pt.money;
    }
    else { return birthday < pt.birthday; }
}

void clStudent::operator =(const clStudent& pt)
{
    name = pt.name;
    surename = pt.surename;
    lastname = pt.lastname;
    birthday = pt.birthday;
    gender = pt.gender;
    admission = pt.admission;
    money = pt.money;
}
clStudent::~clStudent(){}