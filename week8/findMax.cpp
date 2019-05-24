#include <iostream>
#include <vector>

using namespace std;
vector<int> order;
vector<int>::iterator
// find_pos_max(int L, int R, int value, vector<int> order)
// {
//     int n = (L + R) / 2;
//     cout << L << " " << R << " " << value << " " << n << endl;
//     if (R >= L)
//     {
//         if (R == 0 || order[0] < value)
//             return order.begin();
//         else if (order[order.size() - 1] > value)
//             return order.end();
//         else if (order[n - 1] > value && order[n] <= value)
//         {
//             cout << "test\n";
//             return order.begin() + n; //**fix for count
//         }
//         else if (order[n] > value)
//             return find_pos_max(n + 1, R, value, order);
//         else if (order[n] < value)
//             return find_pos_max(L, n - 1, value, order);
//     }
// }

find_pos_max(int L, int R, int value, vector<int> *order)
{
    int n = (L + R) / 2;
    cout << L << " " << R << " " << value << " " << n << endl;
    if (R >= L)
    {
        if (R == 0 || (*order)[0] < value)
            return (*order).begin();
        else if ((*order)[(*order).size() - 1] > value)
            return (*order).end();
        else if ((*order)[n - 1] > value && (*order)[n] <= value)
        {
            cout << "test\n";
            return (*order).begin() + n; //**fix for count
        }
        else if ((*order)[n] > value)
            return find_pos_max(n + 1, R, value, order);
        else if ((*order)[n] < value)
            return find_pos_max(L, n - 1, value, order);
    }
}

void print(vector<int> order)
{
    for (int i = 0; i < order.size(); i++)
        cout << order[i] << " ";
    cout << endl;
}

int main()
{
    // vector<int> order;

    int n = 1;
    while (n != 0)
    {
        cin >> n;
        auto itr = find_pos_max(0, order.size(), n, &order);
        if (itr == order.end())
            cout << "check\n";
        cout << "pass\n";
        order.insert(itr, n);
        print(order);
    }
}