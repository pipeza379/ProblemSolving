//#include<stdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, count;
    cin >> n;
    int std[n];
    for (int i = 0; i < n; i++)
    {
        cin >> std[i];
    }
    for (int k = 0; k < n; k++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (k == j)
                continue;
            else if (std[k] < std[j])
                // cout << std[j];
                count++;
        }
        cout << count << endl;
    }
}