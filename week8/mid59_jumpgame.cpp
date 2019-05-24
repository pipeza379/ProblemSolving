#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<pair<int, int>> adj[21][21];
// vector<int> adj[21][21];
int map[21][21] = {0}, degree[21][21] = {0};
int n;
bool visited[21][21] = {0};
bool goal = false;

void createMap();
void connectMap(int power);
void print();
void bfs();

int main()
{
    int power;
    cin >> n >> power;
    createMap();
    connectMap(power);
    // print(); // case push map;
    bfs();
    if (goal)
        cout << "yes\n";
    else
        cout << "no\n";
}

void bfs()
{
    list<pair<int, int>> Q;
    int r, c;
    Q.push_back(make_pair(0, 0));
    while (!Q.empty())
    {
        r = Q.front().first, c = Q.front().second;
        Q.pop_front();
        if (r == n - 1 && c == n - 1)
        {
            goal = true;
            break;
        }
        visited[r][c] = true;
        for (int i = 0; i < degree[r][c]; i++)
        {
            int Qr = adj[r][c][i].first;
            int Qc = adj[r][c][i].second;
            if (!visited[Qr][Qc])
                Q.push_back(make_pair(Qr, Qc));
        }
    }
}

void createMap()
{
    int val;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> val;
            map[i][j] = val;
        }
    }
}

void connectMap(int power)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (c + 1 < n && (map[r][c + 1] - map[r][c] <= power)) //right
            {
                // adj[r][c].push_back(map[r][c + 1]);
                adj[r][c].push_back(make_pair(r, c + 1));
                degree[r][c]++;
            }
            if (c - 1 >= 0 && (map[r][c - 1] - map[r][c] <= power)) //left
            {
                // adj[r][c].push_back(map[r][c - 1]);
                adj[r][c].push_back(make_pair(r, c - 1));
                degree[r][c]++;
            }
            if (r + 1 < n && (map[r + 1][c] - map[r][c] <= power)) //down
            {
                // adj[r][c].push_back(map[r + 1][c]);
                adj[r][c].push_back(make_pair(r + 1, c));
                degree[r][c]++;
            }
            if (r - 1 >= 0 && (map[r - 1][c] - map[r][c] <= power)) //up
            {
                // adj[r][c].push_back(map[r - 1][c]);
                adj[r][c].push_back(make_pair(r - 1, c));
                degree[r][c]++;
            }
        }
    }
}

// void print()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout <<"r: " << i << " c: " <<j <<endl;
//             cout << map[i][j] << ": ";
//             for (int k = 0; k < adj[i][j].size(); k++)
//                 cout << adj[i][j][k] << " ";
//             cout <<endl;
//         }
//         cout <<endl;
//     }
// }