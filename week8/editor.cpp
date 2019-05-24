#include <iostream>
#include <string>

using namespace std;
string text;
// char text[1100001];
int cursor = -1;
size_t len_word;
size_t len_text;
void insert(string word)
{
    text.insert(cursor + 1, word + " ");
    cursor += (len_word + 1);
}

int move(char op, int now)
{
    if (op == 'l' && now != -1)
    {
        now--;
        while (text[now] != ' ')
        {
            if (now == -1)
                break;
            now--;
        }
    }
    else if (op == 'r' && (now + 1 != len_text))
    {
        now++;
        while (text[now] != ' ')
            now++;
    }
    return now;
}

void del()
{
    int found = move('r', cursor);

    text.erase(cursor + 1, found);
}
void backspace()
{
    int found = move('l', cursor);
    text.erase(found + 1, cursor - found);
    cursor = found;
}

int main()
{
    int n;
    char op;
    string word;
    // char word[11];
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == 'i')
        {
            cin >> word;
            len_word = word.size();
            insert(word);
        }
        else if (op == 'd')
            del();
        else if (op == 'b')
            backspace();
        else if (op == 'l' || op == 'r')
            cursor = move(op, cursor);
        // cout << text << ", " << cursor << endl;
    }
    // if (text == "")
    //     text += " ";
    cout << text << endl;
}