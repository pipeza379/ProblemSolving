#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int num;

vector<int> merge(vector<int> fst, vector<int> sec)
{
    int L = 0, R = 0;
    int len_fst = fst.size(), len_sec = sec.size();
    vector<int> mrg;
    for (int n = 0; n < len_fst + len_sec; n++)
    {
        if (L == len_fst)
        {
            mrg.push_back(sec[R]);
            R++;
        }
        else if (R == len_sec)
        {
            mrg.push_back(fst[L]);
            L++;
        }
        else if (fst[L] <= sec[R])
        {
            mrg.push_back(fst[L]);
            L++;
        }
        else if (sec[R] < fst[L])
        {
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
    mrg = merge(tmp_fst, tmp_sec);
    return mrg;
}

void bst(vector<int> pool, int i, int f) //initial ,final
{
    int nf = (f + i) / 2;
    // cout << "nf: " << pool[nf] << " " << i << " " << f << endl;
    if (pool[nf] == num)
        cout << pool.size() - nf - 1 << endl;
    else if (nf == i || nf == f)
        cout << 0 << endl;
    else if (pool[nf] > num)
        bst(pool, i, nf);
    else if (pool[nf] < num)
        bst(pool, nf, f);
}

int main()
{
    int x, sel, pos;
    vector<int> pool, sort;
    cin >> x;
    while (x--)
    {
        cin >> sel >> num;
        if (sel == 1)
            pool.push_back(num);
        else if (sel == 2)
        {
            pool = mergeSort(pool);
            bst(pool, -1, pool.size());
        }
    }
}