#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> set;
int x, y;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        set.push_back(make_pair(x, y));
        set.begin();
    }
}

vector<int>::iterator findPos(int L, int R, int y)
{
    int n = (L + R) / 2;
    if (R >= L)
    {
        if (set[n].first > x)
            return findPos(L, n - 1, y);
        else if (set[n].first == x)
        {
        }
        else if (set[n].first < x)
            return findPos(n + 1, R, y);
    }
    return set.begin();
}

