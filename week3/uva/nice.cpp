#include <iostream>
#include <string>
// #include <cstdlib>

using namespace std;

void out(string x, string sec_part)
{
    int sum = (26 * 26 * (x[0] - 'A')) + 26 * (x[1] - 'A') + (x[2] - 'A');
    int num = stoi(sec_part);
    string o = abs(sum - num) < 100 ? "nice" : "not nice";
    cout << o << endl;
}

int main()
{
    int line;
    cin >> line;
    while (line--)
    {
        string inp, fst_part = "---", sec_part = "----";
        cin >> inp;
        for (int i = 0; i < 3; i++)
            fst_part[i] = inp[i];
        for (int j = 0; j < 4; j++)
            sec_part[j] = inp[j + 4];
        out(fst_part, sec_part);
    }
}