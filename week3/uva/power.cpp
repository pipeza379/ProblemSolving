#include <iostream>
#include <string>

using namespace std;

int next(int *region, int i, int n)
{
    int x = 0, y = n-1;
    region[x] = 0;
    // cout << "i: " << i << endl;
    while (y--)
    {
        // cout << y << endl;
        int tmp = i;
        while (tmp > 0)
        {
            if (region[(x+1)%n] == 0)
            {
                // cout << "continue ";
                x += 1;
                // cout <<"next: " << x << endl;
                continue;
            }
            x += 1;
            // cout <<"x2: " << x <<endl;
            tmp -= 1;
        }
        // x += i;
        x %= n;
        if (region[x] == 13 && y==0)
            return '0';
        // cout << "x: " << x << endl;
        // cout << y << " region : ";
        region[x] = 0;
        // for (int c = 0; c < n; c++)
        //     cout << region[c] << " ";
        // cout << endl;
    }
    // cout << "x: " << x << endl;
    return '1';
}

int main()
{
    int n = 1;
    while (n)
    {
        cin >> n;
        if (n==0) break;
        int region[n];
        int i = 1;
        char check = '1';
        int r = 10;
        while (check =='1')
        {
            for (int i = 0; i < n; i++)
                region[i] = i + 1;
            // cout << "test : ";
            // for (int c = 0; c < n; c++)
            //     cout << region[c] << " ";
            // cout << endl;

            check = next(region, i, n);
            // cout << check << endl;
            i++;
        }
        cout << i-1 << endl;
    }
}