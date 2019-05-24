#include <iostream>
#include <string>

using namespace std;

int r, c;
char map[240][120];
int treasure = 0;
void printMap()
{
    for (int i = 0; i < 2 * r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << map[i][j];
        cout << endl;
    }
    cout << endl;
}

void clearMap()
{
    for (int i = 0; i < 2 * r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i % 2 == 0)
                map[i][j] = ' ';
            else
            {
                if (map[i][j] == 'X')
                    map[i][j] = '.';
            }
        }
    }
    // printMap();
}

int path(int x, int y, char way = 'L')
{
    if (map[y][x] == '.' || map[y][x] == ' ')
        map[y][x] = 'X';
    // cout << "x: " << x << endl;
    // cout << "y: " << y << endl;
    // printMap();

    if (x >= 0 && x < c)
    {
        if (map[y + 1][x] == '$')
        {
            treasure += 1;
            printMap();
            cout << "ts: " << treasure << endl;
            clearMap();
            return 0;
        }
        else if (map[y + 1][x] == '@')
        {
            clearMap();
            return 0;
        }
        else if (map[y + 1][x] == '.' || map[y + 1][x] == ' ')
        {
            path(x, y + 1, way);
        }
        else if (way == 'L' && (map[y][x - 1] == ' ' || map[y][x - 1] == 'X'))
            path(x - 1, y);
        else if (way == 'R' && (map[y][x + 1] == ' ' || map[y][x + 1] == 'X'))
            path(x + 1, y, 'R');
    }
    if (x == 0 && way == 'L')
        path(x + 1, y, 'R');
    else if (x + 1 == c && way == 'R')
        path(x - 1, y);
}

void start()
{
    for (int i = 0; i < c; i++)
    {
        // cout << map[0][i] << endl;
        // if (map[1][i] == '#')
        // {
        cout << "\nStart\n";
        path(i, 0);
        path(i, 0, 'R');
        // }
    }
}

int main()
{
    cin >> c >> r;
    //create map
    for (int i = 0; i < 2 * r; i++)
    {
        if (i % 2 != 0)
            cin >> map[i];
        else
        {
            for (int j = 0; j < c; j++)
                map[i][j] = ' ';
        }
    }
    // cout << map[0];

    printMap();
    start();
    cout << treasure << endl;
}