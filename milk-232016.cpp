#include <iostream>
#include <vector>

using namespace std;

int pointing[100000];
vector<int> number[100000];
int n;

void print(int a)
{
    a = pointing[a];
    for (int i = 0; i < number[a].size(); i++)
    {
        cout << number[a][i] + 1 << " ";
    }
    cout << endl;
}

void point()
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": " << pointing[i] << endl;
    }
}

void Union(int a, int b)
{
    if (pointing[a] != pointing[b])
    {
        // cout << "Union\n";
        for (int i = 0; i < number[pointing[b]].size(); i++)
        {
            // cout << "round " << i << endl;
            int num = number[pointing[b]][i];
            number[pointing[a]].push_back(num);
            if (num != b)
                pointing[num] = pointing[a];
        }
        pointing[b] = pointing[a];
        // cout << number[pointing[a]].size() << endl;
        // point();
        // print(a);
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
        number[i].push_back(i);
    }

    while (q--)
    {
        scanf(" %c %d %d",&sel,&a,&b);
        // cin >> sel >> a >> b;
        a--, b--;
        if (sel == 'c')
        {
            Union(a, b);
        }
        else if (sel == 'q')
        {
            find(a, b);
        }
    }
}