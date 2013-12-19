#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
#define oo (1<<25)
int const N = 110, M = 1010;
int edges[N][N], graph[N][N], n, m, ans;
void solve() {
  int k, i, j;
  ans = +oo;
  for(k=0; k<n; k++) {
    for(i=0; i<k; i++)
      for(j=i+1; j<k; j++)
        ans = min(ans, edges[i][j] + graph[i][k] + graph[k][j]);
    for(i=0; i<n; i++)
      for(j=i+1; j<n; j++)
          edges[i][j] = edges[j][i] = min(edges[i][j], edges[i][k] + edges[k][j]);
  }
}
int main() {
  while(~scanf("%d%d", &n, &m)) {
    for(int i=0; i< n; i++)
      for(int j=0; j<n; j++)
        edges[i][j] = graph[i][j] = +oo;
    while(m--) {
      int f, t, c;
      scanf("%d%d%d", &f, &t, &c);
      f--; t--;
      if(edges[f][t] != -1) c = min(c, edges[f][t]);
      edges[f][t] = c; graph[f][t] = c;
      edges[t][f] = c; graph[t][f] = c;
    }
    solve();
    if(ans < +oo) printf("%d\n", ans);
    else puts("It's impossible.");
  }
}
