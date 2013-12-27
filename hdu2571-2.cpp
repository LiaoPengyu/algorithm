#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int const N = 22, M = 1010;
int dp[N][M], mat[N][M], C, n, m, i, j, k, l;
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
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]+mat[i+1][j]);
        dp[i][j+1] = max(dp[i][j+1], dp[i][j]+mat[i][j+1]);
        for(k=2; (l=k*j)<=m; k++)
          dp[i][l] = max(dp[i][l], dp[i][j]+mat[i][l]);
      }
    printf("%d\n", dp[n][m]);
  }
  return 0;
}
