#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int c = 0, countA = 0;

void SieveOfEratosthenes(int n, int m)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    int last = 2;
    bool start = false;
    for (int p = 1; p <= n; p++)
    {
        if (p == m)
            start = true;
        if (prime[p] && start)
        {
            if (abs(p - last) == 2)
            {
                c++;
                // cout << last << " , " << p << endl;
            }
            last = p;
        }
    }
}

int main()
{
    int n, m;
    cin >> m >> n;
    SieveOfEratosthenes(n, m);
    cout << c << endl;
}