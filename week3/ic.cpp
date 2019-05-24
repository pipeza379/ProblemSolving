#include<iostream>
#include<string>

using namespace std;
typedef int valueType;

struct ListNode
{
    valueType x;
    ListNode* next;
    ListNode(valueType x,ListNode* next=0):x(x),next(next){}
};

struct HeadNode
{
    ListNode* last;
    ListNode* next;
    HeadNode(ListNode* last=0,ListNode* next=0):last(last),next(next){}
};

class LinkedList
{
  private:
    HeadNode *header;
    void free_list();

  public:
    LinkedList();
    ~LinkedList();
    void print_list();
    void insert(valueType x,string sel);
    void rotate(string sel);
};

LinkedList::LinkedList()
{
    header = new HeadNode;
}

LinkedList::~LinkedList()
{
    free_list();
}

void LinkedList::free_list()
{
    ListNode *node = header->next;
    while (node != header->last)
    {
        ListNode *tmp = node;    
        node = node->next;
        delete tmp;
    }
}

void LinkedList::rotate(string sel)
{
    if (header->next != 0){
        ListNode *tmp;
        ListNode *tmp2;

        if(sel=="lr"){
            tmp = header-> next;
            header-> last = header-> next;
            header-> next = tmp->next;
        }        
        else if(sel=="rr"){       
            tmp = header-> last;
            header-> next = header->last;
            do{
                tmp2=tmp;
                // cout << "check" << tmp->x << endl;
                tmp=tmp->next;
            }
            while(tmp != header->last);
            header-> last = tmp2;
        }
    }
    // print_list();
}

void LinkedList::insert(valueType x,string sel)
{
    ListNode *data = new ListNode(x);
    if (header->next == 0){
        header->next = data;
        header->last = data;
        data->next = header->last;
        }
    else if(sel=="ri"){
        header->last->next = data;
        header->last = data;
        data-> next = header->next;
    }
    else if(sel=="li"){
        header->last->next = data;
        data->next = header->next;
        header->next = data;
    }
    // print_list();
}

void LinkedList::print_list()
{
    ListNode *node = header->next;
    while (node != header->last)
    {
        cout << node->x << endl;
        node = node->next;
    }
    cout << node->x << endl;
}

int main(){
    LinkedList list;
    int s;
    cin >> s;
    for(int i=0;i<s;i++){
        string sel;
        int x;
        cin >> sel;
        if (sel=="ri"||sel=="li"){
            cin >> x;
            list.insert(x,sel);
        }
        else if (sel=="rr"||sel=="lr") list.rotate(sel);        
        // list.print_list();
    }
    list.print_list();
}