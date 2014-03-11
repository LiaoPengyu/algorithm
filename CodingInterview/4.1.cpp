#include <cstdio>
#include <algorithm>
using namespace std;
struct Node {
  int data;
  Node *l, *r;
  Node():l(NULL), r(NULL) {};
  Node(int d):data(d), l(NULL), r(NULL) {};
};
int maxDep(Node *root, int dep) {
  if(root == NULL) return dep;
  return max(maxDep(root->l, dep+1), maxDep(root->r, dep+1));
}
int minDep(Node *root, int dep) {
  if(root == NULL) return dep;
  return min(maxDep(root->l, dep+1), maxDep(root->r, dep+1));
}
bool isBalanced(Node *tree) {
  return maxDep(tree, 0) - minDep(tree, 0) <= 1;
}
