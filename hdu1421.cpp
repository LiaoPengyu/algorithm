#include "cstdio"
#include "cstring"
#include "algorithm"
#define oo 1<<30
using namespace std;
int const N = 2050;
int n, k, v[N], dp[N>>1][N], ANS, i, j;
inline int power(int v) {return v*v;}
int main() {
  while(~scanf("%d%d", &n, &k)) {
    for(i=1; i<=n; i++) scanf("%d", &v[i]);
    sort(v+1, v+n+1);
    memset(dp[0], 0, sizeof(dp[0]));
    for(i=1; i<=k; i++)
      for(j=i<<1|1, dp[i][j-1] = dp[i-1][j-3] + power(v[j-1]-v[j-2]); j<=n; j++)
        dp[i][j] = min(dp[i-1][j-2] + power(v[j]-v[j-1]), dp[i][j-1]);
    ANS = +oo;
    for(int j=k<<1; j<=n; j++) ANS = min(ANS, dp[k][j]);
    printf("%d\n", ANS);
  }
}
