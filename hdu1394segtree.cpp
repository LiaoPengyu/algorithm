#include <cstdio>
#include <iostream>

using namespace std;
const int N = 5000;
int tree[N<<2];
int seq[N];

void build(int l, int r, int rt) {
  tree[rt] = 0;
  if(l==r) return;
  int m = (l+r) >> 1;
  build(l, m, rt<<1);
  build(m+1, r, rt<<1|1);
}

inline void refresh(int rt) {
  tree[rt] = tree[rt<<1] + tree[rt<<1 | 1];
}
void update(int p, int l, int r, int rt) {
  if(l==r)
    {
      tree[rt]++;
      return;
    }
  int m = (l+r) >> 1;
  if(p<=m) update(p, l, m, rt<<1);
  else update(p, m+1, r, rt<<1|1);
  refresh(rt);
}

int query(const int L, const int R, int l, int r, int rt) {
  if(L<=l&&R>=r) return tree[rt];
  int m = (l+r)>>1, ret=0;
  if(L<=m) ret+= query(L, R, l, m, rt<<1);
  if(R>m) ret+= query(L, R, m+1, r, rt<<1 | 1);
  return ret;
}

int main() {
  int n;
  while(~scanf("%d", &n)) {
    int sum=0, ret;
    build(0, n-1, 1);
    for(int i=0; i<n; i++) {
      scanf("%d", &seq[i]);
      sum += query(seq[i], n-1, 0, n-1, 1);
      update(seq[i], 0, n-1, 1);
    }
    ret = sum;
    for(int i = 0; i<n; i++) {
      sum += n-1 - seq[i] - seq[i];
      ret = min(ret, sum);
    }
    printf("%d\n", ret);
  }
  return 0;
}
