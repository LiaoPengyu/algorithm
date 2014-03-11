#include <cstdio>
struct Node {
  Node *l, *r, *p;
  int data;
};
Node *leftMost(Node *e) {
  if(e==NULL) return NULL;
  while(e->l) e=e->l;
  return e;
}
Node *inorderSucc(Node *e) {
  if(e==NULL) return NULL;
  if(e->r)
    return leftMost(e->r);
  else {
    while(e->p)
      if(e->p->r == e) e=e->p;
      else break;
    return e->p;
  }
}
