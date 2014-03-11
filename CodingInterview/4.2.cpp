#include <stack>
using namespace std;
struct Node {
  int to, next;
} Tree[400];
int H[20];
bool v[20] = {};
// ...
bool search(int start, int end) {
  if(start == end) return true;
  stack<int> s;
  s.push(start);
  while(!s.empty()) {
    int tmp = s.top();
    v[tmp] = true;
    s.pop();
    for(int i=H[tmp]; ~i; i=Tree[i].next) {
      if(Tree[i].to == end) return true;
      if(!v[Tree[i].to]) s.push(tmp);
    }
  }
  return false;
}
