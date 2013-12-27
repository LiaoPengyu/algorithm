#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const N = 5010;
int n, s, S, v[N], m, dp[125000], i, j, k;
int main() {
  while(scanf("%d", &n), n>=0) {
    if(n==0) {puts("0 0"); continue;}
    for(S=0, i=j=1; i<=n; i++) {
      scanf("%d%d", &v[j], &m);
      S += v[j++] * m;
      for(k=1; k<m; k++, j++) v[j] = v[j-1];
    }
    s = S>>1;
    for(i=1, memset(dp, 0, sizeof(int)*(s+1)); i<j; i++)
      for(k=s; k>=v[i]; k--)
        dp[k] = max(dp[k], dp[k-v[i]]+v[i]);
    printf("%d %d\n", S-dp[s], dp[s]);
  }
  return 0;
}
