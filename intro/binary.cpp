//#include<stdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int out[100]; // we will keep the remainders here.
    int d = 0;    // we will use d to count the number of times we divide n

    int n;
    cin >> n;
    do
    {
        out[d] = n % 2;
        n = n/2;
        d++;
    } while (n > 0);
    for(int i=d-1;i>=0;i--){
        cout << out[i];
    }
    cout << endl;
}