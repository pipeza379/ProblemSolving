#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> challenger;
int win[4];

void inputChallen();
void roundFinal();

int main()
{
    inputChallen();
    roundFinal();
    for (int i = 0; i < 4; i++)
        cout << win[i] + 1 << " ";
    cout << endl;
}

void inputChallen()
{
    int n, skill;
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        vector<pair<int, int>> competitor;
        for (int j = 0; j < n; j++)
        {
            cin >> skill;
            competitor.push_back(make_pair(skill, i * n + j));
        }
        auto it = max_element(competitor.begin(), competitor.end());
        challenger.push_back(make_pair((*it).first, (*it).second));
    }
}

void roundFinal()
{
    vector<pair<int, int>> winer;
    for (int i = 0; i < 2; i++)
    {
        auto fst = challenger[2*i];
        auto sec = challenger[2 * i + 1];
        if (fst.first > sec.first)
        {
            winer.push_back(make_pair(fst.first, fst.second));
            win[i + 2] = sec.second;
        }
        else
        {
            winer.push_back(make_pair(sec.first, sec.second));
            win[i + 2] = fst.second;
        }
    }
    if (winer[0].first > winer[1].first)
        win[0] = winer[0].second, win[1] = winer[1].second;
    else
        win[0] = winer[1].second, win[1] = winer[0].second;
}