#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include "clDate.h"
#include "clStudent.h"
#include "clGroup.h"

using namespace std;

bool Check(int n)
{
    if (!cin.fail())
    {
        return true;
    }
    else { cin.clear(); cin.ignore(INT_MAX, '\n'); cout << "ERROR: некорректно введено число" << endl; return false; }
}

bool Check_string(string word)
{
    string abc= "0123456789";
    for (int i = 0; i < word.length(); i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if (word[i] == abc[j]) 
            {
                cin.clear(); cin.ignore(INT_MAX, '\n');
                cout << "ERROR: цифра в слове" << endl; 
                return false; 
            }
        }
    }
    return true;
}

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    
    clGroup c; cin >> c; cout << c << endl;
    c.print_sorted_group(); 
    cout << "-------------Отсортированный список-------------"<< endl<< c;
    return 0;
}
