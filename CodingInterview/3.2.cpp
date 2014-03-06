#include <stack>
#include <cstdio>

using namespace std;
class StackWithMin: public stack<int> {
  // min(), pop(), push(val) O(1)
 private:
  stack<int> s2;
 public:
  StackWithMin() {}
  int min() {
    if(s2.empty()) {return 1<<20;}
    else return s2.top();
  }
  void push(int val) {
    if(val<=min()) s2.push(val);
    stack<int>::push(val);
  }
  int pop() {
    int ret = stack<int>::top();
    stack<int>::pop();
    if(ret == min()) s2.pop();
    return ret;
  }
};

struct Node {
  Node *lson, *rson, *pare;
  int val;
  Node():lson(NULL),rson(NULL),val(1<<20) {}
  Node(int val):lson(NULL),rson(NULL),val(val) {}
};
class StackWithMin2 {
 private:
  Node *s;
 public:
  StackWithMin2() {
    s = new Node();
  }
  int min() {
    if(s->rson!=NULL)
      return s->rson->val;
    else return 1<<20;
  }
  void push(int val) {
    Node *p = s;
    while(p->rson!=NULL && p->rson->val<val) {
      p = p->rson;
    }
    Node *tmp = new Node(val);
    tmp->pare = p;
    tmp->lson = p->rson;
    p->rson->pare = tmp;
    p->rson = tmp;
  }
  int pop() {
    Node *p = s;
    if(p->rson == NULL) return -1;
    while(p->rson!=NULL) p = p->rson;
    p->pare->rson = NULL;
    int ret = p->val;
    delete p;
    return ret;
  }
};

int main() {
  StackWithMin2 s;
  for(int i=9; i>4; i--) {
    s.push(i);
    s.push(i);
  }
  for(int i=9; i>4; i--) {
    printf("%d ", s.pop());
    printf("%d\n", s.min());
    printf("%d ", s.pop());
    printf("%d\n", s.min());
  }
  return 0;
}
