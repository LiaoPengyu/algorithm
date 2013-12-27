#include <cstdio>
#include <cstring>
using namespace std;
int const N = 30001;
int n, h, v, tree[N<<2];
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
inline void PushUp(int rt) {tree[rt] = tree[rt<<1] > tree[rt<<1|1]? tree[rt<<1]: tree[rt<<1|1];}
void insert(int h, int v, int l=1, int r=N, int rt=1) {
  if(l==r) {tree[rt] = v+1; return;}
  int m = (l+r) >> 1;
  if(h<=m) insert(h, v, lson);
  else insert(h, v, rson);
  PushUp(rt);
}
int query(int R, int l=1, int r=N, int rt=1) {
  if(R>=r) return tree[rt];
  int m = (l+r) >> 1;
  if(R <= m) return query(R, lson);
  int a = query(R, lson);
  int b = query(R, rson);
  return a>b? a: b;
}
int main() {
  while(~scanf("%d", &n)) {
    memset(tree, 0, sizeof(tree));
    while(n--) {
      scanf("%d", &h);
      if(h>1) insert(h, query(h-1));
      else insert(1, 1);
    }
    printf("%d\n", tree[1]);
  }
  return 0;
}
