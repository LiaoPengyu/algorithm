#include <cstdio>
using namespace std;
struct Node {
  int data;
  Node* next;
  Node(int d) {data = d; next = NULL;}
};
Node *FindBeginning(Node *head) {
  if(head==NULL) return NULL;
  Node *p1, *p2;
  p1 = p2 = head;
  while(p1 != p2 && p2) {
    p1 = p1->next;
    if(p2->next) p2 = p2->next->next;
    else break;
  }
  if(p2->next == NULL) return NULL;
  p1 = head;
  while(p1 != p2) {
    p1=p1->next;
    p2=p2->next;
  }
  return p2;
}
