#include <iostream>
using namespace std;

typedef int valueType;

struct ListNode{
  valueType val;
  ListNode* next;
  ListNode* prev;

  ListNode(valueType val,ListNode* next=0,ListNode* prev=0):val(val),next(next),prev(prev){}
};

int main(){
    int inp,x,y;
    cin >> inp;
    ListNode *pool[inp];
    ListNode *first = new ListNode(0);
    for(int i=1;i<=inp;i++){
        pool[i] = new ListNode(i);
    }
    for(int i=0;i<inp-1;i++){
        ListNode *first = new ListNode(0);
        cin >> x >> y;
        if (pool[y] -> next != 0){
            ListNode* tmp = pool[x];
            ListNode* last = pool[y]->next;
            while (tmp->next !=0) {
                tmp = tmp->next;
            }
            tmp -> next = last;
            last -> prev = tmp;
        }
        pool[y] -> next = pool[x];
        pool[x] -> prev = pool[y];
    }
    first = pool[y];
    while(first->prev !=0) first=first->prev;
    while(first->next !=0){
        cout << first-> val << " ";
        first = first->next;
    }
    cout << first->val << endl;
}
