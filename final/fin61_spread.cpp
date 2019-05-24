#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int pointing[100010];
vector<int> number[100010];
int n, weight = 0;
int lastweight = -1;
int sec = 0;

// list<pair<int, pair<int, int>>> a = {{1, {1, 2}}, {5, {2, 3}}, {4, {1, 2}}, {0, {2, 2}}};

void Union(int a, int b, int w, int *dis)
{
    int aa = a, bb = b;
    a = pointing[a], b = pointing[b];
    if (a != b)
    {
        // if(max(dis[aa],dis[bb]))
        // if(w!=lastweight)
        //     weight += 1;
        if (lastweight < w)
            sec++;
        lastweight = w;
        weight += w;
        // cout << "round " << sec <<" : " << w << endl;
        if (number[a].size() < number[b].size())
            swap(a, b);
        while (!number[b].empty())
        {
            int num = number[b].back();
            number[b].pop_back();
            number[a].push_back(num);
            pointing[num] = a;
        }
    }
}

int main()
{
    int q, a, b, w;
    vector<pair<int, int>> edge;
    vector<int> nodePairs[100010];
    cin >> n >> q;
    int dis[n];
    for (int i = 0; i < n; i++)
        cin >> dis[i];
    //initial
    for (int i = 0; i < n; i++)
    {
        pointing[i] = i;
        number[i].push_back(i);
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        a--, b--;
        edge.push_back(make_pair(w, i));
        nodePairs[i].push_back(a);
        nodePairs[i].push_back(b);
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++)
    {
        int order = edge[i].second;
        int a = nodePairs[order][0];
        int b = nodePairs[order][1];
        int w = edge[i].first;
        Union(a, b, w, dis);
    }
    cout << weight << endl;
    cout << sec << endl;
}

