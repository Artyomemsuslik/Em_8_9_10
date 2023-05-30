#pragma once
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include "clDate.h"
#include "clSesion.h"

using namespace std;

template <class T> class clUzel
{
protected:
	T info;
	clUzel* next;
public:
	clUzel();
	friend ostream& operator << (ostream& os, const clUzel& pt);//потоковый вывод класса clSesion
	friend istream& operator >> (istream& os, clUzel& pt);//потоковый ввод класса clSesion 

	~clUzel();
};

