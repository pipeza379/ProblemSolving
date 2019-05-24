bool visited[101] = {0};
int c = 0;
int layer[101];

void bfs(int s)
{
    for (int i=0;i<n+2;i++){
        layer[i]=-1;
    }
    layer[s] = 0;
    list<int> Q;
    Q.push_back(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop_front();
        visited[u] = true;
        cout << u + 1 << " : " << node[u][0] << ", " << node[u][1] << endl;
        for (int d = 0; d < deg[u]; d++)
        {
            int v = adj[u][d];
            cout << ">> "<< v << " : " << node[v][0] << ", " << node[v][1] << endl;
            // if (visited[v] == false)
            if (layer[v] == -1)
            {
                layer[v] = layer[u] + 1;
                Q.push_back(v);
            }
        }
    }
    c += 1;
}
