#include <stack>
using namespace std;
class StackWithMin: public stack<int> {
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
