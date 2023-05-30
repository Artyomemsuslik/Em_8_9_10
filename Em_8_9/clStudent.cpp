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

ostream& operator << (ostream& os, const clStudent& pt)//потоковый вывод класса clStudent
{
    os << "ФИО: " << pt.name << ' ' << pt.surename << ' ' << pt.lastname << endl \
        << "День рождение: " << pt.birthday \
        << "Пол: " << pt.gender << endl\
        << "Дата поступления: " << pt.admission \
        << "Стипендия: " << pt.money << endl;
    return os;
}

istream& operator >> (istream& os, clStudent& pt)//потоковый ввод класса clStudent
{
    system("cls");
    int gender_number;
    while (true)
    {
        cout << "Введите имя студента: "; os >> pt.name; if (Check_string(pt.name)) { break; }
    }
    while (true)
    {
        cout << "Введите фамилию студента: "; os >> pt.surename; if (Check_string(pt.surename)) { break; }
    }
    while (true)
    {
        cout << "Введите отчество студента: "; os >> pt.lastname; if (Check_string(pt.lastname)) { break; }
    }
    cout << "День рождение студента: "; os >> pt.birthday;
    while (true)
    {
        cout << "Введите пол студента:\n1 - мужчина\n2 - женщина\n"; cin >> gender_number;
        if (Check(gender_number))
        {
            if (gender_number == 1) { pt.gender = 'М'; break; }
            else if (gender_number == 2) { pt.gender = 'Ж'; break; }
            else { cout << "Ошибка ввода"; }
        }
    }
    cin.clear(); cin.ignore(INT_MAX, '\n');
    cout << "Дата поступления студента: "; os >> pt.admission;
    while (true)
    {
        cout << "Введите стипендию студента: "; os >> pt.money;
        if (!cin.fail())
        {
            break;
        }
        else { cin.clear(); cin.ignore(INT_MAX, '\n'); cout << "ERROR: некорректно введено число" << endl; }
    }
    cin.clear(); cin.ignore(INT_MAX, '\n');
    //os >> pt.name >> pt.surename >> pt.lastname >> pt.birthday >> pt.gender >> pt.admission >> pt.money ;
    return os;
}

bool clStudent::operator > (const clStudent& pt)//проверка стипендии
{
    if (money != pt.money)
    {
        return money > pt.money;
    }
    else { return birthday > pt.birthday; }
}

bool clStudent::operator < (const clStudent& pt)//проверка стипендии
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