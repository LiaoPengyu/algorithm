#include <cstdio>
using namespace std;
struct Node {
  int data;
  Node* next;
  Node(int d) {data = d; next = NULL;}
};
bool deleteNode(Node* c) {
  if(c || c->next) return false;
  Node *tmp = c->next;
  c->data = tmp->data;
  c->next = tmp->next;
  return true;
}

void deleteMidNode(Node* head) {
  // delete the floor(len/2) th node
  if(head==NULL) return;
  Node *p1, *p2;
  p1 = p2 = head;
  while(true) {
    if(p2->next==NULL || p2->next->next==NULL) break;
    p2 = p2->next->next;
    p1 = p1->next;
  }
  deleteNode(p1);
}
