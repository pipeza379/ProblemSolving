#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int gifts[n];
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> gifts[i];
    }
    for (int j = 0; j < n; j++)
    {
        if (gifts[j] > 0)
            value += gifts[j];
    }
    cout << value << endl;
}