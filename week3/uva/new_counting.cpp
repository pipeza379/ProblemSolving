#include <iostream>
#include <cstdio>

using namespace std;

char board[101][101];

int main()
{
    int r, c;
    while (1)
    {
        scanf("%d", &r);
        if (r == 0)
            break;
        scanf("%d", &c);
        //create board
        for (int i = 0; i < r; i++)
            scanf("%s", board[i]);
        int count = 0, pos = 0, length = 0, width = 0;
        for (int i = 0; i < r; i++)
        {
            int sum_row[101];
            int tmp = 0;
            for (int j = i; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    length = r - j + 1;
                    if (board[j][k] == '1')
                    {
                        sum_row[k] += 1;
                        width++;
                    }
                    else
                        width = 0;
                    if  
                    
                }
            }
        }
    }
}