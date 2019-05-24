//#include<stdio>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int point, n, x, y;
    point = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        float r = sqrt(x*x+y*y);
        if (r <= 2 )
            point += 5;
        else if (r <= 4)
            point += 4;
        else if (r <= 6)
            point += 3;
        else if (r <= 8)
            point += 2;
        else if (r <= 10)
            point += 1;
    }
    cout << point << endl;
}