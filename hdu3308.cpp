#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
int const N = 111111;
int c, n, m;
struct Node {
  int l, r, lc, rc, tmax;
} tree[N<<2], retn;
inline Node& combin(Node& ln, Node& rn, Node& ret, int m) {
  ret.l = ln.l;
  ret.r = rn.r;
  ret.lc = ln.lc;
  ret.rc = rn.rc;
  bool p = ln.r < rn.l;
  if(ret.lc == m-(m>>1)) ret.lc += p? rn.lc: 0;
  if(ret.rc == (m>>1)) ret.rc += p? ln.rc: 0;
  int tmp = p? ln.rc + rn.lc: 0;
  ret.tmax = max(tmp, max(ln.tmax, rn.tmax));
  return ret;
}
inline void PushUp(int rt, int m) {
  combin(tree[rt<<1], tree[rt<<1|1], tree[rt], m);
}
void build(int l=0, int r=n-1, int rt=1) {
  if(l==r) {
    scanf("%d", &tree[rt].l);
    tree[rt].r = tree[rt].l;
    tree[rt].lc = tree[rt].rc = tree[rt].tmax = 1;
    return;
  }
  int m = (l+r) >> 1;
  build(lson); build(rson);
  PushUp(rt, r-l+1);
}
void update(int p, int a, int l=0, int r=n-1, int rt=1) {
  if(l==r) {
    tree[rt].l = tree[rt].r = a;
    return;
  }
  int m = (l+r) >> 1;
  if(p<=m) update(p, a, lson);
  else update(p, a, rson);
  PushUp(rt, r-l+1);
}

Node& query(int L, int R, int l=0, int r=n-1, int rt=1) {
  if(L<=l && r<=R) {
    return tree[rt];
  }
  int m = (l+r) >> 1;
  if(R<=m) return query(L, R, lson);
  else if(L>m) return query(L, R, rson);
  else {
    Node ln, rn; // do not use global vars in recurse
    ln = query(L, R, lson);
    rn = query(L, R, rson);
    return combin(ln, rn, retn, r-l+1);
  }
}
int main() {
  scanf("%d", &c);
  while(c--) {
    scanf("%d%d", &n, &m);
    build();
    char cmd[2];
    int a, b;
    while(m--) {
      scanf("%s%d%d", cmd, &a, &b);
      if(*cmd=='U') update(a, b);
      else if(*cmd=='Q') printf("%d\n", query(a, b).tmax);
      else assert(0>1);
    }
  }
  return 0;
}
