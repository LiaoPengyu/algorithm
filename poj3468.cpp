#include <cstdio>
#include <cstring>

#define ll long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;

const int N = 100000;
int n, q;

ll tree[N<<2];
ll add[N<<2];

inline void PushDown(int rt, int m) {
  if(add[rt]) {
    tree[rt<<1] += (m-(m>>1)) * add[rt];
    tree[rt<<1|1] += (m>>1) * add[rt];
    add[rt<<1] += add[rt];
    add[rt<<1|1] += add[rt];
    add[rt] = 0;
  }
}
inline void PushUp(int rt) {
  tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void build(int l=1, int r=n, int rt=1) {
  add[rt] = 0;
  if(l==r) {
    scanf("%lld", &tree[rt]);
    return;
  }
  int m = (l+r) >> 1;
  build(lson);
  build(rson);
  PushUp(rt);
}

ll query(int L, int R, int l=1, int r=n, int rt=1) {
  if(L<=l&&R>=r)
    return tree[rt];
  PushDown(rt, r-l+1);
  int m = (l+r) >> 1;
  ll ret=0;
  if(L<=m) ret += query(L, R, lson);
  if(R>m) ret += query(L, R, rson);
  return ret;
}
void update(int L, int R, int a, int l=1, int r=n, int rt=1) {
  if(L<=l && R>=r) {
    tree[rt] += (r-l+1) * a;
    add[rt] += a;
    return;
  }
  int m = (l+r) >> 1;
  PushDown(rt, r-l+1);
  if(L<=m) update(L, R, a, lson);
  if(R>m) update(L, R, a, rson);
  PushUp(rt);
}
int main() {
  while(~scanf("%d%d", &n, &q)) {
    build();
    while(q--) {
      char o[2];
      int a, b, c;
      scanf("%s", o);
      if(o[0]=='Q') {
        scanf("%d%d", &a, &b);
        printf("%lld\n", query(a,b));
      } else {
        scanf("%d%d%d", &a, &b, &c);
        update(a, b, c);
      }
    }
  }
  return 0;
}
