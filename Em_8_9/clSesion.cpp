#include "clSesion.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include "clDate.h"

using namespace std;

clSesion::clSesion()
{
    name_discp = "\0";
    date_of_delivery = { 0,0,0 };
    ocenka = "\0";
    name_prepod = "\0";
}

ostream& operator << (ostream& os, const clSesion& pt)//��������� ����� ������ clStudent
{
    os << pt.name_discp << ' ' <<pt.date_of_delivery << ' ' << pt.ocenka << ' ' << pt.name_prepod << ' ' << endl;
    return os;
}

istream& operator >> (istream& os, clSesion& pt)//��������� ���� ������ clStudent
{
    system("cls");
    cout << "�������� ���������: " << endl; os >> pt.name_discp; 
    cout << "���� �����:" << endl; os >> pt.date_of_delivery; 
    while (true)
    {
        cout << "������: " << endl; os >> pt.ocenka;
        if (stoi(pt.ocenka) >= 0 && stoi(pt.ocenka) <= 5)
        {
            if (stoi(pt.ocenka) == 0) { pt.ocenka = "�������"; break;}
            if (stoi(pt.ocenka) == 1) { pt.ocenka = "�����"; break; }
            pt.ocenka = stoi(pt.ocenka); break;
        }
        else { cout << "������ �����" << endl; }
    }
    cout << "������� �� �������������" << endl; os >> pt.name_prepod;
    //os >> pt.name >> pt.surename >> pt.lastname >> pt.birthday >> pt.gender >> pt.admission >> pt.money ;
    return os;
}