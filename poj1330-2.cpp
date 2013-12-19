#include <cstdio>
#include <cstring>
int const N = 10010, M = 21;
int C, n, f, t, P[N], D[N], H[N], L, r, DP[N][M];
struct EDGE {
  int t, n;
} E[N];
void dfs(int r, int d) {
  D[r] = d;
  for(int i=H[r]; ~i; i=E[i].n)
    dfs(E[i].t, d+1);
}
void add(int f, int t) {
  E[L].t = t;
  E[L].n = H[f];
  H[f] = L++;
}
int solve (int f, int t) {
  if(D[f] > D[t]) {
    int tmp = f;
    f = t;
    t = tmp;
  }
  int d = D[t] - D[f];
  for(int i=0; i<M; i++)
    if(1<<i & d) t = DP[t][i];
  if(f == t) return f;
  for(int i=M-1; ~i; i--)
    if(DP[f][i] != DP[t][i]) f=DP[f][i], t=DP[t][i];
  return DP[f][0];
}
int main() {
  scanf("%d", &C);
  while(C--) {
    memset(D, 0, sizeof(D));
    memset(H, -1, sizeof(H));
    L = 0;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
      scanf("%d%d", &f, &t);
      add(f, t);
      D[t] = 1;
      DP[t][0] = f;
    }
    scanf("%d%d", &f, &t);
    for(r=1; D[r]; r++);
    dfs(r, 0);
    for(int m=1; m<M; m++)
      for(int i=1; i<=n; i++)
        DP[i][m] = DP[DP[i][m-1]][m-1];
    printf("%d\n", solve(f, t));
  }
  return 0;
}
