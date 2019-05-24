#include <iostream>
#include <string>
using namespace std;

int main()
{
    char opr;
    int n,x,sum;
    cin >> n;
    for(int i =0;i<n-1;i++){
        if (i==0) cin >> sum;
        cin >> opr >> x;
        if(opr =='+') sum+=x;
        else if(opr =='-') sum-=x;
    }
    cout << sum << endl;
}