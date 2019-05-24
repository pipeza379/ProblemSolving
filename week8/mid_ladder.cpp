#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void move(int dice);
int cursor = -1, n;

int main()
{
    int m, dice;
    cin >> n >> m;
    int map[n];
    for (int i = 0; i < n; i++)
        cin >> map[i];
    while (m--)
    {
        cin >> dice;
        move(dice);
        move(map[cursor]);
        // cout << cursor + 1 << endl;
    }
    cout << cursor + 1 << endl;
}

void move(int dice)
{
    cursor += dice;
    if (cursor < 0)
        cursor = -1;
    else if (cursor >= n)
        cursor = n-1;
}
