#include <iostream>
#include <set>
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
        schedule.insert(make_pair(x,y)); //last first
    }
    // sort(schedule.begin(),schedule.end());
    int sum = 0,day=0;
    // int last = 0;
    for (int i = 0; i < n; i++)
    {
        auto s = schedule.begin();
        x = s->first, y = s->second;
        schedule.erase(schedule.begin());
        day+=y;
        sum += day>x+10 ? (day-x-10)*1000 : 0;
    }
    printf("%d\n",sum);
}