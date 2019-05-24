#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, r, c;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> r >> c;
        num = (r / 3) * (c / 3);
        cout << num << endl;
    }
}