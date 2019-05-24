#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <list>

using namespace std;
// bool map[100][100] = {0};
// int R,min=0;

int calDistance(int *pos, int x, int y)
{
    if (x >= pos[0]) // && y >= pos[1])
        return sqrt(pow(x - pos[0], 2) + pow(y - pos[1], 2));
}

int jump(){
    
}

int main()
{
    int n, r, x, y;
    int count = 0;
    int pos[2] = {0, 0}, tmp_tree[2]; //set default
    cin >> n >> r;
    list<int> tree[n];

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        tree[i].push_back(x);
        tree[i].push_back(y);
    }
    while (1)
    {
        // cout << "pos: " << pos[0] << " " << pos[1] << endl;
        int distance = 0, max_distance = 0;
        if (calDistance(pos, 100, 100) <= r) //try to jump to goal
        {
            cout << count + 1 << endl;
            break;
        }
        for (int i = 0; i < n; i++) //find max distance
        {
            distance = calDistance(pos, tree[i][0], tree[i][1]);
            // cout << distance << " x,y: " << tree[i][0] << " " << tree[i][1] << endl;
            if (distance > max_distance && distance <= r)
            {
                max_distance = distance;
                tmp_tree[0] = tree[i][0];
                tmp_tree[1] = tree[i][1];
            }
        }
        if (max_distance == 0)
        {
            cout << "-1" << endl;
            break;
        }
        pos[0] = tmp_tree[0], pos[1] = tmp_tree[1]; // jump
        count += 1;
    }
}