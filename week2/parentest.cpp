#include <iostream>
#include <string>
using namespace std;

void check(string inp)
{
    string tmp, expression;
    int i = 0,l = inp.length(),c=true;
    int found;
    char opr = '0';
    while (i < l && l % 2 == 0)
    {
        tmp = inp[i];
        if (inp[i] == '{' || inp[i] == '[' || inp[i] == '(')
        {
            expression.append(tmp);
        }
        else if (inp[i] == '}' || inp[i] == ']' || inp[i] == ')')
        {
            if (inp[i] == '}')
                opr = '{';
            else if (inp[i] == ']')
                opr = '[';
            else if (inp[i] == ')')
                opr = '(';
            found = expression.rfind(opr);
            if (found == -1)
            {
                c = false;
                break;
            }
            else if (found == static_cast<int>(expression.length()) - 1)
            {
                expression.erase(found, 1);
            }
        }
        else
        {
            c=false;
            break;
        }
        i++;
    }
    if (expression.length() == 0 && l % 2 == 0 && c==true)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

int main()
{
    int n;
    cin >> n;
    string exp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> exp[i];
    }
    for (int i = 0; i < n; i++)
    {
        check(exp[i]);
    }
}