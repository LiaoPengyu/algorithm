#include <cstdio>
#include <iostream>

using namespace std;
const int N = 222222;
int tree[N<<2];
int h, w, n;

void build(int l, int r, int rt) {
  tree[rt] = w;
  if(l==r) return;
  int m = (l+r) >> 1;
  build(l, m, rt<<1);
  build(m+1, r, rt<<1 | 1);
}

inline void refresh(int rt) {
  tree[rt] = max(tree[rt<<1], tree[rt<<1 | 1]);
}
int update(int w, int l, int r, int rt) {
  if(l==r) {
    tree[rt] -= w;
    return l;
  }
  int m = (l+r) >> 1, ret;
  ret = tree[rt<<1] >= w? update(w, l, m, rt<<1): update(w, m+1, r, rt<<1 | 1);
  refresh(rt);
  return ret;
}

int main() {
  while(~scanf("%d%d%d", &h, &w, &n)) {
    if(h>n) h=n;
    build(1, h, 1);
    while(n--) {
      int w;
      scanf("%d", &w);
      if(tree[1]<w) printf("-1\n");
      else printf("%d\n", update(w, 1, h, 1));
    }
  }
}
