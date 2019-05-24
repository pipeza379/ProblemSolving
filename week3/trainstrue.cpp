#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

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
        // cout << head->val << " ";
        // cout << head->val << endl;
        printf("%d\n",head->val);   
    }
    // cout << endl;
}

int main()
{
    ListNode *head[100000];
    for (int k = 1; k <= 100000; k++)
        head[k] = new ListNode(k);
    int x, i, j, mx = 0;
    char sel;
    scanf("%d", &x);
    // cin >> x;
    for (int n = 0; n < x; n++)
    {
        // cin >> sel;
        // cin >> i >> j;
        scanf(" %c", &sel);
        scanf("%d %d", &i, &j);
        mx = max(mx, j);
        if (sel == 'N')
            append(head[j], i);
        else if (sel == 'M')
        {
            move(head[i], head[j]);
        }
        // for (int c = 1; c <= mx; c++)
        //     if (head[c]->next != 0)
        //     {
        //         cout << "[" << c << "] ";
        //         printPlatform(head[c]);
        //     }
    }
    //print
    for (int c = 1; c <= mx; c++)
        if (head[c]->next != 0)
        {
            // cout << "[" << c << "] ";
            printPlatform(head[c]);
        }
}