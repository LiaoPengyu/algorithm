#include <cstdio>
#include <cstring>
#define oo 1<<20
#define min(x, y) ((x) > (y)? (y): (x))
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
int main() {
  while(scanf("%d%d%d%d%d", &n, &m, &p, &a, &b)
        && (n || m || p || a|| b)) {
    for(i=0; i<n; i++) scanf("%d", &tc[i]);
    memset(H, -1, sizeof(H));
    for(i=cnt=0; i<p; i++) {
      scanf("%d%d%d", &f, &t, &c);
      insert(f-1, t-1, c);
    }
    for(int s=0; s<1<<n; s++)
      for(f=0; f<m; f++)
        dp[s][f] = +oo;
    dp[0][a-1] = 0;
    double ans = +oo;
    for(int s=0; s<1<<n; ans = min(ans, dp[s][b-1]), s++)
      for(t=0; t<n; t++)
        if(!(s & (1<<t)))
          for(f=0; f<m; f++)
            for(i=H[f]; ~i; i=E[i].n)
              dp[s | (1<<t)][E[i].t] = min(dp[s | (1<<t)][E[i].t],
                                           dp[s][f] + ((double)E[i].c / tc[t]));
    if(ans != +oo) printf("%.3f\n", ans);
    else printf("Impossible\n");
  }
  return 0;
}
