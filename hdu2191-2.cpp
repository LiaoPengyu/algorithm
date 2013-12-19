#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
int const MN = 101;
int C, n, m, p, h, c, i, j, s, tp, th, dp[MN];
inline void bagcom() {for(j=tp; j<=n; j++) dp[j] = max(dp[j], dp[j-tp]+th);}
inline void bag01() {for(j=n; j>=tp; j--) dp[j] = max(dp[j], dp[j-tp]+th);}
int main() {
  scanf("%d", &C);
  while(C--) {
    scanf("%d%d", &n, &m);
    for(memset(dp, 0, sizeof(dp)), i=1; i<=m && scanf("%d%d%d", &p, &h, &c); i++)
      if(p*c>n) tp=p, th=h, bagcom();
      else {
        for(s=1; s<c; c-=s, s<<=1)
          tp = s*p, th = s*h, bag01();
        tp = c*p, th = c*h, bag01();
      }
    printf("%d\n", dp[n]);
  }
  return 0;
}
