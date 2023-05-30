#include "clUzel.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include "clDate.h"
#include "clSesion.h"

using namespace std;

template <class T> clUzel<T>::clUzel()
{
	T head = nullptr;
	info = new T;
}

template <class T> ostream& operator << (ostream& os, const clUzel<T>& pt)//потоковый вывод класса clSesion
{
	cout << info;
}

template <class T>
istream& operator >> (istream& os, clUzel<T>& pt)//потоковый ввод класса clSesion 
{
	cin >> info;
}

template <class T>
clUzel<T>::~clUzel<T>() 
{
	delete info;
}
