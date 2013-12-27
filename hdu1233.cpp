#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
#define oo 1<<25
int const N = 110;
int f, t, c, n, H[N], L, D[N], s, i;
bool V[N];
struct Edge {int t, n, c;} E[(N*N)<<1];
void add(int f, int t, int c) {
  E[L].t = t;
  E[L].c = c;
  E[L].n = H[f];
  H[f] = L++;
  E[L].t = f;
  E[L].c = c;
  E[L].n = H[t];
  H[t] = L++;
}
bool relax(int&w, int c) {return w>c? (w=c, true): false;}
int prim(int s=1) {
  int nn=n, ret=0, tmp;
  fill(D+1, D+1+n, +oo);
  memset(V, false, sizeof(V));
  while(nn--) {
    V[tmp=s] = true;
    for(i=H[s]; ~i; i=E[i].n) if(!V[E[i].t]) relax(D[E[i].t], E[i].c);
    for(i=1; i<=n; i++) if(!V[i]) s = s==tmp? i: (D[i]<D[s]? i: s);
    if(!V[s]) ret += D[s];
  }
  return ret;
}
int main() {
  while(scanf("%d", &n), n) {
    for(memset(H, -1, sizeof(H)), s=n*(n-1)/2, L=i=0; i<s && scanf("%d%d%d", &f, &t, &c); i++)
      add(f, t, c);
    printf("%d\n", prim());
  }
  return 0;
}
