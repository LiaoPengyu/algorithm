#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int const N = 1010;
int T, n, i, j, m, s, r[N], ret;
struct Homework {
  int h, s;
  bool operator<(Homework const&o) const {
    if(s==o.s) return h>o.h;
    return s>o.s;};
} h[N];
int main() {
  scanf("%d", &T);
  while(T-- && scanf("%d", &n)) {
    for(i=1, m=0; i<=n; i++) scanf("%d", &h[i].h), m=max(m, h[i].h);
    for(i=1, s=0; i<=n; i++) scanf("%d", &h[i].s), s+=h[i].s;
    sort(h+1, h+n+1);
    for(memset(r, 0, sizeof(r)), ret=0, i=1; i<=n; i++)
      for(j=h[i].h ;j>0; j--)
        if(!r[j]) {
          r[j] = i, ret +=h[i].s;
          break;
        }
    printf("%d\n", s-ret);
  }
  return 0;
}
