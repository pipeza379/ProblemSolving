#include <iostream>
#include <string>
#include <bitset>
#include <sstream>

using namespace std;

int main()
{
    char sum[32];
    int n, m;
    while (cin >> n >> m)
    {
        string bit1 = bitset<32>(n).to_string();
        string bit2 = bitset<32>(m).to_string();
        for (int i = 31; i >= 0; i--)
        {
            if (bit1[i] == bit2[i])
                sum[i] = '0';
            else
                sum[i] = '1';
        }
        // cout << sum << endl;
        stringstream ss;
        string s;
        ss << sum;
        ss >> s;
        unsigned int deci = bitset<32>(s).to_ullong();
        cout << deci << endl;
    }
}