#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int,int> intpair;

int main()
{
    int n;
    int x, y;
    multiset<intpair> schedule;

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",&x,&y);
        schedule.insert(make_pair(y,x)); //last first
    }
    // sort(schedule.begin(),schedule.end());
    int count = 0;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        auto s = schedule.begin();
        x = s->second, y = s->first;
        schedule.erase(schedule.begin());
        if (x >= last)
        {
            // cout << x << " " << y << endl;
            count++ ;
            last = y;
        }
    }
    printf("%d\n",count);
}