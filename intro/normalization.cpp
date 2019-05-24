#include <iostream>

using namespace std;

int min(int a, int b)
{
    return (a <= b) ? a : b;
}

int main()
{
    int a, b, mn;
    int i = 2;
    cin >> a >> b;
    if(a >1 && b>1){
    mn = min(a, b);
    while(i <= mn){
        if (a%i==0 && b%i==0) {
            a /= i;
            b /= i;
        }
        else i++;
    }
    cout << a << "/" << b << endl;
    }
}