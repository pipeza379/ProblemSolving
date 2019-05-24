#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode *last;
    ListNode *next;
    ListNode(valueType val, ListNode *last = 0, ListNode *next = 0) : val(val), last(last), next(next) {}
};

void append(ListNode *head, valueType inp)
{
    ListNode *data = new ListNode(inp);
    if (head->next == 0)
        head->next = data;
    else
    {
        // cout << "last val" << head->last->val;
        head->last->next = data;
    }
    head->last = data;
}

void move(ListNode *from, ListNode *to)
{
    if (from->val != to->val && from->next != 0)
    {
        if (to->next == 0)
            to->next = from->next;
        else
            to->last->next = from->next;
        to->last = from->last;
        from->next = 0;
        from->last = 0;
    }
}

void printPlatform(ListNode *head)
{
    // while (head->next != 0)
    while (head->next != 0)
    {
        head = head->next;
        // cout << head->val << endl;
        cout << head->val << " ";
    }
    cout << endl;
}

int main()
{
    ListNode *head[100001];
    int x, i, j;
    char sel;
    cin >> x;
    vector<int> len;
    for (int n = 0; n < x; n++)
    {
        cin >> sel >> i >> j;
        if (head[j] == 0)
            head[j] = new ListNode(j);
        len.push_back(j);
        if (sel == 'N')
            append(head[j], i);
        else if (sel == 'M')
        {
            if (head[i] == 0)
                head[i] = new ListNode(i);
            move(head[i], head[j]);
        }
        sort(len.begin(), len.end());
        len.erase(unique(len.begin(), len.end()), len.end());
        for (auto i : len)
        {
            cout << "[" << i << "] ";
            printPlatform(head[i]);
        }
    }
    //print
    sort(len.begin(), len.end());
    len.erase(unique(len.begin(), len.end()), len.end());
    for (auto i : len)
        // cout << i << " ";
        printPlatform(head[i]);
}
