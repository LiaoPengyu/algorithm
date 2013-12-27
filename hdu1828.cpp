#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const POS = 10000, NEG = -10000, N = 22222;
int LB=POS, RB=NEG;
struct Node {
  int lb, rb, len, seg, cover;
} tree[N<<2];
struct Rec {
  int l, r, h, c;
  Rec(){}
  Rec(int l, int r, int h, int c): l(l), r(r), h(h), c(c) {}
  bool operator < (Rec const& other) const {
    if(h==other.h) return c>other.c;
    return h<other.h;
  }
} rec[N];
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
void PushUp(int rt, int l, int r) {
  if(tree[rt].cover) {
    tree[rt].lb = tree[rt].rb = 1;
    tree[rt].seg = 2;
    tree[rt].len = r-l+1;
  } else if(r == l)
    tree[rt].len = tree[rt].seg = tree[rt].lb = tree[rt].rb = 0;
  else {
    tree[rt].lb = tree[rt<<1].lb;
    tree[rt].rb = tree[rt<<1|1].rb;
    tree[rt].seg = tree[rt<<1].seg + tree[rt<<1|1].seg;
    tree[rt].len = tree[rt<<1].len + tree[rt<<1|1].len;
    if(tree[rt<<1].rb && tree[rt<<1|1].lb) tree[rt].seg -= 2;
  }
}
void update(int L, int R, int c, int l=LB, int r=RB-1, int rt=1) {
  if(L<=l && R>=r) {
    tree[rt].cover += c;
    PushUp(rt, l, r);
    return;
  }
  int m = (l+r) >> 1;
  if(L<=m) update(L, R, c, lson);
  if(R>m) update(L, R, c, rson);
  PushUp(rt, l, r);
}
int main() {
  int n;
  while(~scanf("%d", &n)) {
    for(int i=0; i<n; i++) {
      int a, b, c, d;
      scanf("%d%d%d%d", &a, &b, &c, &d);
      LB = min(LB, a);
      RB = max(RB, c);
      rec[i*2] = Rec(a, c, b, 1);
      rec[i*2+1] = Rec(a, c, d, -1);
    }
    for(int i=0; i<(N<<2); i++) {
      tree[i].cover = tree[i].len = tree[i].seg = tree[i].lb = tree[i].rb = 0;
    }
    sort(rec, rec+n*2);
    int ans=0, last=0;
    for(int i=0; i<2*n; i++) {
      if(rec[i].l < rec[i].r) update(rec[i].l, rec[i].r-1, rec[i].c);
      ans += tree[1].seg * (rec[i+1].h - rec[i].h);
      ans += abs(tree[1].len - last);
      last = tree[1].len;
    }
    printf("%d\n", ans);
  }
  return 0;
}
