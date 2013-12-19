#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define lson l, m, rt << 1
#define rson m+1, r, rt << 1|1

const int N = 100000;
long tree[N<<2];
int q, n, rt;

inline void PushUp(int rt) {
  tree[rt] = tree[rt<<1] + tree[rt<<1 | 1];
}

void build(int l=1, int r=n, int rt=1) {
  if(l==r) {
    scanf("%ld", &tree[rt]); return;
  }
  int m = (l+r) >> 1;
  build(lson);
  build(rson);
  PushUp(rt);
}

long query(int L, int R, int l=1, int r=n, int rt=1) {
  if(L<=l && R>=r)
    return tree[rt];
  int m = (l+r) >> 1, ret=0;
  if(L<=m) ret+=query(L, R, lson);
  if(R>m) ret+=query(L, R, rson);
  return ret;
}

void add(int L, int R, int a, int l=1, int r=n, int rt=1) {
  tree[rt] += (R-L+1) * a;
  if(l==r) return;
  int m = (l+r) >> 1;
  if(L<=m) add(L, m, a, lson);
  if(R>m) add(m+1, R, a, rson);
}

int main() {
  while(~scanf("%d%d", &n, &q)) {
    build();
    while(q--) {
      char command[2];
      scanf("%s", command);
      int a, b, c;
      if(command[0]=='Q') {
        scanf("%d%d", &a, &b);
        printf("%ld\n", query(a, b));
      }
      else {
        scanf("%d%d%d", &a, &b, &c);
        add(a,b,c);
      }
    }
  }
  return 0;
}
