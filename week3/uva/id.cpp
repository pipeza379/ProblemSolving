#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string id, tmp_id;
    while (cin >> id)
    {
        tmp_id = id;
        if (id == "#")
            break;
        if(next_permutation(id.begin(), id.end())) cout << id << endl;
        else cout << "No Successor" << endl;
    }
}