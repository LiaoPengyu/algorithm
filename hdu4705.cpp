#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <cstring>
using namespace std;
#define LL __int64
#define LLD I64d
int const N = 100100;

struct Edge {
  int to, next;
} edge[N<<2];
int n, NEXT, head[N];
void add(int u, int v) {
  edge[NEXT].to = v;
  edge[NEXT].next = head[u];
  head[u] = NEXT++;
}
LL ans;
bool vec[N];
int dfs(int u) {
  int son, tmp=0;
  vec[u] = true;
  for(int i=head[u]; i!=-1; i=edge[i].next) {
    int v = edge[i].to;
    if(vec[v]) continue;
    son = dfs(v);
    tmp += son;
    ans += (LL)son*(n-1-tmp);
  }
  return tmp+1;
}
int main() {
  int a, b;
  while(~scanf("%d", &n)) {
    NEXT = 0; ans = 0;
    memset(head, -1, sizeof(head));
    for(int i=1; i<n; i++) {
      scanf("%d%d", &a, &b);
      add(a, b);
      add(b, a);
    }
    memset(vec, false, sizeof(vec));
    dfs(1);
    LL sum = (LL)n*(n-1)*(n-2)/6;
    printf("%LLD\n", sum - ans);
  }
  return 0;
}
