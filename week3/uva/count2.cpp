#include <iostream>
#include <string>

using namespace std;

char board[101][101];

int main()
{

    while (1)
    {
        int r, c;
        cin >> r;
        if (r == 0)
            break;
        cin >> c;

        //create board;
        for (int i = 0; i < r; i++)
            cin >> board[i];

        int count = 0;
        //create pattern

        for (int j = 1; j <= r; j++)
        {
            // for (int i = 1; i <= c; i++)
            // {
            // cout << "j: " << j << " i: " << i << endl;
            int sub_count[101] = {};
            //fig size & sequence
            for (int y = j; y < r; y++)
            {
                for (int x = 0; x < c; x++)
                {
                    sub_count[]   
                    // cout << "\ty: " << y << " x: " << x << endl;
                    if (board[y + j - 1][x + i - 1] == '1')
                        sub_count += 1;
                }
            }
            if (sub_count == r * c)
                count += 1;
            // }
        }
        cout << count << endl;
    }
}