#include <iostream>

using namespace std;

int main()
{
    int x, n=1, count = -1;
    cin >> x;
    while (n != 0)
    {
        cin >> n;
        count++;
    }
    cout << ((x - 2558 - count) % 2 == 0 ? 'K' : 'C') << endl;
}