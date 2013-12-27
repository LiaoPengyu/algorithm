#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const N = 200010;
int m, n, c[N], l, dp[N], i, j, ans;
int main() {
  while(~scanf("%d%d", &m, &n)) {
    for(j=1, memset(c, 0, sizeof(c)); j<=m; j++) {
      if(n>=1) {scanf("%d", &l); dp[1]=l;}
      if(n>=2) {scanf("%d", &l); dp[2]=l;}
      for(i=3, c[j]=max(dp[1], dp[2]); i<=n && scanf("%d", &l); i++)
        dp[i] = max(dp[i-2], dp[i-3])+l, c[j] = max(c[j], dp[i]);
    }
    if(m>=1) dp[1]=c[1];
    if(m>=2) dp[2]=c[2];
    for(i=3; i<=m; i++)
      dp[i] = max(dp[i-2], dp[i-3])+c[i];
    for(i=1, ans=0; i<=m; i++) ans=max(ans, dp[i]);
    printf("%d\n", ans);
  }
  return 0;
}
