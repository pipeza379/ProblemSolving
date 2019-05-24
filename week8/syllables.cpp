#include <iostream>
#include <string>

using namespace std;

void syllable(string word)
{
    int len = word.length();
    int count = 0, tmp = 0;
    for (int i = 0; i < len; i++)
    {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
            tmp++;
        else if (tmp != 0)
        {
            tmp = 0;
            count++;
        }
    }
    if(tmp!=0) count++;
    cout << count << endl;
}

int main()
{
    int n;
    string text;
    cin >> n;
    while (n--)
    {
        cin >> text;
        syllable(text);
    }
}

