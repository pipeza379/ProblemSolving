#include <iostream>
#include <string>
#include <vector>

using namespace std;

void move(char op);
void ins();
void del();
void backspace();
void print();

vector<string> text;
size_t len_word;
string word;
int cursor = 0;

int main()
{
    int n;
    char op;
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == 'i')
        {
            cin >> word;
            ins();
        }
        else if (op == 'd')
            del();
        else if (op == 'b')
            backspace();
        else if (op == 'l' || op == 'r')
            move(op);
        // print();
        // cout << "cursor : " << cursor << endl;
    }
    print();
}

void move(char op)
{
    if (op == 'l' && cursor > 0)
        --cursor;
    else if (op == 'r' && cursor < text.size())
        ++cursor;
}
void ins()
{
    text.insert(text.begin() + cursor, word);
    cursor++;
}

void del()
{
    if (cursor < text.size())
        text.erase(text.begin() + cursor);
}
void backspace()
{
    if (cursor > 0)
    {
        move('l');
        text.erase(text.begin() + cursor);
    }
}

void print()
{
    for (int i = 0; i < text.size(); i++)
        cout << text[i] << " ";
    cout << endl;
}
