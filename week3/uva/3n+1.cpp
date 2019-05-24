#include <iostream>
#include <string>

using namespace std;

int func(int n)
{
    int size = 1;
    while (n != 1)
    {
        size += 1;
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
    }
    return size;
}

int main()
{
    int i, j, tmp_i, tmp_j;
    while (cin >> i >> j)
    {
        int size=0,max=0;
        tmp_i = i;
        tmp_j = j;
        if (i > j)
            swap(i, j);
        for (i; i <= j; i++)
        {
            size = func(i);
            max = size >= max ? size : max;
        }
        cout << tmp_i << " " << tmp_j << " " << max << endl;
    }
}