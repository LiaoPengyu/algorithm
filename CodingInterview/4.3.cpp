#include <cstdio>
struct Node {
  Node *l, *r;
  int data;
  Node(int d): data(d) {}
};
Node* addToTree(int *arr, int root, int len) {
  if(root>len) return NULL;
  Node *r = new Node(arr[root-1]);
  r->l = addToTree(arr, root<<1, len);
  r->r = addToTree(arr, root<<1|1, len);
  return r;
}
Node* createTree(int *arr, int len) {
  return addToTree(arr, 1, len);
}

Node* addToBSTree(int *arr, int s, int e) {
  if(s>=e) return NULL;
  int mid = (s+e)>>1;
  Node *r = new Node(arr[mid]);
  r->l = addToBSTree(arr, s, mid-1);
  r->r = addToBSTree(arr, mid+1, e);
  return r;
}
Node* createBSTree(int *arr, int len) {
  return addToBSTree(arr, 0, len);
}
