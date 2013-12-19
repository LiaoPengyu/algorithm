#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int const N = 22, M = 1010;
int C, n, m, mat[N][M], dp[N][M];
int main() {
  scanf("%d", &C);
  while(C--) {
    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++) {
        dp[i][j] = -1000;
        scanf("%d", &mat[i][j]);
      }
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++) {
        dp[i][j] = max(dp[i][j], dp[i-1][j]+mat[i][j]);
        for(int k=1; k<j; k++)
          if(!(j % k)) dp[i][j] = max(dp[i][j], dp[i][j/k]+mat[i][j]);
      }
    printf("%d\n", dp[n][m]);
  }
  return 0;
}
