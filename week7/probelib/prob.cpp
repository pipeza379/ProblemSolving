#include <iostream>
#include "probelib.h"

using namespace std;

// bool bst(int ANS, int L, int R)
// {
//     int n = (L + R) / 2;
//     cout << n << endl;
//     if (n > ANS)
//         return bst(ANS, L, n);
//     else if (n < ANS)
//         return bst(ANS, n + 1, R);
//     else if (n == ANS)
//     {
//         cout << "ans: " << n << endl;
//         return true;
//     }
//     return false;
// }

void bst(int L, int R)
{
    int n = (L + R) / 2;
    // cout << n << ", " << L << " : " << R << endl;
    if (L == R)
        probe_answer(n);
    else if (probe_check(n+1, R))
    {
        // cout << "R\n";
        bst(n+1, R);
    }
    else
    {
        // cout << "L\n";
        bst(L, n);
    }
}

int main()
{
    // int N = 100000;
    // int ANS = 12367;
    // cout << bst(ANS, 0, N) << endl;
    int N = probe_init();
    bst(0, N - 1);
}