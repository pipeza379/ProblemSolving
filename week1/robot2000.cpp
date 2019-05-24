#include <iostream>
#include <string>
using namespace std;

char convertCommand(char i, char f)
{
    if ((i == 'N' && f == 'E') || (i == 'E' && f == 'S') || (i == 'S' && f == 'W') || (i == 'W' && f == 'N'))
        cout << "RF";
    else if ((i == 'N' && f == 'S') || (i == 'E' && f == 'W') || (i == 'S' && f == 'N') || (i == 'W' && f == 'E'))
        cout << "RRF";
    else if ((i == 'N' && f == 'W') || (i == 'E' && f == 'N') || (i == 'S' && f == 'E') || (i == 'W' && f == 'S'))
        cout << "RRRF";
    else if ((i == 'N' && f == 'N') || (i == 'E' && f == 'E') || (i == 'S' && f == 'S') || (i == 'W' && f == 'W'))
        cout << "F";
    return f;
}

void start(char i)
{
    if (i == 'N')
        cout << "F";
    else if (i == 'E')
        cout << "RF";
    else if (i == 'S')
        cout << "RRF";
    else if (i == 'W')
        cout << "RRRF";
}

int main()
{
    string path;
    cin >> path;
    char initial, fin;
    for (int i = 0; i < path.size(); i++)
    {
        if (i == 0)
        {
            initial = path[0];
            start(initial);
            continue;
        }
        if (initial == 'Z')
        {
            cout << "Z";
            initial = 'N';
        }
        fin = path[i];
        initial = convertCommand(initial, fin);
    }
    cout << endl;
}