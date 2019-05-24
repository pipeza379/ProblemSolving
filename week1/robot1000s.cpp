#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int direction(string path, int sel)
{
    int pos[4] = {}; //[N,E,S,W]
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == 'N')
            pos[0] += 1;
        else if (path[i] == 'E')
            pos[1] += 1;
        else if (path[i] == 'S')
            pos[2] += 1;
        else if (path[i] == 'W')
            pos[3] += 1;
    }

    //find max distance
    int lenght = path.size() - sel;
    int x = 0, y = 0, direct = 0;
    int max_y = max(pos[0], pos[2]), min_y = min(pos[0], pos[2]);
    int max_x = max(pos[1], pos[3]), min_x = min(pos[1], pos[3]);
    //if all path be positive
    if (sel >= path.size())
        return direct; //mean 0
    else if (max_x + max_y >= lenght || max_x >= lenght || max_y >= lenght)
        direct = lenght;
    else if (max_x + max_y + min_x >= lenght || max_x + max_y + min_y >= lenght)
        direct = max_x + max_y - (lenght - max_x - max_y);
    else if (max_x + min_x >= lenght)
        direct = max_x - (lenght - max_x);
    else if (max_y + min_y >= lenght)
        direct = max_y - (lenght - max_y);
    else
        direct = max_x + max_y - (lenght - max_x - max_y);
    return direct;
}

int main()
{
    string path;
    int sel;
    cin >> path;
    cin >> sel;
    int distance = direction(path, sel) * 2;
    cout << distance << endl;
}