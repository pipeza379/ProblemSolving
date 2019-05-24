#include <iostream>
#include <string>
#include <cstdio>
#include <time.h>

using namespace std;

char board[101][101];

int counting(int *pattern, int r, int c)
{

    int count = 0;

    int sy = pattern[0];
    int sx = pattern[1];
    // cout << sx << " " << sy << endl;
    //loop board
    for (int j = 0; j < r + 1 - sy; j++)
    {
        for (int i = 0; i < c + 1 - sx; i++)
        {
            // cout << "j: " << j << " i: " << i << endl;
            if (board[j][i] == '0')
                continue;
            //loop size sy,sx
            int sub_count = 0;
            bool check = true;
            for (int y = 1; y <= sy; y++)
            {
                if (!check)
                    break;
                for (int x = 1; x <= sx; x++)
                {
                    // cout << "y: " << y + j << " x: " << x + i << endl;
                    if (board[j + y - 1][i + x - 1] == '0')
                    {
                        check = false;
                        break;
                    }
                    sub_count += 1;
                }
            }
            if (sub_count == (sy * sx))
                count += 1;
            // cout << "count " << count << endl;
            // printf("count %d\n",count);
        }
    }
    // cout << endl;
    return count;
}

int main()
{
    // clock_t tStart = clock();
    int r, c;

    while (1)
    {
        scanf("%d", &r);
        if (r == 0)
            break;
        scanf("%d", &c);

        //create board;
        for (int i = 0; i < r; i++)
            scanf("%s", board[i]);
        int ro = 0;

        //create pattern
        int pattern[r * c][2];
        for (int y = 1; y <= r; y++)
        {
            for (int x = 1; x <= c; x++)
            {
                pattern[ro][0] = y;
                pattern[ro][1] = x;
                ro += 1;
            }
        }

        int count = 0;
        for (int ptn = 0; ptn < r * c; ptn++)
        {
            count += counting(pattern[ptn], r, c);
            // printf("count %d\n", count);
        }
        printf("%d\n", count);
        // printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
        // cout << count << endl;
    }
}