#include <iostream>
#include <string>
using namespace std;

int charToInt(char c)
{
    int out = int(c) - 48;
    return out;
}

int main()
{
    string a[2];
    cin >> a[0] >> a[1];
    int mx = a[0].length() >= a[1].length() ? 0 : 1;
    int mn = a[0].length() < a[1].length() ? 0 : 1;
    int i = a[mx].length() - 1;
    int j = a[mn].length() - 1;
    int o[a[mx].length() + 1];
    int tmp = 0;
    
    if(i-j !=0){
        for(int c=0;c<i-j;c++){
            a[mn]= a[mn].insert(0,"0");
        }
    }
    // cout << a[mn] << endl; //adjust length string

    while (i >= 0)
    {
        int sum = charToInt(a[mx][i]) + charToInt(a[mn][i]) + tmp; //cast to int
        // cout << " mn: " << charToInt(a[mn][i]) << " mx: " << charToInt(a[mx][i]) <<" sum: " << sum << endl;
        tmp = sum / 10;
        o[i + 1] = sum % 10;
        i--;
    }
    o[0] = tmp;
    for (int round = 0; round <= a[mx].length(); round++)
    {
        if (round == 0 && o[0] == 0)
            continue;
        cout << o[round];
    }
    cout << endl;
}
