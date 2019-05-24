#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    cin >> n;
    int item[n];
    int count[3] = {},price[3]={p1,p2,p3};
    for (int i = 0; i < n; i++)
    {
        cin >> item[n];
        switch (item[n])
        {
        case 1:
            count[0] += 1;
            break;
        case 2:
            count[1] += 1;
            break;
        case 3:
            count[2] += 1;
            break;
        default:
            break;
        }
    }
    for(int j=0;j<3;j++){
        price[j] = price[j]*count[j];
    }
    cout << min(price[0],min(price[1],price[2])) << endl;
}
