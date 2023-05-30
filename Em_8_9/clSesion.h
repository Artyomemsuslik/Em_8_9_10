#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "clDate.h"

using namespace std;
class clSesion
{
protected:
	string name_discp;
	clDate date_of_delivery;
	string ocenka;
	string name_prepod;
public:
	clSesion();
	friend ostream& operator << (ostream& os, const clSesion& pt);//потоковый вывод класса clSesion
	friend istream& operator >> (istream& os, clSesion& pt);//потоковый ввод класса clSesion 
};

