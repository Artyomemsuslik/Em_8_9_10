#pragma once
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include "clDate.h"
#include "clStudent.h"

using namespace std;

class clGroup
{
protected:
    string name_group;
    string institute;
    string department;
    string FIO_boss;
    int count;
    clStudent* list /*= new clStudent * [count]*/;
public:
    clGroup();
    friend ostream& operator << (ostream& os, const clGroup& pt);//��������� ����� ������ clStudent
    friend istream& operator >> (istream& os, clGroup& pt);//��������� ���� ������ clStudent    
    void sort(clStudent* a, int l, int r);
    void Swap(clStudent& A, clStudent& B);// �-�� ������������ ��������
    void print_sorted_group();
    ~clGroup();
};

