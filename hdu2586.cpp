#include <cstdio>
#include <cstring>
using namespace std;
int const N = 40010, M = 21;
int c, m, n, f, t, d, H[N], L, DP[N][M], D[N], DIS[N], V[N];
struct EDGE {
  int t, d, n;
} E[N<<1];
void add(int f, int t, int d) {
  E[L].t = t;
  E[L].d = d;
  E[L].n = H[f];
  H[f] = L++;
  E[L].t = f;
  E[L].d = d;
  E[L].n = H[t];
  H[t] = L++;
}
void dfs(int f, int d) {
  D[f] = d; V[f] = true;
  for(int i=H[f]; ~i; i=E[i].n)
    if(!V[E[i].t]) {
      DIS[E[i].t] = DIS[f] + E[i].d;
      DP[E[i].t][0] = f;
      dfs(E[i].t, d+1);
    }
}
int solve(int f, int t) {
  if(D[f]>D[t]) {
    int tmp = f;
    f = t; t = tmp;
  }
  int d = D[t] - D[f];
  for(int i=0; i<M; i++)
    if(1<<i & d) t = DP[t][i];
  if(f == t) return f;
  for(int i=M-1; ~i; i--)
    if(DP[f][i] != DP[t][i]) f = DP[f][i], t = DP[t][i];
  return DP[f][0];
}
int main() {
  scanf("%d", &c);
  while(c--) {
    scanf("%d%d", &n, &m);
    memset(H, -1, sizeof(H));
    memset(V, false, sizeof(V));
    L = 0;
    for(int i=1; i<n; i++) {
      scanf("%d%d%d", &f, &t, &d);
      add(f, t, d);
    }
    DIS[1] = 0;
    DP[1][0] = 1;
    dfs(1, 0);
    for(int j=1; j<M; j++)
      for(int i=1; i<=n; i++)
        DP[i][j] = DP[DP[i][j-1]][j-1];
    for(int i=0; i<m; i++) {
      scanf("%d%d", &f, &t);
      printf("%d\n", DIS[f] + DIS[t] - 2 * DIS[solve(f, t)]);
    }
  }
}
