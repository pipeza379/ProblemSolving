//#include<stdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string number;
    cin >> number;
    int lenght = number.size();
    for (int i = 0; i < lenght / 2; i++)
    {
        if (number[i] != number[lenght - i - 1])
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}