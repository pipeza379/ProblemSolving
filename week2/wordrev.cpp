#include <iostream>
#include <string>
using namespace std;

void reverse(string &str, int n)
{
    for (int i = n - 1; i >= 0; i--)
        cout << str[i];
}
int main()
{
    string text, cp;
    cin >> text;
    int count = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '_')
        {
            reverse(cp, count);
            cout << "_";
            cp.clear();
            count = 0;
            continue;
        }
        cp[count] = text[i];
        count++;
    }
    reverse(cp, count);
    cout << endl;
}