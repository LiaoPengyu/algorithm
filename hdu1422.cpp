#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
int const N = 100010;
int n, w, l, d[N<<1], sum, ANS, i, j;
int main() {
  while(~scanf("%d", &n)) {
    for(i=1; i<=n; i++) scanf("%d%d", &w, &l), d[i] = d[i+n] = w-l;
    for(ANS=0, sum=0, i=j=1; i<=n;) {
      for(; sum>=0 && j-i<n; j++) sum += d[j];
      ANS = max(ANS, j-i-(sum>=0? 0: 1));
      if(ANS >= n) break;
      for(; sum<0 && i<=n; i++) sum -= d[i];
    }
    printf("%d\n", ANS);
  }
  return 0;
}
