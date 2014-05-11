#include <stack>
#include <iterator>
#include <exception>
using namespace std;

class EmptyException:exception {};

template<typename T>
class MyQueue {
 private:
  stack<T> s1, s2;
 public:
  int size() {
    return s1.size() + s2.size();
  }
  void add(T val) {
    s1.push(val);
  }
  T peek() throw(EmptyException) {
    if(s2.empty()) {
      if(s1.empty()) throw EmptyException();
      while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    return s2.top();
  }
  T remove() throw(EmptyException) {
    if(s2.empty()) {
      if(s1.empty()) throw EmptyException();
      while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    T ret = s2.top();
    s2.pop();
    return ret;
  }
};
