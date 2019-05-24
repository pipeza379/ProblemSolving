#include <iostream>
#include <string>

using namespace std;

int area[505][505];
int count;

void markArea(int xmin, int ymin, int xmax, int ymax, int mark = 1, bool ch = true)
{
    for (int j = ymin - 1; j < ymax; j++)
    {
        for (int i = xmin - 1; i < xmax; i++)
        {
            if (ch)
                area[j][i] = mark;
            else
            {
                if (area[j][i] == 0)
                    count += 1;
            }
            // cout << area[j][i] << " ";
        }
        // cout << endl;
    }
}

int main()
{
    int r, c, n;
    while (cin >> c >> r>>n,c,r)
    {
        count = 0;
        markArea(1, 1, c, r, 0);
        while (n--)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2)
                swap(x1, x2);
            if (y1 > y2)
                swap(y1, y2);
            markArea(x1, y1, x2, y2);
        }
        markArea(1, 1, c, r, 0, false);
        if (count == 0)
            cout << "There is no empty spots.\n";
        else if (count == 1)
            cout << "There is one empty spot.\n";
        else
            cout << "There are " << count << " empty spots.\n";
        // cout << count << endl;
    }
}