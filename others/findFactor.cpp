#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> s;
void find_factor(int sum, int n) {
  // print factor that sum of them equal the `sum` from sequence 1,2...n
  if(sum<=0 || n<=0) return;
  if(sum == n) {
    for(int i=0; i<s.size(); i++)
      printf("%d + ", s[i]);
    printf("%d\n", n);
  }
  s.push_back(n);
  find_factor(sum-n, n-1);
  s.pop_back();
  find_factor(sum, n-1);
}
