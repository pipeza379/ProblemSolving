#include <iostream>
#include <cstdio>

using namespace std;
int a, b, n;
char map[21][21];

void print(bool **visited)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
            cout << visited[r][c];
        cout << endl;
    }
    cout << endl;
}

bool path(bool **visited, int x, int y, bool door)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n))
    {
        // cout << "path : x, "<< x+1 << " y, " << y+1 <<endl;
        if (x == b && y == a)
            return true;
        if (map[y][x] == '#' || visited[y][x] == 1 || (map[y][x] == 'O' && !door))
            return false;
        if (map[y][x] == 'O' && door)
            door = 0;
        visited[y][x] = 1;
        // print(visited);
        bool found = (path(visited, x + 1, y, door) || path(visited, x - 1, y, door) || path(visited, x, y - 1, door) || path(visited, x, y + 1, door));
        return found;
    }
    return false;
}

int main()
{
    int q, r, c;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        scanf("%s", map[i]);
    bool *visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = new bool[n];
    while (q--)
    {
        scanf("%d %d %d %d", &r, &c, &a, &b);
        --a, --b;

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
                visited[j][i] = 0;
        }
        // print(map);
        if (path(visited, --c, --r, 1))
            printf("yes\n");
        else
            printf("no\n");
    }
}