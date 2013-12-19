#include "cstring"
#include "cstdio"
#include "algorithm"
using namespace std;
int const N = 33;
struct PG {
  int h, l, t;
  bool operator<(PG const&o) const {if(t==o.t) return l<o.l; else return t<o.t;}
}P[N];
int n, i, j, k, dp[1000], ANS;
int main() {
  while(scanf("%d", &n), n>0) {
    for(i=1; i<=n; i++) scanf("%d%d%d", &P[i].h, &P[i].l, &P[i].t);
    sort(P+1, P+n+1);
    for(memset(dp, 0, sizeof(dp)), i=1; i<=n; i++)
      for(j=P[i].t; j>=P[i].l; j--)
        dp[j] = max(dp[j], dp[j-P[i].l]+P[i].h);
    for(ANS=0, j=1; j<=P[n].t; j++) ANS = max(ANS, dp[j]);
    printf("%d\n", ANS);
  }
  return 0;
}
