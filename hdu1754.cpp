#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 200000 << 2;
int tree[N];

void refresh(int rt)
{
  tree[rt] = max(tree[rt<<1], tree[rt<<1 | 1]);
}

void build(int l, int r, int rt) {
  if (l == r) {
    scanf("%d", &tree[rt]);
    return;
  }
  int m = (l+r) >> 1;
  build(l, m, rt<<1);
  build(m+1, r, rt<<1 | 1);
  refresh(rt);
}

void update(const int pos, const int v, int l, int r, int rt) {
  if(l==r) {
    tree[rt] = v;
    return;
  }
  int m = (l+r) >> 1;
  if(pos <= m) update(pos, v, l, m, rt<<1);
  else update(pos, v, m+1, r, rt<<1 | 1);
  refresh(rt);
}

int query(int L, int R, int l, int r, int rt) {
  if(L <= l && R >= r) return tree[rt];
  int m = (l+r) >> 1;
  int ret = -1;
  if(L <= m ) ret = max(ret, query(L, R, l, m, rt<<1));
  if(R > m) ret = max(ret, query(L, R, m+1, r, rt<<1 | 1));
  return ret;
}

int main() {
  int n , m;
  while (~scanf("%d%d",&n,&m)) {
    build(1 , n , 1);
    while (m --) {
      char op[2];
      int a , b;
      scanf("%s%d%d",op,&a,&b);
      if (op[0] == 'Q') printf("%d\n",query(a , b , 1 , n , 1));
      else update(a , b , 1 , n , 1);
    }
  }
  return 0;
}
