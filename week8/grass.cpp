#include <iostream>
#include <string>

using namespace std;

char field[101][101] = {'.'};
char cmd;
int s, n, num;

void createField()
{
    for (int row = 0; row < s; row++)
    {
        cin >> field[row];
    }
}

void printMap()
{
    for (int r = 0; r < s; r++)
        cout << field[r] << endl;
}

// void eatRow()
// {
//     if (cmd == 'L')
//         for (int i = 0; i < n; i++)
//         {
//             if (field[num][i] == '.')
//                 break;
//             field[num][i] = '.';
//         }
//     else if (cmd == 'R')
//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (field[num][i] == '.')
//                 break;
//             field[num][i] = '.';
//         }
// }

void eatGrass()
{
    int r, c;
    if (cmd == 'U' || cmd == 'L')
    {
        for (int i = 0; i < s; i++)
        {
            if (cmd == 'U')
                r = i, c = num;
            else if (cmd == 'L')
                r = num, c = i;
            if (field[r][c] != 'x')
                break;
            field[r][c] = '.';
        }
    }
    else if (cmd == 'D' || cmd == 'R')
    {
        for (int i = s - 1; i >= 0; i--)
        {
            if (cmd == 'D')
                r = i, c = num;
            else if (cmd == 'R')
                r = num, c = i;
            if (field[r][c] != 'x')
                break;
            field[r][c] = '.';
        }
    }
}

void plantGrass()
{
    int r, c;
    for (int i = 0; i < s; i++)
    {
        if (cmd == 'A')
            r = num, c = i;
        else if (cmd == 'B')
            r = i, c = num;
        if (field[r][c] != '#')
            field[r][c] = 'x';
    }
}

void operation()
{
    for (int i = 0; i < n; i++)
    {
        cin >> cmd >> num;
        num--;
        if (cmd == 'L' || cmd == 'R' || cmd == 'U' || cmd == 'D')
            eatGrass();
        else if (cmd == 'A' || cmd == 'B')
            plantGrass();
        // printMap();
    }
}

int main()
{
    cin >> s >> n;
    createField();
    operation();
    printMap();
}