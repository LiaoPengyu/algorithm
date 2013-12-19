#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
int const N = 100010, M = 100010;
int a[N], c[N], v[N*10], n, m, i, j, k, dp[M], ANS;
int main() {
  while(scanf("%d%d", &n, &m), n||m) {
    for(i=1; i<=n; i++) scanf("%d", &a[i]);
    for(i=1; i<=n; i++) scanf("%d", &c[i]);
    for(i=j=1; i<=n; i++) {
      if(a[i]*c[i]>m) c[i] = (m+a[i]-1) / a[i];
      for(k=1; k<c[i]; c[i]-=k, k<<=1) v[j++] = a[i]*k;
      if(c[i]) v[j++] = a[i]*c[i];
    }
    for(memset(dp, 0, sizeof(dp)), i=1; i<j; i++)
      for(k=m; k>=v[i]; k--)
        dp[k] = max(dp[k], dp[k-v[i]] + v[i]);
    for(k=1, ANS=0; k<=m; k++) if(dp[k] == k) ANS++;
    printf("%d\n", ANS);
  }
  return 0;
}
