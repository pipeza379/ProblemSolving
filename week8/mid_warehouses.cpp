#include <iostream>
#include <vector>
#include <list>
#include <cstdio>

using namespace std;

int n, m, k;
vector<int> adj[100010];
vector<int> node;
int count = 0;

int findPos(int L, int R, int value, vector<int> add);
void read_input();
void print();
int bst(int L, int R, int u, int v);

int main()
{
    read_input();
    // print();
    int s, g;
    while (k--)
    {
        scanf("%d %d", &s, &g);
        // cin >> s >> g;
        s, g;
        bool fin = 0;
        for (int i = 0; i < count; i++)
        {
            if (bst(0, adj[i].size() - 1, i, s) != -1 && bst(0, adj[i].size() - 1, i, g) != -1)
                fin = 1;
        }
        printf("%d\n", (fin ? 1 : 0));
    }
}

void read_input()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        vector<int>::iterator itr;
        int u, v, ins[2];
        scanf("%d %d", &u, &v);
        if (adj[0].empty()) //for firsy
        {
            adj[0].push_back(u);
            if (u == v)
                continue;
            itr = adj[0].begin() + findPos(0, adj[0].size() - 1, v, adj[0]);
            adj[0].insert(itr, v);
            count++; //count node
        }
        else
        {
            for (int j = 0; j < count; j++)
            {
                if (adj[j].empty()) continue;
                if (bst(0, adj[j].size() - 1, j, v) != -1 && bst(0, adj[j].size() - 1, j, u) != -1) //if adj[j] have 'u' and 'v'
                    break;
                if (bst(0, adj[j].size() - 1, j, v) == -1 && bst(0, adj[j].size() - 1, j, u) != -1) //if adj have 'u' but don't have 'v'
                {
                    itr = adj[j].begin() + findPos(0, adj[j].size() - 1, v, adj[j]);
                    adj[j].insert(itr, v);
                    ins[0] = v, ins[1] = j;
                    break;
                }
                else if (bst(0, adj[j].size() - 1, j, u) == -1 && bst(0, adj[j].size() - 1, j, v) != -1) //if adj have 'v' but don't have 'u'
                {
                    itr = adj[j].begin() + findPos(0, adj[j].size() - 1, u, adj[j]);
                    adj[j].insert(itr, u);
                    ins[0] = u, ins[1] = j;
                    break;
                }
                else if (j == count - 1)
                {
                    adj[count].push_back(u);
                    if (u == v)
                        break;
                    itr = adj[count].begin() + findPos(0, adj[count].size() - 1, v, adj[count]);
                    adj[count].insert(itr, v);
                    count++;
                }
            }
            for (int j = 0; j < count; j++)
            {
                if (j == ins[1])
                    continue;
                else if (bst(0, adj[j].size() - 1, j, ins[0]) != -1)
                {
                    for (int k = 0; k < adj[j].size(); k++)
                    {
                        if (adj[j][k] == ins[0])
                            continue;
                        itr = adj[ins[1]].begin() + findPos(0, adj[ins[1]].size() - 1, adj[j][k], adj[ins[1]]);
                        adj[ins[1]].insert(itr, adj[j][k]);
                    }
                    adj[j].clear();
                }
            }
        }
        // print();
    }
}

int findPos(int L, int R, int value, vector<int> add)
{
    int n = (L + R) / 2;
    if (add[0] > value || R == -1) //head
        return 0;
    else if (add[add.size() - 1] < value) //back
        return add.size();
    else if (add[n] < value && add[n + 1] > value || add[n] == value)
        return n + 1; //**fix for count
    else if (add[n] > value)
        return findPos(L, n, value, add);
    else if (add[n] < value)
        return findPos(n + 1, R, value, add);
}

int bst(int L, int R, int u, int v)
{
    int n = L + (R - L) / 2;
    if (R >= L)
    {
        // cout << n << endl;
        if (adj[u][n] > v)
            return bst(L, n - 1, u, v);
        else if (adj[u][n] == v)
            return n;
        else if (adj[u][n] < v)
            return bst(n + 1, R, u, v);
    }
    return -1;
}

void print()
{
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}