#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int const N = 79999;

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
int ltree[N<<2], rtree[N<<2], tmax[N<<2], cover[N<<2];
int n, m;

inline void PushDown(int m, int rt) {
  if(cover[rt] != -1) {
    cover[rt<<1] = cover[rt<<1|1] = cover[rt];
    ltree[rt<<1] = rtree[rt<<1] = tmax[rt<<1] = cover[rt] ? (m - (m>>1)): 0;
    ltree[rt<<1|1] = rtree[rt<<1|1] = tmax[rt<<1|1] = cover[rt] ? (m>>1): 0;
    cover[rt] = -1;
  }
}
inline void PushUp(int m, int rt) {
  ltree[rt] = ltree[rt<<1];
  rtree[rt] = rtree[rt<<1|1];
  if(ltree[rt] == m-(m>>1)) ltree[rt] += ltree[rt<<1|1];
  if(rtree[rt] == (m>>1)) rtree[rt] += rtree[rt<<1];
  tmax[rt] = max(max(tmax[rt<<1], tmax[rt<<1|1]), rtree[rt<<1]+ltree[rt<<1|1]);
}
void build(int l=1, int r=n, int rt=1) {
  tmax[rt] = rtree[rt] = ltree[rt] = r-l+1;
  cover[rt] = -1;
  if(l==r) return;
  int m = (l+r) >> 1;
  build(lson), build(rson);
}
void update(int L, int R, int a, int l=1, int r=n, int rt=1) {
  if(L<=l && r<=R) {
    cover[rt] = a;
    tmax[rt] = ltree[rt] = rtree[rt] = a? (r-l+1): 0;
    return;
  }
  PushDown(r-l+1, rt);
  int m = (l+r) >> 1;
  if(L<=m) update(L, R, a, lson);
  if(R>m) update(L, R, a, rson);
  PushUp(r-l+1, rt);
}
int query(int d, int l=1, int r=n, int rt=1) { // check d>tmax[1] before query
  int ret, m = (l+r) >> 1;
  if(l==r) ret = l;
  else {
    PushDown(r-l+1, rt);
    if(d<=tmax[rt<<1]) ret = query(d, lson);
    else if(d<=rtree[rt<<1]+ltree[rt<<1|1]) ret = m-rtree[rt<<1]+1;
    else ret = query(d, rson); // d<=tmax[rt<<1|1]
  }
  if(rt==1) update(ret, ret+d-1, 0);
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  build();
  while(m--) {
    int a, b, c;
    scanf("%d%d", &a, &b);
    if(a==1)
      printf("%d\n", b>tmax[1]? 0: query(b));
    else {
      scanf("%d", &c); update(b, b+c-1, 1);
    }
  }
  return 0;
}
