#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode *next;
    ListNode *prev;
    ListNode(valueType val, ListNode *next = 0, ListNode *prev = 0) : val(val), next(next), prev(prev) {}
};

void revert(ListNode *chain)
{
    chain->next = chain->prev;
    chain->prev = 0;
    // cout << "check: " << chain[*now]->val << " ";
    chain = chain->next;
    while (chain->prev != 0)
    {
        ListNode *tmp = new ListNode(0);
        tmp = chain->prev;
        chain->prev = chain->next;
        chain->next = tmp;
        // cout << chain[*now]->val << " ";
        chain = chain->next;
    }
    chain->prev = chain->next;
    chain->next = 0;
    // cout << chain[*now]->val << endl;
}

void print(ListNode **pool, int num)
{
    ListNode *out = pool[num];
    while (out->next != 0)
    {
        printf("%d ",out->val);
        // cout << out->val << " ";
        out = out->next;
    }
    printf("%d\n",out->val);
    // cout << out->val << endl;
}

void event(ListNode **chain, int *now, char sel)//, int *pos)
{
    // cout << "val bef: " << *now;
    if (sel == 'F')
    {
        if (chain[*now]->next != 0)
            *now = chain[*now]->next->val;
    }
    else if (sel == 'B')
    {
        if (chain[*now]->prev != 0)
            *now = chain[*now]->prev->val;
    }
    else if (sel == 'C')
    {
        int inp;
        if (chain[*now]->next != 0)
            chain[*now]->next->prev = 0;
        scanf("%d",&inp);
        // cin >> inp;
        if (chain[inp]->next == 0 && chain[inp]->prev != 0)
        {
            // cout << "C revert\n";
            revert(chain[inp]);
        }
        chain[*now]->next = chain[inp];
        chain[inp]->prev = chain[*now];
        *now = chain[*now]->next->val;
    }

    // *now = chain[*now]->val;
    // *pos = *now;
    // cout << "val now: " << *now;
}

void createChain(ListNode **pool, int ch)
{
    ListNode *data = new ListNode(0);
    int num[2] = {0, 0}; //[0] = length ,[1]=head chain

    //create chain
    for (int i = 1; i <= ch; i++)
    {
        int tmp = 0, n = 0;
        // cin >> tmp;
        scanf(" %d",&tmp);
        num[0] += tmp;
        for (int count = num[1] + 1; count <= num[0]; count++)
        {
            pool[count] = new ListNode(count);
            if (n != 0)
            {
                data->next = pool[count];
                pool[count]->prev = data;
            }
            // cout << data->val << " - " << pool[count]->val << endl;
            data = pool[count];
            if (n == 0)
                pool[count]->prev = 0;
            n++;
        }
        // print(pool,num[1]);
        num[1] += tmp;
    }
}

int main()
{
    int ch, num_event;
    int now;
    char sel;
    ListNode *pool[100001];

    // cin >> ch >> num_event;
    scanf("%d %d\n",&ch,&num_event);
    createChain(pool, ch);
    now = 1;
    // int pos[num_event];

    for (int i = 0; i < num_event; i++)
    {
        // cin >> sel;
        scanf(" %c",&sel);
        event(pool, &now, sel);//, &pos[i]);
        
        // cout << "pos : " << now << endl; //print now position
        // printf("pos : %d\n",now);
        
        // cout << now << endl;
        printf("%d\n",now);
        // print(pool, 1);
    }
    // for (int i = 0; i < num_event; i++)
    //     cout << pos[i] << endl;
}