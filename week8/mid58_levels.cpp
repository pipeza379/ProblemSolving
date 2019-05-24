#include <iostream>
#include <vector>

using namespace std;
int n, m;
bool clear[100][3];
int now = 0;
vector<int> level[100];
vector<int> inp;
void check();

int main()
{
    cin >> n >> m;
    int d, g, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> d >> g >> b;
        level[i].push_back(d); //distance
        level[i].push_back(g); //gifts
        level[i].push_back(b); //bonus
    }   
    while (m--)
    {
        cin >> d >> g >> b;
        inp.clear();
        inp.push_back(d);
        inp.push_back(g);
        inp.push_back(b);
        check();
        // cout << now + 1 << endl;
    }
    cout << now + 1 << endl;
}

void check()
{
    if (now + 1 != n)
    {
        for (int i = 0; i < 3; i++)
        {
            if (inp[i] >= level[now][i])
                clear[now][i] = true;
        }
        if (clear[now][0] && clear[now][1] && clear[now][2])
            now++;
    }
}