#include <iostream>

using namespace std;

bool check_prime(int p)
{
    if (p <= 1)
    {
        return false;
    }
    else
    {
        for (int i = 2; i < p; i++)
        {
            // cout << i <<endl;
            if (p % i == 0)
                return false;
        }
        return true;
    }
}
int main()
{
    int p, n;
    cin >> p;
    n = p + 1;
    while (!check_prime(n))
    {
        n++;
    };
    cout << n << endl;
}