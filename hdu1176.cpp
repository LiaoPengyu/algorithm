#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const N = 100010, T = 100010;
int n, x, t, mint, maxt, dp[T][12], mat[T][12], ANS;
inline int eval(int i, int j) {
  int ret = ~dp[i-1][j]? dp[i-1][j]+mat[i][j]: -1;
  if(j>0) ret = max(ret, ~dp[i-1][j-1]? dp[i-1][j-1]+mat[i][j]: -1);
  if(j<10) ret = max(ret, ~dp[i-1][j+1]? dp[i-1][j+1]+mat[i][j]: -1);
  return ret;
}
int main() {
  while(scanf("%d", &n), n) {
    memset(mat, 0, sizeof(mat));
    memset(dp, -1, sizeof(dp));
    mint = T; maxt = 0; ANS = -1;
    while(n--) {
      scanf("%d%d", &x, &t);
      mat[t][x] ++;
      mint = min(t, mint);
      maxt = max(t, maxt);
    }
    dp[0][5] = 0;
    for(int i=1; i<=maxt; i++)
      for(int j=0; j<=10; j++)
        dp[i][j] = eval(i, j);
    for(int i=0; i<=10; i++)
      ANS = max(dp[maxt][i], ANS);
    printf("%d\n", ANS);
  }
  return 0;
}
