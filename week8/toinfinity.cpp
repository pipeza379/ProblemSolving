#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, x, y, r, tmp, mn = -1;
    cin >> n;
    int distance[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> r;
        tmp = abs(y) - r;
        if (tmp <= 0)
            break;
        distance[i] = tmp;
    }
    if (tmp > 0)
    {
        sort(distance, distance + (sizeof(distance) / sizeof(distance[0])));
        mn = distance[0];
    }
    cout << mn << endl;
}