#include <iostream>
#include <string>

using namespace std;

bool end_path = false;
bool find_out = false;
// bool find_start = false;
int r, c;

void printMap(char **map)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << map[i][j];
        cout << endl;
    }
    cout << endl;
}

int move(char **map, int UL0, int UL1, int UR0, int UR1, int DL0, int DL1, int DR0, int DR1)
{
    //UR,UL,DR,DL
    // cout << "from: " << UL0 << UL1 << " " << UR0 << UR1 << endl;
    // cout << "      " << DL0 << DL1 << " " << DR0 << DR1 << endl;

    printMap(map);
    //check end
    if (DL0 + 1 == r && DR0 + 1 == r)
    {
        find_out = true;
        // cout << "find" << endl;
        return 0;
    }
    if (find_out)
        return 0;

    // down
    if (DL0 + 1 < r)
    {
        if (map[DL0 + 1][DL1] == '.' && map[DR0 + 1][DR1] == '.') // || map[DR0 + 1][DL1] == 'X')) || (map[DL0 + 1][DL1] == '.' || (map[DL0 + 1][DL1] == 'X') && (map[DR0 + 1][DL1] == '.')))
        {
            // cout << " down\n";
            int tmp_UL0 = UL0, tmp_UL1 = UL1;
            int tmp_UR0 = UR0, tmp_UR1 = UR1;
            int tmp_DL0 = DL0, tmp_DL1 = DL1;
            int tmp_DR0 = DR0, tmp_DR1 = DR1;
            tmp_UL0 += 1, tmp_UR0 += 1;
            tmp_DL0 += 1, tmp_DR0 += 1;
            map[tmp_DL0][tmp_DL1] = 'X', map[tmp_DR0][tmp_DR1] = 'X';
            move(map, tmp_UL0, tmp_UL1, tmp_UR0, tmp_UR1, tmp_DL0, tmp_DL1, tmp_DR0, tmp_DR1);
        }
    }
    // left
    if (UL1 - 1 >= 0)
    {
        if (map[UL0][UL1 - 1] == '.' && map[DL0][DL1 - 1] == '.')
        {
            // cout << " left\n";
            int tmp_UL0 = UL0, tmp_UL1 = UL1;
            int tmp_UR0 = UR0, tmp_UR1 = UR1;
            int tmp_DL0 = DL0, tmp_DL1 = DL1;
            int tmp_DR0 = DR0, tmp_DR1 = DR1;

            tmp_UL1 -= 1, tmp_UR1 -= 1;
            tmp_DL1 -= 1, tmp_DR1 -= 1;
            map[tmp_UL0][tmp_UL1] = 'X', map[tmp_DL0][tmp_DL1] = 'X';
            move(map, tmp_UL0, tmp_UL1, tmp_UR0, tmp_UR1, tmp_DL0, tmp_DL1, tmp_DR0, tmp_DR1);
        }
    }
    // right
    if (UR1 + 1 < c)
    {
        if (map[UR0][UR1 + 1] == '.' && map[DR0][DR1 + 1] == '.')
        {
            // cout << " right\n";
            int tmp_UL0 = UL0, tmp_UL1 = UL1;
            int tmp_UR0 = UR0, tmp_UR1 = UR1;
            int tmp_DL0 = DL0, tmp_DL1 = DL1;
            int tmp_DR0 = DR0, tmp_DR1 = DR1;

            tmp_UL1 += 1, tmp_UR1 += 1;
            tmp_DL1 += 1, tmp_DR1 += 1;
            map[tmp_UR0][tmp_UR1] = 'X', map[tmp_DR0][tmp_DR1] = 'X';
            move(map, tmp_UL0, tmp_UL1, tmp_UR0, tmp_UR1, tmp_DL0, tmp_DL1, tmp_DR0, tmp_DR1);
        }
    }
    // up
    if (UL0 - 1 >= 0)
    {
        if (map[UL0 - 1][UL1] == '.' && map[UR0 - 1][UR1] == '.')
        {
            // cout << " up\n";
            int tmp_UL0 = UL0, tmp_UL1 = UL1;
            int tmp_UR0 = UR0, tmp_UR1 = UR1;
            int tmp_DL0 = DL0, tmp_DL1 = DL1;
            int tmp_DR0 = DR0, tmp_DR1 = DR1;

            tmp_UL0 -= 1, tmp_UR0 -= 1;
            tmp_DL0 -= 1, tmp_DR0 -= 1;
            map[tmp_UL0][tmp_UL1] = 'X', map[tmp_UR0][tmp_UR1] = 'X';
            move(map, tmp_UL0, tmp_UL1, tmp_UR0, tmp_UR1, tmp_DL0, tmp_DL1, tmp_DR0, tmp_DR1);
        }
    }
    // cout << "endway\n";
    return 0;
}

void start(char **map)
{
    bool find_start = true;
    while (find_start)
    {
        for (int i = 0; i < c - 1; i++)
        {
            if (map[0][i] == '.' && map[0][i + 1] == '.' && map[1][i] == '.' && map[1][i + 1] == '.')
            {
                int UL[2] = {0, 0}, UR[2] = {0, 1};
                int DL[2] = {1, 0}, DR[2] = {1, 1};
                find_start = true;
                UL[1] += i, UR[1] += i;
                DL[1] += i, DR[1] += i;
                map[0][i] = 'X', map[0][i + 1] = 'X';
                map[1][i] = 'X', map[1][i + 1] = 'X';
                int UL0 = UL[0], UL1 = UL[1];
                int UR0 = UR[0], UR1 = UR[1];
                int DL0 = DL[0], DL1 = DL[1];
                int DR0 = DR[0], DR1 = DR[1];

                // cout << "start: " << UL0 << UL1 << " " << UR0 << UR1 << endl;
                // cout << "       " << DL0 << DL1 << " " << DR0 << DR1 << endl;
                move(map, UL0, UL1, UR0, UR1, DL0, DL1, DR0, DR1);
            }
        }
        find_start = false;
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

    //start //00 01 10 11
    //checkstart
    start(map);
    // printMap(map);
    if (find_out)
        cout << "yes\n";
    else
        cout << "no\n";
}
