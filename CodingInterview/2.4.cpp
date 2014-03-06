#include <cstdio>
using namespace std;
struct Node {
  int data;
  Node* next;
  Node(int d) {data = d; next = NULL;}
};

Node* addLists(Node *l1, Node *l2) {
  int carry = 0, val = 0;
  Node *head = new Node(0), *cur = head;
  while(l1 || l2) {
    val = carry;
    if(l1) {val+=l1->data; l1=l1->next;}
    if(l2) {val+=l2->data; l2=l2->next;}
    cur->next = new Node(0);
    cur = cur->next;
    cur->data = val % 10;
    carry = val>=10? 1: 0;
  }
  cur->next = NULL;
  cur = head->next;
  delete head;
  return cur;
}

Node* addListsRecur(Node *l1, Node *l2, int carry) {
  if(!l1 && !l2) return NULL;
  Node *cur = new Node(0);
  int val = carry;
  if(l1) {val+=l1->data; l1=l1->next;}
  if(l2) {val+=l2->data; l2=l2->next;}
  cur->data = val % 10;
  cur->next = addListsRecur(l1, l2, val>=10? 1:0);
  return cur;
}
