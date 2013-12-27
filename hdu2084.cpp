#include <cstdio>
int const N = 110;
int dp[N], mat[N], C, n, ANS, i ,j;
int main() {
  scanf("%d", &C);
  while(C--) {
    scanf("%d", &n);
    for(scanf("%d", &dp[0]), i=2; i<=n; i++) {
      for(j=0; j<i; j++) scanf("%d", &mat[j]);
      dp[i-1] = dp[i-2] + mat[i-1];
      for(j=i-2; j>0; j--) dp[j] = (dp[j-1] > dp[j]? dp[j-1]: dp[j]) + mat[j];
      dp[0] += mat[0];
    }
    for(i=0, ANS=0; i<n; i++) ANS = ANS > dp[i]? ANS: dp[i];
    printf("%d\n", ANS);
  }
  return 0;
}
