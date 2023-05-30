#include "clGroup.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include "clDate.h"
#include "clStudent.h"

using namespace std;

clGroup::clGroup()
{
    name_group, institute, department, FIO_boss = '\0', '\0', '\0', '\0';
    count = 0;
}

ostream& operator << (ostream& os, const clGroup& pt)//потоковый вывод класса clStudent
{
    //system("cls");
    cout.width(20); cout.fill('-'); cout << "Группа " << pt.name_group; cout.width(20); cout.fill('-'); cout << '-' << endl; cout.fill(' ');
    os << "Название группы: " << pt.name_group << endl\
        << "Институт: " << pt.institute << endl\
        << "Кафедра: " << pt.department << endl \
        << "Фамилия ИО куратора: " << pt.FIO_boss << endl\
        << "Кол-во студентов в группе: " << pt.count << endl;
    cout.width(40 + pt.name_group.length()); cout.fill('-'); cout << '-' << endl; cout.fill(' ');
    os << "Группа: " << endl;
    for (int i = 0; i < pt.count; i++)
    {
        cout.width(40 + pt.name_group.length()); cout.fill('-'); cout << '-' << endl; cout.fill(' ');
        cout << "Студент " << i + 1 << ": \n";
        os << pt.list[i];
    }
    return os;
}

istream& operator >> (istream& os, clGroup& pt)//потоковый ввод класса clStudent
{
    cout << "Введите название группы: "; os >> pt.name_group;
    cout << "Введите институт: "; os >> pt.institute;
    cout << "Введите выпускающую кафедру: "; os >> pt.department;
    cout << "Введите Фамилия ИО куратора: "; os >> pt.FIO_boss;
    while (true)
    {
        cout << "Введите численность группы: "; os >> pt.count; if (Check(pt.count)) { break; }
        else { cout << "Ошибка ввода" << endl; }
    }
    cin.clear(); cin.ignore(INT_MAX, '\n');
    pt.list = new clStudent[pt.count]();
    for (int i = 0; i < pt.count; i++)
    {
        cin >> pt.list[i];
    }
    return os;
}

void clGroup::sort(clStudent* a, int l, int r)
{
    for (int i = l; i < r - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < r; j++)
            if (a[j] < a[min])
                min = j;
        Swap(a[i], a[min]);
    }
}

void clGroup::Swap(clStudent& A, clStudent& B)// ф-ия перестановок значений
{
    clStudent t = A; A = B; B = t;
}

void clGroup::print_sorted_group()
{
    sort(list, 0, count);
}

clGroup::~clGroup() {}