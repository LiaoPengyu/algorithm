#include <cstring>
#include <cstdio>
#include <algorithm>
#define oo 999999
using namespace std;
int const N = 10010;
int T, E, F, n, i, j, dp[N];
struct Currency {
  int p, w;
} C[505];
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &E, &F);
    scanf("%d", &n);
    for(F-=E, i=1; i<=n && scanf("%d%d", &C[i].p, &C[i].w); i++) ;
    for(fill(dp, dp+F+1, +oo), dp[0]=0, i=1; i<=n; i++)
      for(j=C[i].w; j<=F; j++)
        dp[j] = min(dp[j], dp[j-C[i].w]+C[i].p);
    if(dp[F] == +oo) puts("This is impossible.");
    else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[F]);
  }
  return 0;
}
