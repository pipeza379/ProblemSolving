#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode *next;
    ListNode(valueType val, ListNode *next = 0) : val(val), next(next) {}
};

void append(ListNode *node, valueType inp)
{
    ListNode *data = new ListNode(inp);
    while (node->next != 0)
    {
        node = node->next;
    }
    node->next = data;
}

void move(ListNode *from, ListNode *to)
{
    if (from->val != to->val)
    {
        while (to->next != 0)
        {
            to = to->next;
        }
        to->next = from->next;
        from->next = 0;
    }
}

void printPlatform(ListNode *head)
{
    head = head->next;
    while (head->next != 0)
    {
        cout << head->val << endl;
        // cout << head->val << " ";
        head = head->next;
    }
    cout << head->val << endl;
}

int main()
{
    ListNode *head[100000];
    for (int i = 1; i <= 100000; i++)
    {
        head[i] = new ListNode(i);
    }
    int x, i, j, mx = 0;
    char sel;
    cin >> x;
    for (int n = 0; n < x; n++)
    {
        cin >> sel;
        cin >> i >> j;
        mx = max(mx, j);
        if (sel == 'N')
        {
            append(head[j], i);
        }
        else if (sel == 'M')
        {
            move(head[i], head[j]);
            // cout << "from : " << head[i]->next;
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