#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const N = 1010;
int v[N], dp[N], n, i, j, ANS;
int main() {
  while(scanf("%d", &n), n) {
    for(scanf("%d", &v[1]), ANS=dp[1]=v[1], i=2; i<=n; i++) {
      scanf("%d", &v[i]);
      for(j=1, dp[i]=v[i]; j<i; j++) if(v[j]<v[i]) dp[i] = max(dp[i], dp[j]+v[i]);
      ANS = max(ANS, dp[i]);
    }
    printf("%d\n", ANS);
  }
  return 0;
}
