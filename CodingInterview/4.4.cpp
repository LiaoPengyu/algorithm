#include <cstdio>
#include <vector>
using namespace std;
struct Node {
  Node *l, *r;
  int data;
  Node(int d):data(d) {}
};
vector<vector<Node*> *> *findLevelLinkList(Node *tree) {
  vector<vector<Node*> *> *result = new vector<vector<Node*> *>();
  vector<Node*> *list = new vector<Node*>();
  list->push_back(tree);
  result->push_back(list);
  while(!list->empty()) {
    vector<Node*> *newlist = new vector<Node*>();
    for(vector<Node*>::iterator i=list->begin(); i!=list->end(); i++) {
      if((*i)->l != NULL) newlist->push_back((*i)->l);
      if((*i)->r != NULL) newlist->push_back((*i)->r);
    }
    result->push_back(newlist);
    list = newlist;
  }
  return result;
}
void createTree(Node *root, int now, int n) {
  if(now>=n) return;
  Node *l = new Node(now+1);
  Node *r = new Node(now+1);
  root->l = l;
  root->r = r;
  createTree(l, now+1, n);
  createTree(r, now+1, n);
}
int main() {
  Node *tree = new Node(1);
  createTree(tree, 1, 5);
  vector<vector<Node*> *> *ret = findLevelLinkList(tree);
  for(vector<vector<Node*> *>::iterator i=ret->begin(); i!=ret->end(); i++) {
    for(vector<Node*>::iterator j=(*i)->begin(); j!=(*i)->end(); j++) {
      printf("%d ", (*j)->data);
    }
    delete *i;
    printf("\n");
  }
  delete ret;
  return 0;
}
