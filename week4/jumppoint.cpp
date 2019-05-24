#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX_N 1010

int n, r;
vector<pair<int, int>> node;
vector<int> adj[MAX_N];
vector<pair<int, pair<int, int>>> Q;
int deg[MAX_N] = {0};

void read_input()
{
    cin >> n >> r;
    //initial start,goal
    node.push_back(make_pair(0, 0));

    for (int i = 1; i < n + 1; i++)
    {
        int x, y;
        cin >> x >> y;
        node.push_back(make_pair(x, y));
    }
    node.push_back(make_pair(100, 100));
}

void connectGraph()
{
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = i + 1; j < n + 2; j++)
        {
            if (pow(node[i].first - node[j].first, 2) + pow(node[i].second - node[j].second, 2) <= pow(r, 2))
            {
                // cout << node[i].first << "," << node[i].second;
                // cout << " : " << node[j].first << "," << node[j].second << endl;
                adj[i].push_back(j);
                adj[j].push_back(i);
                deg[i]++;
                deg[j]++;
            }
        }
    }
}

int jump = 10010;
int count_jump[MAX_N];
bool found = false;
void serchDFS(int s, bool *visited, int count)
{
    bool tmp_visited[MAX_N] = {0};
    visited[s] = true;

    //copy visited
    for (int i = 0; i < n + 2; i++)
        tmp_visited[i] = visited[i];

    count++;
    count_jump[s] = min(count_jump[s], count);
    if (node[s].first == 100 && node[s].second == 100)
    {
        found = true;
        jump = min(jump, count);
        return;
    }

    if (count > (ceil(100 / r) * 3))
        return;

    for (int d = 0; d < deg[s]; d++)
    {
        int v = adj[s][d];
        // cout << "now " << node[s].first << ", " << node[s].second << ">> " << node[v].first << ", " << node[v].second << " visited : " << visited[v] << endl;
        if (visited[v] == false && (count_jump[s] + 1 < count_jump[v]))
        {
            // cout << count_jump[s] << " v: " << count_jump[v];
            // cout << " from " << node[s].first << ", " << node[s].second << ">> " << node[v].first << ", " << node[v].second << " count : " << count + 1 << endl;
            serchDFS(v, tmp_visited, count);
        }
    }
    return;
}

int main()
{
    // clock_t tStart = clock();
    bool visited[MAX_N] = {0};
    int count = -1;
    for (int i = 0; i < MAX_N; i++)
    {
        count_jump[i] = 10000;
    }
    read_input();
    connectGraph();
    serchDFS(0, visited, count);
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    if(found)
        cout << jump << endl;
    else cout << "-1" << endl;
}