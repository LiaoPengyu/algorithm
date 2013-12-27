#include <cstdio>
#include <cstring>

using namespace std;
int const N = 100010;
int p[N], du[N], sets[N], odds[N], n, m;
bool flag[N];
void init(int nn) {
  while(nn--) {
    int tmp = nn+1;
    p[tmp] = -1;
    du[tmp] = 0;
    sets[tmp] = 0;
    odds[tmp] = 0;
    flag[tmp] = false;
  }
}
int find(int x) {
  int tx = x;
  while(p[tx]>=0) tx=p[tx];
  while(x!=tx) {
    p[x] = tx;
    x = p[x];
  }
  return x;
}
void union_s(int a, int b) {
  int ra = find(a);
  int rb = find(b);
  if(ra == rb) return;
  int tmp;
  if(p[ra] > p[rb]) {
    tmp = p[ra];
    p[ra] = rb;
    p[rb] += tmp;
  } else {
    tmp = p[rb];
    p[rb] = ra;
    p[ra] += tmp;
  }
}
int main() {
  while(~scanf("%d%d", &n, &m)) {
    init(n);
    for(int i=0; i<m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      if(a==b) continue;
      du[a]++; du[b]++;
      union_s(a, b);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++) {
      if(du[i]==0) continue;
      int rt = find(i);
      if(!flag[rt]) {
        flag[rt] = true;
        sets[cnt++] = rt;
      }
      if(du[i] & 1) {
        odds[rt]++;
      }
    }
    int ret = 0;
    for(int i=0; i<cnt; i++) {
      if(odds[sets[i]])
        ret += odds[sets[i]] / 2;
      else
        ret++;
    }
    printf("%d\n", ret);
  }
  return 0;
}
