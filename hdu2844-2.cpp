#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
int const N = 100010, M = 100010;
int v[N*10], n, m, c, i, j, k, dp[M], ANS;
int main() {
  while(scanf("%d%d", &n, &m), n||m) {
    for(i=1; i<=n; i++) scanf("%d", &v[i]);
    for(j=1; j<=n; j++ ) {
      scanf("%d", &c);
      if(v[j]*c>m) c = (m+v[j]-1) / v[j];
      for(k=2, c--; k<c; c-=k, k<<=1) v[i++] = v[j]*k;
      if(c) v[i++] = v[j]*c;
    }
    for(memset(dp, 0, sizeof(dp)), j=1; j<i; j++)
      for(k=m; k>=v[j]; k--)
        dp[k] = max(dp[k], dp[k-v[j]] + v[j]);
    for(k=1, ANS=0; k<=m; k++) if(dp[k] == k) ANS++;
    printf("%d\n", ANS);
  }
  return 0;
}
