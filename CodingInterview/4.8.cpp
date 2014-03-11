#include <cstdio>
#include <vector>
using namespace std;
struct Node {
  Node *l, *r;
  int data;
};
void print(vector<int> buffer, int index) {
  for(int i=buffer.size(); i>=index; i--)
    printf("%d ", buffer[i]);
  printf("\n");
}
void findSum(int sum, Node* root, vector<int> buffer) {
  if(root==NULL) return;
  buffer.push_back(root->data);
  int tmp = sum;
  for(int i=buffer.size(); i>=0; i--) {
    tmp-=buffer[i];
    if(sum==0) print(buffer, i);
  }
  vector<int> b1(buffer);
  vector<int> b2(buffer);
  findSum(sum, root->l, b1);
  findSum(sum, root->r, b2);
}
