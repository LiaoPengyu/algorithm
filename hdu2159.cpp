#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
int const N = 110;
int n, m, k, s, v[N], e[N], dp[N][N], i, j, l, ANS;
int main() {
  while(~scanf("%d%d%d%d", &n, &m, &k, &s)) {
    memset(dp, 0, sizeof(dp));
    for(i=1; i<=k; i++ ) scanf("%d%d", &e[i], &v[i]);
    for(l=1; l<=s; l++)
      for(i=1; i<=k; i++)
        for(j=v[i]; j<=m; j++)
          dp[j][l] = max(dp[j][l], dp[j-v[i]][l-1]+e[i]);
    for(ANS=-1, j=0; j<=m; j++) if(dp[j][s]>=n) {ANS=m-j; break;}
    printf("%d\n", ANS);
  }
  return 0;
}
