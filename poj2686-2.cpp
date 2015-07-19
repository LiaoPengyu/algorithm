#include <cstdio>
#include <cstring>
#include <queue>
#define oo 1<<20
using namespace std;

int const N = 9, M = 31, P = 30 * 31;
int cnt, H[M], tc[N], n, m, p, a, b, f, t, c, i;
double dp[1<<N][M];
struct Edge {
  int t, c, n;
} E[P];
inline void insert(int f, int t, int c) {
  E[cnt].t = t;
  E[cnt].c = c;
  E[cnt].n = H[f];
  H[f] = cnt++;
  E[cnt].t = f;
  E[cnt].c = c;
  E[cnt].n = H[t];
  H[t] = cnt++;
}
inline bool relax(double v, double& o) {
  return o>v? (o=v, true): false;
}
void spfa(int f = a-1) {
  bool flag[M] = {};
  for(int s=0; s<1<<n; s++)
    for(p =0; p<m; p++)
      dp[s][p] = +oo;
  dp[0][f] = 0;
  flag[f] = true;
  queue<int> Q;
  for(Q.push(f); !Q.empty(); Q.pop(), flag[f] = false) {
    for(int i=H[f=Q.front()], j; ~i; i=E[i].n)
      for(int p=0; p<n; p++)
        for(int s=0, ms=(1<<n)-(1<<p); s<ms; s++)
          if(!(s & (1<<p))
             && relax(dp[s][f] + ((double)E[i].c)/tc[p], dp[s | (1<<p)][j=E[i].t])
             && !flag[j]) flag[j] = true, Q.push(j);
  }
}
int main() {
  while(scanf("%d%d%d%d%d", &n, &m, &p, &a, &b)
        && (n || m || p || a|| b)) {
    for(i=0; i<n; i++) scanf("%d", &tc[i]);
    memset(H, -1, sizeof(H));
    for(i=cnt=0; i<p; i++) {
      scanf("%d%d%d", &f, &t, &c);
      insert(f-1, t-1, c);
    }
    spfa();
    double ans = +oo;
    for(int s=0; s<1<<n; s++)
      if(ans > dp[s][b-1])
        ans = dp[s][b-1];
    if(ans != +oo) printf("%.3f\n", ans);
    else printf("Impossible\n");
  }
  return 0;
}
