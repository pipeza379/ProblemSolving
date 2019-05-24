#include <iostream>
#include <string>

using namespace std;

int r, c;
int count = 0, good = 0, best = 0;
bool ore[2] = {0};
void printMap(char **map)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << map[i][j];
        cout << endl;
    }
}

int path(char **map, int x, int y)
{
    if ((x >= 0 && x < c) && (y >= 0 && y < r))
    {
        if (map[y][x] == '#' || map[y][x] == 'X')
            return 0;
        if (map[y][x] == '*')
            ore[0] = true;
        if (map[y][x] == '$')
            ore[1] = true;
        count += 1;
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
        path(map, x - 1, y);
        path(map, x, y + 1);
        path(map, x + 1, y);
        path(map, x, y - 1);
    }
}

void start(char **map)
{
    for (int j = 0; j < r; j++)
    {
        for (int i = 0; i < c; i++)
        {
            if (map[j][i] != '#' && map[j][i] != 'X')
            {
                // cout << "\nStart\n";
                path(map, i, j);
                if (ore[0] && ore[1])
                    best += count;
                else if (ore[0] || ore[1])
                    good += count;
                count = 0;
                ore[0] = false, ore[1] = false;
            }
        }
    }
}

int main()
{
    cin >> r >> c;
    char *map[r];
    //create map
    for (int i = 0; i < r; i++)
        map[i] = new char[10];
    for (int i = 0; i < r; i++)
        cin >> map[i];

    int count = 0;
    start(map);
    // cout << "best: " << best;
    // cout << "good: " << good;
    cout << best << " " << good << endl;
}