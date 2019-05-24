#include <iostream>
#include <vector>
#include <set>
#include <iterator>

#define MAX_N 100005
#define LONG_PATH 1000000100

using namespace std;

vector<int> adj[MAX_N];
vector<int> length[MAX_N];
int n, m;

bool visited[MAX_N] = {0};
int d[MAX_N];
multiset<pair<int, int>> pool;

void dijkstra(int s)
{
    for (int i = 0; i < n; i++)
        d[i] = LONG_PATH;

    d[s] = 0;
    pool.insert(make_pair(0, s));
    for (int i = 0; i < n; i++)
    {
        auto pos = pool.begin();
        int best = pos->second;
        pool.erase(pos);
        for (int i = 0; i < adj[best].size(); i++)
        {
            // cout << "i: " << adj[best][i] << endl;
            int v = adj[best][i];
            int len = length[best][i];
            if (!visited[v] && ((d[best] + len) < d[v]))
            {
                pool.insert(make_pair(d[best] + len, v));
                d[v] = d[best] + len;
            }
        }

        visited[best] = true;
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        a--, b--;
        adj[a].push_back(b);
        length[a].push_back(w);
        adj[b].push_back(a);
        length[b].push_back(w);
    }

    dijkstra(0);
    cout << d[n - 1] << endl;
    // for (auto i = d.begin(); i != d.end(); i++)
    // {
    //     if (i->second == n - 1)
    //     {
    //         // cout << i->first << " " << i->second << endl;
    //         cout << i->first << endl;
    //         break;
    //     }
    // }
}