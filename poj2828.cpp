#include <cstdio>
#include <iostream>

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int N =  200010;
int tree[N<<2];
int ret[N];
int n;

struct date {
  int pos, val;
} d[N];

inline void PushUp(int rt) {
  tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void build(int l=1, int r=n, int rt=1) {
  if(l==r){
    tree[rt] = 1; return;
  }
  int m = (l+r) >> 1;
  build(lson);
  build(rson);
  PushUp(rt);
}

void update(int p, int v, int l=1, int r=n, int rt=1) {
  if(l==r) {
    tree[rt] = 0;
    ret[l] = v; return;
  }
  int m = (l+r)>>1;
  if(tree[rt<<1]>p) update(p, v, lson);
  else update(p-tree[rt<<1], v, rson);
  PushUp(rt);
}

int main() {
  while(~scanf("%d", &n)) {
    int i;
    build();
    for(i=0; i<n; i++) {
      scanf("%d%d", &d[i].pos, &d[i].val);
    }
    for(i=n-1; i>=0;i--) {
      update(d[i].pos, d[i].val);
    }
    for(i=1; i<=n; i++) {
      printf("%d%c", ret[i], i^n?' ':'\n');
    }
  }
}
