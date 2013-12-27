#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
int const N=111111;

struct Node {
  int lz, rz, lc, rc, maxz, max, sum, xorf, cover;
} tree[N<<2], retn;

int T, n, m;
Node& combine(Node& ln, Node& rn, Node& ret, int m) {
  ret.lc = ln.lc;
  ret.rc = rn.rc;
  ret.lz = ln.lz;
  ret.rz = rn.rz;
  if(ret.lc == (m-(m>>1))) ret.lc += rn.lc;
  if(ret.rc == (m>>1)) ret.rc += ln.rc;
  if(ret.lz == (m-(m>>1))) ret.lz += rn.lz;
  if(ret.rz == (m>>1)) ret.rz += ln.rz;
  ret.max = max(ln.rc+rn.lc, max(ln.max, rn.max));
  ret.maxz = max(ln.rz+rn.lz, max(ln.maxz, rn.maxz));
  ret.sum = ln.sum+rn.sum;
  ret.xorf = 0;
  ret.cover = -1;
  return ret;
}
inline void refresh(int rt, int op, int m) {
  tree[rt].cover = op;
  tree[rt].lc = tree[rt].rc = tree[rt].max = tree[rt].sum = op? m: 0;
  tree[rt].lz = tree[rt].rz = tree[rt].maxz = op? 0: m;
  tree[rt].xorf = 0;
}
inline void FXOR(int rt, int m) {
  if(tree[rt].cover != -1) {
    tree[rt].cover ^= 1;
    tree[rt].lz = tree[rt].rz = tree[rt].maxz = tree[rt].cover? 0: m;
    tree[rt].lc = tree[rt].rc = tree[rt].max = tree[rt].sum = tree[rt].cover? m: 0;
  } else {
    tree[rt].xorf ^= 1;
    int tmplz, tmprz, tmpmaxz;
    tmplz = tree[rt].lz;
    tmprz = tree[rt].rz;
    tmpmaxz = tree[rt].maxz;
    tree[rt].lz = tree[rt].lc;
    tree[rt].rz = tree[rt].rc;
    tree[rt].maxz = tree[rt].max;
    tree[rt].lc = tmplz;
    tree[rt].rc = tmprz;
    tree[rt].max = tmpmaxz;
    tree[rt].sum = m - tree[rt].sum;
  }
}
inline void PushUp(int rt, int m) {
  combine(tree[rt<<1], tree[rt<<1|1], tree[rt], m);
}
inline void PushDown(int rt, int m) {
  if(tree[rt].cover != -1) {
    refresh(rt<<1, tree[rt].cover, m-(m>>1));
    refresh(rt<<1|1, tree[rt].cover, m>>1);
    tree[rt].cover = -1;
  } else if(tree[rt].xorf) {
    FXOR(rt<<1, m-(m>>1));
    FXOR(rt<<1|1, m>>1);
    tree[rt].xorf = 0;
  }
}
void build(int l=0, int r=n-1, int rt=1) {
  tree[rt].xorf = 0;
  tree[rt].cover = -1;
  if(l==r) {
    scanf("%d", &tree[rt].sum);
    tree[rt].lc = tree[rt].rc = tree[rt].max = tree[rt].sum;
    tree[rt].lz = tree[rt].rz = tree[rt].maxz = 1 - tree[rt].sum;
    return;
  }
  int m = (l+r)>>1;
  build(lson);
  build(rson);
  PushUp(rt, r-l+1);
}
void update(int L, int R, int op, int l=0, int r=n-1, int rt=1) {
  if(L<=l && r<=R) {
    if(op == 1 || op == 0) {
      refresh(rt, op, r-l+1);
    } else FXOR(rt, r-l+1);
    return;
  }
  PushDown(rt, r-l+1);
  int m = (l+r) >> 1;
  if(L<=m) update(L, R, op, lson);
  if(R>m) update(L, R, op, rson);
  PushUp(rt, r-l+1);
}
Node& query(int L, int R, int l=0, int r=n-1, int rt=1) {
  if(L<=l && r<=R) {
    return tree[rt];
  }
  PushDown(rt, r-l+1);
  int m = (l+r) >> 1;
  if(R<=m) return query(L, R, lson);
  if(L>m) return query(L, R, rson);
  else {
    Node ln, rn;
    ln = query(L, R, lson);
    rn = query(L, R, rson);
    return combine(ln, rn, retn, r-l+1);
  }
}
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &m);
    build();
    while(m--) {
      int op, a, b;
      scanf("%d%d%d", &op, &a, &b);
      if(op<3) update(a, b, op);
      else {
        retn = query(a, b); //maybe tree[rt], maybe retn
        if(op==3) printf("%d\n", retn.sum);
        else if(op==4) printf("%d\n", retn.max);
      }
    }
  }
  return 0;
}
