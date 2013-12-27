#include <cstdio>
#include <cstring>
using namespace std;
int const N = 30010;
int dp[N], c, n, v;
int main() {
  while(~scanf("%d", &n)) {
    memset(dp, 0, sizeof(dp));
    c = 0;
    while(n--) {
      scanf("%d", &v);
      for(int i=0; i<c; i++)
        if(v <= dp[i]) {dp[i] = v, v=0; break;}
      if(v) dp[c++] = v;
    }
    printf("%d\n", c);
  }
  return 0;
}
