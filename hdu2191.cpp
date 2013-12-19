#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
int const N = 700, MN = 101;
int C, n, m, p, h, c, i, j, s, v[N], w[N], dp[MN];
int main() {
  scanf("%d", &C);
  while(C--) {
    scanf("%d%d", &n, &m);
    for(i=j=1; i<=m; i++) {
      scanf("%d%d%d", &p, &h, &c);
      c = p*c > n? (n+p-1)/p: c;
      for(s=1; s<c; c-=s, s<<=1) v[j] = s*p, w[j++] = s*h;
      v[j] = c*p, w[j++] = c*h;
    }
    for(memset(dp, 0, sizeof(dp)), i=1; i<j; i++)
      for(s=n; s>=v[i]; s--)
        dp[s] = max(dp[s], dp[s-v[i]]+w[i]);
    printf("%d\n", dp[n]);
  }
  return 0;
}
