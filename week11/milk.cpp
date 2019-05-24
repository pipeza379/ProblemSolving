#include <iostream>
#include <vector>

using namespace std;

int pointing[100005];
vector<int> number[100005];
int n;

void print(int a)
{
    a = pointing[a];
    for (int i = 0; i < number[a].size(); i++)
        cout << number[a][i] + 1 << " ";
    cout << endl;
}

void point()
{
    for (int i = 0; i < n; i++)
        cout << i + 1 << ": " << pointing[i] + 1 << endl;
}

void Union(int a, int b)
{
    a = pointing[a], b = pointing[b];
    if (a != b)
    {
        if (number[a].size() < number[b].size())
            swap(a, b);
        while (!number[b].empty())
        {
            int num = number[b].back();
            number[b].pop_back();
            number[a].push_back(num);
            pointing[num] = a;
        }
        // for (int i = 0; i < number[b].size(); i++)
        // {
        //     int num = number[b][i];
        //     number[a].push_back(num);
        //     if (num != b)
        //         pointing[num] = a;
        // }
        // pointing[b] = pointing[a];
    }
}

void find(int a, int b)
{
    if (pointing[a] == pointing[b])
        cout << "yes\n";
    else
        cout << "no\n";
}

int main()
{
    int q, a, b;
    char sel;
    cin >> n >> q;

    //initial
    for (int i = 0; i < n; i++)
    {
        pointing[i] = i;
        number[i] = vector<int>(1, i);
    }

    while (q--)
    {
        scanf(" %c %d %d", &sel, &a, &b);
        a--, b--;
        if (sel == 'c')
            Union(a, b);
        else if (sel == 'q')
            find(a, b);
    }
}