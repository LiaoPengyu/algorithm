#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
int const N=500000;
int tree[N<<2], ret[N+1];
int k, n;

int pd_num[N+1];

using namespace std;

void init() {
  memset(pd_num, 0, sizeof(pd_num));
  for(int i=2; i<N+1; i++) {
    for(int j=i; j<N+1; j+=i) {
      pd_num[j]++;
    }
  }
}

struct child {
  char name[11];
  int num;
} children[N+1];

inline void PushUp(int rt) {
  tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void build(int l=1, int r=n, int rt=1) {
  if(l==r) {
    tree[rt] = 1; return;
  }
  int m = (l+r) >> 1;
  build(lson);
  build(rson);
  PushUp(rt);
}

int query(const int L, const int R, int l=1, int r=n, int rt=1) {
  if(L<=l && R>=r) return tree[rt];
  int m = (l+r)>>1, ret=0;
  if(L<=m) ret += query(L, R, lson);
  if(R>m) ret += query(L, R, rson);
  return ret;
}

int update(const int p, int l=1, int r=n, int rt=1) {
  if(l==r) {
    tree[rt] = 0;
    return l;
  }
  int m = (l+r) >> 1, ret;
  ret = p<=tree[rt<<1]? update(p, lson): update(p-tree[rt<<1], rson);
  PushUp(rt);
  return ret;
}

int main() {
  init();
  while(~scanf("%d%d", &n, &k)) {
    build();
    for(int i=1; i<n+1; i++) {
      scanf("%s%d", children[i].name, &children[i].num);
    }
    int delta;
    ret[1] = k; update(k);
    for(int i=2; i<=n; i++) {
      delta = children[ret[i-1]].num;
      if(delta > 0) {
        delta = delta%tree[1]? delta%tree[1]: tree[1];
        int d = query(ret[i-1], n);
        ret[i]=delta<=d? update(tree[1]-d+delta): update(delta-d);
      }
      else {
        delta = -delta;
        delta = delta%tree[1]? delta%tree[1]: tree[1];
        int d = query(1, ret[i-1]);
        ret[i]=delta<=d? update(d-delta + 1): update(tree[1] - (delta-d) + 1);
      }
    }
    int retv = max_element(pd_num+1, pd_num+n+1)-pd_num;
    printf("%s %d\n", children[ret[retv]].name, pd_num[retv]+1);
  }
  return 0;
}
