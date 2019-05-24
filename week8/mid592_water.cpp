#include <iostream>

using namespace std;

int main()
{
    int enegy = 0, enegy_today, n0 = 0, n, r;
    cin >> r;
    while (r--)
    {
        enegy_today=0;
        cin >> n;
        if (n0 - n > 10)
        {
            enegy_today = 10 * (n0 - n);
            enegy += (enegy_today > 700) ? 700 : enegy_today;
        }
        n0 = n;
        // cout << enegy_today << endl;
    }
    cout << enegy << endl;
}