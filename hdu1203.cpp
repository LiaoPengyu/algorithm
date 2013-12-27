#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const M = 10010;
int n, m, v[M], i, j;
float p[M], dp[M];
int main() {
  while(scanf("%d%d", &n, &m), n||m) {
    for(i=0; i<=n; i++) dp[i] = 1;
    for(i=1; i<=m; i++) {
      scanf("%d%f", &v[i], &p[i]);
      p[i] = 1 - p[i];
      for(j=n; j>=v[i]; j--) dp[j] = min(dp[j], dp[j-v[i]] * p[i]);
    }
    printf("%.1f%%\n", (1-dp[n]) * 100);
  }
  return 0;
}
