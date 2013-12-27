#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int const N = 105;
int mat[N][N], T, n, m, e, ed, i, j, dp[N][N];
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++)
      for(j=1; j<=m && scanf("%d", &mat[i][j]); j++);
    for(memset(dp, 0, sizeof(dp)), dp[1][1]=1, ed=n+m, i=2; i<ed; i++)
      for(j=i<=n? 1: i-n; j<i; j++)
        if((e=mat[i-j][j])>0)
          for(int k=1, tmp=min(e, ed-i); k<=tmp; k++)
            for(int l=max(j, i+k-n), tmp1=min(j+k, m); l<=tmp1; l++)
              dp[i+k-l][l] = (dp[i+k-l][l]+dp[i-j][j]) % 10000;
    printf("%d\n", dp[n][m]);
  }
  return 0;
}
