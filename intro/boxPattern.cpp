#include <iostream>
using namespace std;

int main()
{
    int n,val;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            val = (j+i)%n;
            if (val==0) val =n;
            cout << val;
        }
        cout<< endl;
    } 
}