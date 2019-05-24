#include <iostream>

using namespace std;

void out(int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        if (s == 0)
            cout << " ";
        if (s == 1)
            cout << "*";
    }
}

int main()
{
    int n, i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        j = n - i;
        out(j, 0);
        out(i, 1);
        cout << endl;
    }
}
