#include "cstring"
#include "cstdio"
#include "algorithm"
using namespace std;
int const N = 33;
struct PG {
  int h, l, t;
  bool operator<(PG const&o) const {if(t==o.t) return l<o.l; else return t<o.t;}
}P[N];
int n, i, j, k, dp[N][100], ANS;
int main() {
  while(scanf("%d", &n), n>0) {
    for(i=1; i<=n; i++) scanf("%d%d%d", &P[i].h, &P[i].l, &P[i].t);
    sort(P+1, P+n+1);
    for(memset(dp, 0, sizeof(dp)), ANS=0, i=1; i<=n; i++)
      for(j=1; j<=P[i].t-P[i].l+1; j++)
        for(dp[i][j]=P[i].h, ANS=max(ANS, dp[i][j]), k=1; k<i; k++)
          if(j>P[k].l)
            dp[i][j] = max(dp[i][j], dp[k][j-P[k].l]+P[i].h), ANS = max(ANS, dp[i][j]);
    printf("%d\n", ANS);
  }
  return 0;
}
