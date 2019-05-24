#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

void print(vector<int> sort)
{
    int len = sort.size();
    for (int i = 0; i < len-1; i++)
        cout << sort[i] << " ";
    cout << sort[sort.size()-1] << endl;
}

vector<int> merge(vector<int> fst, vector<int> sec)
{
    int L = 0, R = 0;
    int len_fst = fst.size(), len_sec = sec.size();
    vector<int> mrg;
    for (int n = 0; n < len_fst + len_sec; n++)
    {
        // cout << L << " " << R;
        // cout << "push ";
        if (L == len_fst)
        {
            // cout << sec[R] << endl;
            mrg.push_back(sec[R]);
            R++;
        }
        else if (R == len_sec)
        {
            // cout << fst[L] << endl;
            mrg.push_back(fst[L]);
            L++;
        }
        else if (fst[L] <= sec[R])
        {
            // cout << fst[L] << endl;
            mrg.push_back(fst[L]);
            L++;
        }
        else if (sec[R] < fst[L])
        {
            // cout << sec[R] << endl;
            mrg.push_back(sec[R]);
            R++;
        }
    }
    return mrg;
}

vector<int> mergeSort(vector<int> list)
{
    int len = list.size();
    if (len <= 2)
    {
        int tmp;
        if ((list[0] > list[1]) && len == 2)
        {
            tmp = list[0];
            list[0] = list[1];
            list[1] = tmp;
        }
        return list;
    }
    vector<int> tmp_fst, tmp_sec, mrg;
    for (int i = 0; i < len; i++)
    {
        if (i < len / 2)
            tmp_fst.push_back(list[i]);
        else
            tmp_sec.push_back(list[i]);
    }
    tmp_fst = mergeSort(tmp_fst);
    tmp_sec = mergeSort(tmp_sec);
    // print(tmp_fst);
    // print(tmp_sec);
    print(tmp_fst);
    print(tmp_sec);
    mrg = merge(tmp_fst, tmp_sec);
    // tmp_fst.erase(tmp_fst.begin(), tmp_fst.end());
    // tmp_sec.erase(tmp_sec.begin(), tmp_sec.end());
    return mrg;
}

int main()
{
    int x;
    vector<int> pool, sort;
    while (1)
    {
        ios::sync_with_stdio(false);
        cin >> x;
        if (x == 0)
            break;
        int num, tmp1 = x;

        //create list of number this you want to sort with merge sort
        while (tmp1--)
        {
            ios::sync_with_stdio(false);
            cin >> num;
            pool.push_back(num);
        }

        sort = mergeSort(pool);
        print(sort);
        sort.erase(sort.begin(), sort.end());
        pool.erase(pool.begin(), pool.end());
    }
}