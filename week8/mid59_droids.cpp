#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m, past = 0, sum_r = 0;
vector<int> droids, busy;

// int findR(int L, int R, int value, vector<int> droids);
// int findPos(int L, int R, int value, vector<int> droids);
// void sortInput();
void print(vector<int> droids);

int main()
{
    scanf("%d %d", &n, &m);
    // sortInput();
    int pos_adr, it, R, L;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pos_adr);
        it = 0, L = 0, R = droids.size() - 1;
        while (1)
        {
            int n = (L + R) / 2;
            if (R == -1 || droids[0] > pos_adr)
                break;
            else if (droids[droids.size() - 1] < pos_adr)
            {
                it = droids.size();
                break;
            }
            else if ((droids[n] < pos_adr && droids[n + 1] > pos_adr) || droids[n] == pos_adr)
            {
                it = n + 1;
                break;
            }
            else if (droids[n] > pos_adr)
                R = n - 1;
            else if (droids[n] < pos_adr)
                L = n + 1;
        }
        droids.insert(it + droids.begin(), pos_adr);
        busy.push_back(0);
        // print(droids);
    }

    while (m--)
    {
        int x, find = 0;
        scanf("%d", &x);
        // int find = findR(0, droids.size() - 1, x, droids);
        L = 0, R = droids.size() - 1;
        while (1)
        {
            if (R >= L)
            {
                int n = (L + R) / 2;
                if (droids[0] >= x)
                    break;
                else if (droids[droids.size() - 1] <= x)
                {
                    find = droids.size() - 1;
                    break;
                }
                else if (droids[n] <= x && droids[n + 1] > x)
                {
                    if (droids[n + 1] - x < x - droids[n])
                        find = n + 1;
                    else if (x - droids[n] <= droids[n + 1] - x)
                        find = n;
                    break;
                }
                else if (droids[n] > x)
                    R = n - 1;
                else if (droids[n] < x)
                    L = n + 1;
            }
        }

        // cout << "b: " << *(busy.begin() + find) << endl;
        if (*(busy.begin() + find))
        {
            if (find == 0)
                find += 1;
            else if (find == droids.size() - 1)
                find -= 1;
            else if (x - *(droids.begin() + find - 1) <= *(droids.begin() + find + 1) - x)
                find -= 1;
            else
                find += 1;
        }
        int r = abs(x - *(droids.begin() + find));
        *(busy.begin() + past) = 0; //set last droids is not busy
        *(busy.begin() + find) = 1; //round current
        past = find;
        // cout << *(droids.begin() + find) << ", " << r << endl;
        sum_r += r;
    }
    printf("%d\n", sum_r);
}

// void sortInput()
// {
//     int pos_adr, it;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &pos_adr);
//         it = findPos(0, droids.size() - 1, pos_adr, droids);
//         droids.insert(it + droids.begin(), pos_adr);
//         busy.push_back(0);
//         // print(droids);
//     }
// }
// int findR(int L, int R, int value, vector<int> droids)
// {
//     if (R >= L)
//     {
//         int n = (L + R) / 2;
//         if (droids[0] >= value)
//             return 0;
//         else if (droids[droids.size() - 1] <= value)
//             return droids.size() - 1;
//         else if (droids[n] <= value && droids[n + 1] > value)
//         {
//             if (droids[n + 1] - value < value - droids[n])
//                 return n + 1;
//             else if (value - droids[n] <= droids[n + 1] - value)
//                 return n;
//         }
//         else if (droids[n] > value)
//             return findR(L, n - 1, value, droids);
//         else if (droids[n] < value)
//             return findR(n + 1, R, value, droids);
//     }
// }

// int findPos(int L, int R, int value, vector<int> add)
// {
//     int n = (L + R) / 2;
//     if (R == -1 || add[0] > value)
//         return 0;
//     else if (add[add.size() - 1] < value)
//         return add.size();
//     else if ((add[n] < value && add[n + 1] > value) || add[n] == value)
//         return n + 1;
//     else if (add[n] > value)
//         return findPos(L, n - 1, value, add);
//     else if (add[n] < value)
//         return findPos(n + 1, R, value, add);
// }

void print(vector<int> droids)
{
    for (int i = 0; i < droids.size(); i++)
        cout << droids[i] << " ";
    cout << endl;
}
