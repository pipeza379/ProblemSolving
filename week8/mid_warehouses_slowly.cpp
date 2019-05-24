#include <iostream>
#include <vector>
#include <list>
#include <cstdio>

using namespace std;

int n, m, k;
vector<int> adj[100010];
int deg[100010] = {0};
// bool visited_s[100010], visited_g[100010];
bool visited[100010];

// void read_input();
// bool bfs(int s, int goal);
void print();
// int bst(int L, int R, int u, int v);

int main()
{
    // read_input();
    cin >> n >> m >> k;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        // cin >> u >> v;
        --u, --v;
        // if (!(adj[u].empty()) && !(adj[v].empty()))
        // {
        //     int findU = -1;
        //     int L = 0, R = adj[v].size() - 1;
        //     while (1)
        //     {
        //         int n = L + (R - L) / 2;
        //         if (R >= L)
        //         {
        //             if (adj[v][n] > u)
        //                 R = n - 1;
        //             else if (adj[v][n] == u)
        //             {
        //                 findU = n;
        //                 cout << "find\n";
        //                 break;
        //             }
        //             else if (adj[v][n] < u)
        //                 L = n + 1;
        //         }
        //         break;
        //     }
        //     int findV = -1;
        //     cout << "U: " << findU << endl;
        //     L = 0, R = adj[u].size() - 1;
        //     while (1)
        //     {
        //         int n = L + (R - L) / 2;
        //         if (R >= L)
        //         {
        //             if (adj[u][n] > v)
        //                 R = n - 1;
        //             else if (adj[u][n] == v)
        //             {
        //                 findV = n;
        //                 cout << "findV\n";
        //                 break;
        //             }
        //             else if (adj[u][n] < v)
        //                 L = n + 1;
        //         }
        //         break;
        //     }
        //     cout << "V: " << findV << endl;
        //     // if (bst(0, adj[u].size() - 1, u, v) != -1 && bst(0, adj[v].size() - 1, v, u) != -1)
        //     if (findU != -1 && findV != -1)
        //         continue;
        // }

        if (u == v)
            continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
        // print();
        count++;
    }

    // print();
    int s, g;
    while (k--)
    {
        scanf("%d %d", &s, &g);
        // cin >> s >> g;
        --s, --g;
        bool fin = false;
        int count = 0;
        for (int x = 0; x < n; x++)
            visited[x] = false;
        if (!visited[s])
        {
            list<int> Q;
            Q.push_back(s);
            while (!Q.empty())
            {
                count++;
                if (count > n)
                {
                    fin = false;
                    break;
                }
                int u = Q.back();
                Q.pop_back();
                if (u == g)
                {
                    fin = true;
                    break;
                }
                visited[u] = true;
                for (int d = 0; d < deg[u]; d++)
                {
                    int v = adj[u][d];
                    if (v == g)
                    {
                        fin = true;
                        break;
                    }
                    if (visited[v] == false)
                        Q.push_back(v);
                }
            }
        }
        printf("%d\n", (fin ? 1 : 0));
    }
}

// void read_input()
// {
//     cin >> n >> m >> k;
//     int count = 0;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         scanf("%d %d", &u, &v);
//         // cin >> u >> v;
//         --u, --v;
//         if (!(adj[u].empty()) && !(adj[v].empty()))
//         {
//             if (bst(0, adj[u].size() - 1, u, v) != -1 && bst(0, adj[v].size() - 1, v, u) != -1)
//                 continue;
//         }
//         if (u == v)
//             continue;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         deg[u]++;
//         deg[v]++;
//         // print();
//         count++;
//     }
// }

// bool bfs(int s, int g)
// {
//     // cout << "node: " << s << " , " << visited[s] << endl;
//     for (int x = 0; x < n; x++)
//     {
//         visited_s[x] = false;
//         visited_g[x] = false;
//     }
//     if (!visited_s[s])
//     {
//         list<int> Q;
//         list<int> QG;
//         Q.push_back(s);
//         QG.push_back(g);
//         if (s == g)
//             return true;
//         while (!Q.empty())
//         {
//             if (QG.empty())
//                 break;
//             int u = Q.front();
//             Q.pop_front();
//             int x = QG.front();
//             QG.pop_front();
//             visited_s[u] = true;
//             visited_g[x] = true;
//             // cout << "s: " << u + 1 << " g: " << x + 1 << endl;
//             if (visited_g[u] || visited_s[x])
//                 return true;
//             for (int d = 0; d < deg[u]; d++)
//             {
//                 int v = adj[u][d];
//                 // cout << "u: " << v + 1 << "\n";
//                 if (visited_s[v] == false)
//                     Q.push_back(v);
//             }
//             for (int d = 0; d < deg[x]; d++)
//             {
//                 int v = adj[x][d];
//                 // cout << "x: " << v + 1 << "\n";
//                 if (visited_g[v] == false)
//                     QG.push_back(v);
//             }
//         }
//     }
//     return false;
// }

// bool bfs(int s, int goal)
// {
//     // cout << "node: " << s << " , " << visited[s] << endl;
//     int count = 0;
//     for (int x = 0; x < n; x++)
//         visited[x] = false;
//     if (!visited[s])
//     {
//         list<int> Q;
//         Q.push_back(s);
//         while (!Q.empty())
//         {
//             count++;
//             if (count > n)
//                 return false;
//             int u = Q.back();
//             Q.pop_back();
//             if (u == goal)
//                 return true;
//             visited[u] = true;
//             for (int d = 0; d < deg[u]; d++)
//             {
//                 int v = adj[u][d];
//                 if (v == goal)
//                     return true;
//                 if (visited[v] == false)
//                     Q.push_back(v);
//             }
//         }
//     }
//     return false;
// }

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << " " << adj[i][j] + 1;
        }
        cout << endl;
    }
}

// int bst(int L, int R, int u, int v)
// {
//     int n = L + (R - L) / 2;
//     if (R >= L)
//     {
//         // cout << n << endl;
//         if (adj[u][n] > v)
//             return bst(L, n - 1, u, v);
//         else if (adj[u][n] == v)
//             return n;
//         else if (adj[u][n] < v)
//             return bst(n + 1, R, u, v);
//     }
//     return -1;
// }