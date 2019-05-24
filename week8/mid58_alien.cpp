#include <iostream>
#include <math.h>

using namespace std;

int alien[2]; //x y
int r;
int calDistance(int x, int y)
{
    int dis = pow(abs(x-alien[0]), 2) + pow(abs(y-alien[1]), 2);
    return dis;
}

int main()
{
    int n, x, y, count = 0;
    cin >> n >> alien[0] >> alien[1] >> r;
    while (n--)
    {
        cin >> x >> y;
        int distance = calDistance(x, y);
        if (distance <= pow(r,2))
            count++;
    }
    cout << count<<endl;
}