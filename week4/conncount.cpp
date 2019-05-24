#include <iostream>
#include <vector>
#include <list>

using namespace std;

int n, m;
vector<int> adj[100010];
int deg[100010];

void read_input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        deg[i] = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        deg[u]++;
        adj[v].push_back(u);
        deg[v]++;
    }
}
bool visited[100010] = {0};
int count = 0;
void bfs(int s)
{
    // cout << "node: " << s << " , " << visited[s] << endl;
    if (!visited[s])
    {
        list<int> Q;
        Q.push_back(s);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop_front();
            visited[u] = true;
            // cout << u + 1 << ", " << layer[u] << endl;

            for (int d = 0; d < deg[u]; d++)
            {
                int v = adj[u][d];
                if (visited[v] == false)
                    Q.push_back(v);
            }
        }
        count += 1;
    }
}

int main()
{
    read_input();
    for (int i = 0; i < n; i++)
        bfs(i);
    cout << count << endl;
}