#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> tree;
int value;

vector<int>::iterator findPos(int L, int R)
{
    int n = (L + R) / 2;
    if (tree[0] > value)
        return tree.begin();
    else if (tree[tree.size() - 1] < value)
        return tree.end();
    else if (tree[n] < value && tree[n + 1] > value || tree[n] == value)
        return tree.begin() + n + 1; //**fix for count
    else if (tree[n] > value)
        return findPos(L, n);
    else if (tree[n] < value)
        return findPos(n + 1, R);
}

void ins()
{
    if (tree.empty())
        tree.push_back(value);
    else
    {
        vector<int>::iterator it = findPos(0, tree.size() - 1);
        tree.insert(it, value);
    }
}

int main()
{
    int r, cmd;
    vector<int>::iterator check;
    scanf("%d\n", &r);
    while (r--)
    {
        scanf("%d %d", &cmd, &value);
        if (cmd == 1)
        {
            ins();
            // print();
        }
        else if (cmd == 2)
        {
            if (!tree.empty())
            {
                check = findPos(0, tree.size() - 1);
                int count = distance(check, tree.end());
                printf("%d\n",count);
            }
            else
                printf("0\n");
        }
    }
}