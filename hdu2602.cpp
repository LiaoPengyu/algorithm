#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int const NM = 1010, VM = 1010;
int T, n, v, VA[NM], VO[NM], dp[NM], i, j;
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &v);
    memset(dp, 0, sizeof(dp));
    for(i=1; i<=n; i++) scanf("%d", &VA[i]);
    for(i=1; i<=n; i++) scanf("%d", &VO[i]);
    for(i=1, dp[0]=0; i<=n; i++)
      for(j=v; j>=VO[i]; j--)
        dp[j] = max(dp[j], dp[j-VO[i]]+VA[i]);
    printf("%d\n", dp[v]);
  }
  return 0;
}
