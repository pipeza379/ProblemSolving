#include <iostream>
#include <string>
using namespace std;

int main()
{
    string path;
    int x = 0, y = 0;
    cin >> path;
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == 'N')
            y += 1;
        else if (path[i] == 'S')
            y -= 1;
        else if (path[i] == 'E')
            x += 1;
        else if (path[i] == 'W')
            x -= 1;
        else if (path[i] == 'Z')
        {
            x = 0;
            y = 0;
        }
    }
    cout << x << " " << y << endl;
}