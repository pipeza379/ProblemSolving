#include <iostream>
#include <string>

using namespace std;

int r, c, a, b;
bool found = false;
int num = 30000;

void printMap(char **map)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << map[i][j];
        cout << endl;
    }
}

int path(char **map, int x, int y, int count)
{
    if ((x >= 0 && x < c) && (y >= 0 && y < r))
    {
        if (x == b && y == a)
        {
            found = true;
            num = min(num, count);
        }
        if (map[y][x] == '#' || map[y][x] == '*')
            return 0;
        count++;
        map[y][x] = 'X';

        //copy map
        char *copy[r];
        //create map
        for (int i = 0; i < r; i++)
            copy[i] = new char[10];
        for (int i = 0; i < r; i++)
            cin >> map[i];

        // cout << "\npath: " << x << " " << y << endl;
        // printMap(map);
        path(map, x - 1, y, count);
        path(map, x, y + 1, count);
        path(map, x + 1, y, count);
        path(map, x, y - 1, count);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    cin >> r >> c >> b >> a;
    char *map[r];
    //create map
    for (int i = 0; i < n; i++)
        map[i] = new char[q];
    for (int i = 0; i < n; i++)
        cin >> map[i];

    int count = 0;
    path(map, c, r, count);
    if (found)
        cout << num << endl;
    else
        cout << "-1" << endl;
}