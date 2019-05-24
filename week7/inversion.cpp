#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

long long count_ivs = 0;

void print(vector<long long> sort)
{
    long long len = sort.size();
    for (long long i = 0; i < len - 1; i++)
        cout << sort[i] << " ";
    cout << sort[sort.size() - 1] << endl;
}

vector<long long> merge(vector<long long> left, vector<long long> right)
{
    long long L = 0, R = 0;
    long long len_left = left.size(), len_right = right.size();
    vector<long long> mrg;
    for (long long n = 0; n < len_left + len_right; n++)
    {
        if (L == len_left)
        {
            mrg.push_back(right[R]);
            R++;
        }
        else if (R == len_right)
        {
            mrg.push_back(left[L]);
            L++;
        }
        else if (left[L] <= right[R])
        {
            mrg.push_back(left[L]);
            L++;
        }
        else if (right[R] < left[L])
        {
            count_ivs += len_left - L;
            mrg.push_back(right[R]);
            R++;
        }
    }
    return mrg;
}

vector<long long> mergeSort(vector<long long> list)
{
    int  len = list.size();
    if (len == 1)
        return list;
    vector<long long> tmp_left, tmp_right, mrg;
    for (long long i = 0; i < len; i++)
    {
        if (i < len / 2)
            tmp_left.push_back(list[i]);
        else
            tmp_right.push_back(list[i]);
    }
    tmp_left = mergeSort(tmp_left);
    tmp_right = mergeSort(tmp_right);
    // print(tmp_fst);
    // print(tmp_sec);
    mrg = merge(tmp_left, tmp_right);
    // print(mrg);
    return mrg;
}

int main()
{
    long long x, num;
    vector<long long> pool, sort;
    cin >> x;
    while (x--)
    {
        // ios::sync_with_stdio(false); //8;p8;p8;8p;8p8;p8;8p8;p8;8p;8p8;8p8;p8;8p8;8p;8p8;p8;p
        //create list of number this you want to sort with merge sort
        cin >> num;
        pool.push_back(num);
    }
    sort = mergeSort(pool);
    // print(sort);
    cout << count_ivs << endl;
}