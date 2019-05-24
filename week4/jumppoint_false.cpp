#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
int n, R, count_min = -1;

int calDistance(int x, int y, int x2, int y2)
{
    if (x2 >= x || y2>=y)
        return sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
}

void jump(int x, int y, vector<int> *tree, int count)
{
    //x,y is now position
    vector<int> tmp_tree[n];
    for (int j = 0; j < n; j++)
    {
        tmp_tree[j].push_back(tree[j][0]);
        tmp_tree[j].push_back(tree[j][1]);
    }

    // for(int j = 0 )
    for (int i = 0; i < n; i++)
    {
        int distance;

        // cout << i << " Tree: \n";
        // for (int k = 0; k < n; k++)
        //     cout << tree[k][0] << " " << tree[k][1] << endl;
        // cout << "x : " << x << " y: " << y << endl;

        distance = calDistance(x, y, tree[i][0], tree[i][1]);
        if (R >= calDistance(x, y, 100, 100))
        {
            count++;
            count_min = (count_min == -1) ? count : min(count, count_min);
            // cout << "count_min: " << count_min << endl;
            return;
        }
        else if (R >= distance && tmp_tree[i][0] != -1 && tree[i][1] != -1)
        {
            // cout << "ok\n";
            tmp_tree[i][0] = -1, tmp_tree[i][1] = -1;
            // cout << tree[i][0] << " " << tree[i][1] << " count: " << count+1 << endl;
            jump(tree[i][0], tree[i][1], tmp_tree, count + 1);
        }
    }
}

int main()
{
    int x, y, count = -1;
    int pos[2] = {0, 0}; //set default
    cin >> n >> R;
    vector<int> tree[n];

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        tree[i].push_back(x);
        tree[i].push_back(y);
    }
    jump(0, 0, tree, 0);
    cout << count_min << endl;
}