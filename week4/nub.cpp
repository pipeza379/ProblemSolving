#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
typedef int valueType;

int count = 0;

struct ListNode
{
    valueType val;
    ListNode *last;
    ListNode *next;
    ListNode(valueType val, ListNode *last = 0, ListNode *next = 0) : val(val), last(last), next(next) {}
};

void append(ListNode *head, ListNode *tail)
{
    if (head->next == 0)
        head->next = tail;
    else
        head->last->next = tail;
    head->last = tail->last;
    tail->last = head;
}

// void print(ListNode *head)
// {
//     cout << head->val<<endl;
//     while (head->next != 0)
//     {
//         head = head->next;
//         printf("%d\n",head->val);
//     }
// }

void print(ListNode *head)
{
    ListNode *tmp = new ListNode(0);
    tmp->next = head->last;
    while (head->next != tmp->next && head->val != 0)
    {
        cout << "val: " << head->val << endl;
        head->val = 0;
        head = head->next;
        // printf("%d\n", head->val);
    }
    if (head->val != 0)
    {
        head->val = 0;
        count += 1;
    }
}

int main()
{
    // for (int k = 1; k <= 100000; k++)
    //     head[k] = new ListNode(k);
    int size, row, i, j;
    vector<int> group;
    scanf("%d %d", &size, &row);
    ListNode *head[size];
    for (int n = 0; n < row; n++)
    {
        scanf("%d %d", &i, &j);
        group.push_back(i);
        if (head[i]->val != i)
            head[i] = new ListNode(i);
        if (head[j]->val != j)
            head[j] = new ListNode(j);
        // cout << head[j] << " " << head[i];
        append(head[i], head[j]);
    }
    //print
    print(head[3]);
    // cout << group.size();
    for (auto i = group.begin(); i != group.end(); ++i)
        print(head[*i]);
    cout << count << endl;
}