#include <stack>
using namespace std;
void sort(stack<int> *s) {
  stack<int> s2;
  while(!s->empty()) {
    int tmp = s->top();
    s->pop();
    while(!s2.empty() && s2.top() > tmp) {
      s->push(s2.top());
      s2.pop();
    }
    s2.push(tmp);
    while(!s->empty() && s->top() > s2.top()) {
      s2.push(s->top());
      s->pop();
    }
  }
  while(!s2.empty()) {
    s->push(s2.top());
    s2.pop();
  }
}
