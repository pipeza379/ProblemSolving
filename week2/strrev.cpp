#include <iostream>
#include <string>
using namespace std;

void reverse(string str)
{
    for (int i = str.length() - 1; i >= 0; i--)
        cout << str[i];
}
int main()
{
    string text, cp;
    cin >> text;
    reverse(text);
    cout << endl;
}