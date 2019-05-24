#include <iostream>
#include <vector>

using namespace std;
int END, round;

void n_i(int ni)
{
    int divi = ni, count = 0, i = 1;
    // cout << ni << endl;
    while (divi >= i)
    {
        if (ni % i != 0)
        {
            i++;
            continue;
        }
        divi = ni / i;
        if (divi == i)
            count += 1;
        else if (divi > i)
            count += 2;
        i++;
    }
    int nnew = ni + count;
    cout << nnew << endl;
    if (nnew >= END)
        return;
    else
        n_i(nnew);
}

int main()
{
    cin >> END;
    n_i(1);
}