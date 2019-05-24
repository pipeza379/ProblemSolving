#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, t, checkpoint, total_time = 0;
    cin >> n >> m; //map,video
    int map[n];
    for (int i = 0; i < n; i++)
        map[i] = 1000000;
    for (int i = 0; i < m; i++)
    {
        cin >> checkpoint >> t;
        checkpoint--;
        map[checkpoint] = min(map[checkpoint], t);
    }   
    for (int i = 0; i < n; i++)
        total_time += map[i];
    cout << total_time << endl;
    for (int i = 0; i < n; i++)
        cout <<i+1 << " " << map[i] << endl;
}