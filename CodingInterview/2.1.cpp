#include <cstdio>
#include <set>
#include <iterator>
using namespace std;
struct Node {
  int data;
  Node* next;
  Node(int d) {data = d; next = NULL;}
};
void deleteDups(Node* n) {
  set<int> s;
  set<int>::iterator it;
  for(Node*p=NULL, *tmp; n!=NULL;) {
    if(s.find(n->data) != s.end()) {
      p->next = n->next;
      tmp = n;
      n = n->next;
      delete tmp;
    } else {
      s.insert(n->data);
      p = n;
      n = n->next;
    }
  }
}

void deleteDupsNoBuffer(Node* n) {
  Node *pre = n, *p, *cur, *tmp;
  for(cur=n->next; cur!= NULL;) {
    for(p=n; p!=cur; p=p->next) {
      if(p->data==cur->data) {
        pre->next = cur->next;
        tmp = cur;
        cur = cur->next;
        delete tmp;
        break;
      }
    }
    if(p==cur) {
      pre=cur;
      cur=cur->next;
    }
  }
}
