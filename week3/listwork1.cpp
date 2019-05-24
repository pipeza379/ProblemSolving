#include <iostream>
using namespace std;

typedef int valueType;

struct ListNode{
  valueType val;
  ListNode* next;

  ListNode(valueType val,ListNode* next=0):val(val),next(next){}
};

void insertFront(ListNode* header,valueType inp){
  ListNode *data = new ListNode(inp);
  if(header->next!=0) data-> next = header->next;
  header-> next = data;
}

void delNode(ListNode* node,int pos){
  ListNode* tmp;
  if (node->val >= pos){
    node->val -=1;
    for(int i=0;i<pos;i++){
      tmp = node;
      node = node -> next;
    }
    tmp -> next = 0;
    if(node -> next !=0) {
      tmp -> next = node -> next;
      node -> next = 0;
    }
  }
}

void print_list(ListNode* node)
{
  node = node -> next;
  while(node != 0) {
    cout << node->val << endl;;
    node = node->next;
  }
}

int main() {
  int x,inp;
  char cmd;
  ListNode* header = new ListNode(0);
  cin >> x;
  for(int i=0;i<x;i++){
    cin >> cmd >> inp;
    if (cmd=='I'){
      insertFront(header,inp);
      header->val +=1;
    }
    else if (cmd=='D') delNode(header,inp);//input = position that you want to del
  }
  print_list(header);
}