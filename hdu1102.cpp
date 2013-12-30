#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define oo 1<<25
int const N = 105;
struct Edge {
  int t, n, d;
} E[N*N];
int i, j, n, q, f, t, d, H[N], L, D[N];
void add(int f, int t, int d) {
  E[L].t = t;
  E[L].d = d;
  E[L].n = H[f];
  H[f] = L++;
  E[L].t = f;
  E[L].d = d;
  E[L].n = H[t];
  H[t] = L++;
}
bool relax(int&w, int c) {return w>c? (w=c, true): false;}
int prim(int s=1) {
  int tmp, nn=n, ret=0;
  bool v[N] = {};
  fill(D+1, D+n+1, +oo);
  while(nn--) {
    v[s] = true;
    for(i=H[tmp=s]; ~i; i=E[i].n)
      if(!v[E[i].t]) relax(D[E[i].t], E[i].d);
    for(i=1; i<=n; i++)
      if(!v[i]) s = s==tmp? i: (D[s]<D[i]? s: i);
    if(!v[s]) ret += D[s];
    else break;
  }
  return ret;
}
int main() {
  while(~scanf("%d", &n)) {
    for(memset(H, -1, sizeof(H)), L=0, i=1; i<=n; i++)
      for(j=1; j<=n && scanf("%d", &d); j++)
        if(j>i) add(i, j, d);
    scanf("%d", &q);
    for(i=1; i<=q && scanf("%d%d", &f, &t); i++)
      for(j=H[f]; ~j; j=E[j].n)
        if(E[j].t == t) {
          E[j].d = E[j^1].d = 0;
          break;
        }
    printf("%d\n", prim());
  }
  return 0;
}
