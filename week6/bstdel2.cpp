#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;
int value;

vector<int>::iterator findPos(int L, int R)
{
    int n = (L + R) / 2;
    // cout << n << endl;
    if (tree[0] > value)
        return tree.begin();
    else if (tree[tree.size() - 1] < value)
        return tree.end();
    else if (tree[n] > value && tree[n - 1] < value || tree[n] == value)
        return tree.begin() + n;
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
void del()
{
    vector<int>::iterator pos = findPos(0, tree.size() - 1);
    if (*pos == value)
        tree.erase(pos);
}

void print()
{
    for (int i = 0; i < tree.size(); i++)
        cout << tree[i] << " ";
    cout << endl;
}

int main()
{
    int r, cmd;
    vector<int>::iterator check;
    cin >> r;
    while (r--)
    {
        cin >> cmd >> value;
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
                cout << ((*check == value) ? 1 : 0) << endl;
            }
            else
                cout << 0 << endl;
        }
        else if (cmd == 3 && !tree.empty())
            del();
        // cout << "len " << tree.size() << endl;
    }
}