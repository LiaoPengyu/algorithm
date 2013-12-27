#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int const N = 2222;
struct Edge {
  double l, r, h;
  int c;
  Edge() {}
  Edge(double l, double r, double h, int c): l(l), r(r), h(h), c(c) {}
  bool operator <(Edge const& other) const{
    return h<other.h;
  }
} edge[N];
int cnt[N<<2], n;
double sum[N<<2], X[N], ans;
#define LEAF_P (l==r)
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
inline void PushUp(int l, int r, int rt) {
  if(cnt[rt]) sum[rt] = X[r+1] - X[l];
  else if(LEAF_P) sum[rt] = 0;
  else sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void update(int L, int R, int c, int l=0, int r=n-1, int rt=1) {
  if(L<=l && R>=r) {
    cnt[rt] += c;
    PushUp(l, r, rt);
    return;
  }
  int m = (l+r)>>1;
  if(L<=m) update(L, R, c, lson);
  if(R>m) update(L, R, c, rson);
  PushUp(l, r, rt);
}
int main() {
  int rec, cas=1;
  while(~scanf("%d", &rec) && rec) {
    for(int i=0, j=0; i<rec; i++) {
      double x1, y1, x2, y2;
      scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
      edge[j] = Edge(x1, x2, y1, 1);
      X[j++] = x1;
      edge[j] = Edge(x1, x2, y2, -1);
      X[j++] = x2;
    }
    sort(edge, edge+rec*2);
    sort(X, X+rec*2);
    int m=1;
    for(int i=1; i<rec*2; i++) // unique
      if(X[i]!=X[i-1]) X[m++] = X[i];
    n = m; ans = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));
    for(int i=0; i<rec*2-1; i++) {
      int l, r;
      l = lower_bound(X, X+m, edge[i].l) - X;
      r = lower_bound(X, X+m, edge[i].r) - X;
      update(l, r-1, edge[i].c);
      ans += (edge[i+1].h - edge[i].h) * sum[1];
    }
    printf("Test case #%d\nTotal explored area: %.2f\n\n", cas++, ans);
  }
  return 0;
}
