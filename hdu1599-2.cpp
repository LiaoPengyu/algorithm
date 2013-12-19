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
        if(edges[i][j] != -1 && graph[i][k] != -1 && graph[k][j] != -1)
          ans = min(ans, edges[i][j] + graph[i][k] + graph[k][j]);
    for(i=0; i<n; i++)
      for(j=0; j<n; j++) {
        if(edges[i][k] != -1 && edges[k][j] != -1) {
          int tmp = edges[i][k] + edges[k][j];
          if(edges[i][j] == -1) edges[i][j] = edges[j][i] = tmp;
          else edges[i][j] = edges[j][i] = min(edges[i][j], tmp);
        }
      }
  }
}
int main() {
  while(~scanf("%d%d", &n, &m)) {
    memset(edges, -1, sizeof(edges));
    memset(graph, -1, sizeof(graph));
    for(int i=0; i<n ;i++)
      edges[i][i] = graph[i][i] = 0;
    while(m--) {
      int f, t, c;
      scanf("%d%d%d", &f, &t, &c);
      f--; t--;
      if(edges[f][t] != -1) c = min(c, edges[f][t]);
      edges[f][t] = graph[f][t] = edges[t][f] = graph[t][f] = c;
    }
    solve();
    if(ans < +oo) printf("%d\n", ans);
    else puts("It's impossible.");
  }
}
