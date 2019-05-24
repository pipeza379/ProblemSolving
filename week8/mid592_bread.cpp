#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

vector<int> add;
vector<int> count;
vector<int> amount;

int bst(int L, int R, int value);
int calCount(int q);
vector<int>::iterator findPos(int L, int R, int value);

int main()
{
    int N, Q, q, a, c, l;
    cin >> N >> Q;
    while (N--)
    {
        scanf("%d %d %d",&a,&c,&l);
        if (!add.empty())
        {
            vector<int>::iterator itr = findPos(0, add.size() - 1, a);
            int find = itr - add.begin();

            //sortby address
            add.insert(itr, a);
            count.insert(count.begin() + find, c);
            amount.insert(amount.begin() + find, l);
        }
        else
        {
            add.push_back(a);
            count.push_back(c);
            amount.push_back(l);
        }
    }
    while (Q--)
    {
        scanf("%d",&q);
        printf("%d\n",calCount(q));
    }
}

vector<int>::iterator findPos(int L, int R, int value)
{
    int n = (L + R) / 2;
    if (add[0] > value)
        return add.begin();
    else if (add[add.size() - 1] < value)
        return add.end();
    else if (add[n] < value && add[n + 1] > value || add[n] == value)
        return add.begin() + n + 1; //**fix for count
    else if (add[n] > value)
        return findPos(L, n, value);
    else if (add[n] < value)
        return findPos(n + 1, R, value);
}

int bst(int L, int R, int value)
{
    int n = L + (R - L) / 2;
    if (R >= L)
    {
        // cout << n << endl;
        if (add[n] > value)
            return bst(L, n - 1, value);
        else if (add[n] == value)
            return n;
        else if (add[n] < value)
            return bst(n + 1, R, value);
    }
    return -1;
}

int calCount(int q)
{
    int co = 1000001, n, tmp;
    int start = 1, end = 1000000000;
    if (q >= 5)
        start = q - 5;
    if (q <= 1000000000 - 5)
        end = q + 5;
    for (int i = start; i <= end; i++) //set address of Q and find address of bread
    {
        if (bst(0, add.size() - 1, i) == -1)
            continue;
        vector<int>::iterator pos = findPos(0, add.size() - 1, i);
        int p = pos - add.begin(); //position bread that possible by vector  
        
        //check min
        for (int j = p - 5; j <= p + 5; j++)
        {
            if (amount[j] <= 0 || j < 0 || j > add.size() - 1)
                continue;
            else if (abs(q - add[j]) <= 5)
            {
                tmp = co;
                co = min(co, count[j]);
                if (tmp != co)
                    n = j;
            }
        }
    }
    if (co == 1000001)
        co = 0;
    else
    {
        amount[n] -= 1;
        co = count[n];
        if (amount[n] == 0)
        {
            add.erase(add.begin() + n);
            amount.erase(amount.begin() + n);
            count.erase(count.begin() + n);
        }
    }
    return co;
}
