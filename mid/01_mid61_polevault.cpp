#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
vector<int> order;

int print(vector<int> *order)
{
    for (int i = 0; i < (*order).size(); i++)
        cout << (*order)[i] << " ";
    cout << endl;
}

int main()
{
    int n, a, x, sum = 0, find;
    long long int q;
    scanf("%d %lld",&n,&q);
    vector<int> box;

    while (n--)
    {
        scanf("%d",&x);
        if (order.empty())
        {
            order.push_back(x);
            box.push_back(x);
        }
        else
        {
            box.push_back(x);
            for (long long int i = 0; i < box.size(); i++)
            {
                find = -1;
                int L = 0, R = order.size() - 1;
                if (i < box.size()-1)
                    box[i] += x;
                int value = box[i];
                while (1)
                {
                    int r = (L + R) / 2;
                    if (order[0] > value)
                    {
                        find = 0;
                        break;
                    }
                    else if (order[order.size() - 1] < value)
                    {
                        find = order.size();
                        break;
                    }
                    else if (order[r] == box[i])
                    {
                        find = -1;
                        break;
                    }
                    else if (order[r] < value && order[r + 1] > value)
                    {
                        find = r + 1;
                        break;
                    }
                    else if (order[r] > value)
                        R = r;
                    else if (order[r] < value)
                        L = r + 1;
                }
                if (find != -1)
                    order.insert(order.begin() + find, value);
            }
        }
    }
    long long int value;
    while (q--)
    {
        scanf("%lld",&value);
        find = -1;
        int L = 0, R = order.size() - 1;
        while (1)
        {
            int n = L + (R - L) / 2;
            if (R >= L)
            {
                if (order[n] > value)
                    R = n - 1;
                else if (order[n] == value)
                {
                    find = n;
                    break;
                }
                else if (order[n] < value)
                    L = n + 1;
            }
            else
                break;
        }

        if (find != -1)
            printf("Y");
        else
            printf("N");
    }
    cout << endl;
}