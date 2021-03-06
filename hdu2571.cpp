#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int const N = 22, M = 1010;
int dp[N][M], mat[N][M], C, n, m, i, j, k;
int main() {
  scanf("%d", &C);
  while(C--) {
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++)
      for(j=1; j<=m; j++) {
        scanf("%d", &mat[i][j]);
        dp[i][j] = -1000;
      }
    for(i=1, dp[1][1]=mat[1][1]; i<=n; i++)
      for(j=1; j<=m; j++) {
        if(i>1) dp[i][j] = max(dp[i][j], dp[i-1][j]+mat[i][j]);
        if(j>1) dp[i][j] = max(dp[i][j], dp[i][j-1]+mat[i][j]);
        for(k=2; k<=j; k++)
          if(!(j % k)) dp[i][j] = max(dp[i][j], dp[i][j/k]+mat[i][j]);
      }
    printf("%d\n", dp[n][m]);
  }
  return 0;
}
