#include <cstring>
#include <cstdio>

using namespace std;

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

int const N = 200010;
int tree[N<<2], add[N<<2];
int n, q, i, x, y, z;

inline void PushDown(int rt, int m) {
  if(add[rt]) {
    tree[rt<<1] = (m-(m>>1)) * add[rt];
    tree[rt<<1|1] = (m>>1) * add[rt];
    add[rt<<1] = add[rt];
    add[rt<<1|1] = add[rt];
    add[rt] = 0;
  }
}
inline void PushUp(int rt) {
  tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void build(int l=1, int r=n, int rt=1) {
  add[rt] = 0;
  tree[rt] = r-l+1;
  if(l==r) return;
  int m = (l+r)>>1;
  build(lson);
  build(rson);
}
void update(int L, int R, int me, int l=1, int r=n, int rt=1) {
  if(L<=l && R>=r) {
    tree[rt] = (r-l+1) * me; add[rt] = me;
    return;
  }
  int m = (l+r)>>1;
  PushDown(rt, r-l+1);
  if(L<=m) update(L, R, me, lson );
  if(R>m) update(L, R, me, rson );
  PushUp(rt);
}
int main() {
  scanf("%d", &i);
  for(int c=1; c<=i; c++) {
    scanf("%d", &n), scanf("%d", &q);
    build();
    while(q--) {
      scanf("%d%d%d", &x, &y, &z);
      update(x, y, z);
    }
    printf("Case %d: The total value of the hook is %d.\n", c, tree[1]);
  }
  return 0;
}
