#include <cstdio>
using namespace std;
struct Node {
  int data;
  Node* next;
  Node(int d) {data = d; next = NULL;}
};
Node *nthToLast(Node *head, int n) {
  // count from 0
  // i.e nthToLast(head, 0) return the last Node(not NULL)
  Node *p1, *p2;
  p1=p2=head;
  for(int i=0; i<=n; i++)
    if(p2==NULL) return NULL;
    else p2=p2->next;
  while(p2!=NULL) {
    p1=p1->next;
    p2=p2->next;
  }
  return p1;
}
