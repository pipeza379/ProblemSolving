#include <iostream>
#include <cstdlib>

using namespace std;

typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode *next;

    ListNode(valueType val, ListNode *next = 0)
        : val(val), next(next) {}
};

void print_list(ListNode *node)
{
    while (node != 0)
    {
        cout << node->val << endl;
        node = node->next;
    }
}

void insert_front(ListNode *header, valueType x)
{
    ListNode *data = new ListNode(x);
    data->next = header->next;
    header->next = data;
}

void free_list(ListNode *&header)
{
    // if (header->next == NULL)
    //     delete header;
    // else
    // {
    //     free_list(header->next);
    //     delete header;
    // }
    while(header->next != 0){
        ListNode *tmp = header;
        header = header->next;
        delete tmp;
    }
}

int main()
{
    ListNode *first_header = 0;
    for (int i = 0; i < 2; i++)
    {
        ListNode *header = new ListNode(0);
        if (!first_header)
        {
            first_header = header;
        }
        for (int j = 0; j < 10; j++)
        {
            insert_front(header, j);
        }
        free_list(header);
        print_list(first_header);
    }

    ListNode *new_header = new ListNode(0);
    new_header = new ListNode(0);
    new_header = new ListNode(0);
    int dist = abs(new_header - first_header);
    if (dist < 100)
    {
        cout << "ok" << endl;
    }
    else
    {
        cout << "not ok" << endl;
    }
}