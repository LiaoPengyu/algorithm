#include <cstdio>
#include <cstring>
using namespace std;
#define oo 1<<25
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
int const N = 1050;
struct EDGE {
  int t, n, c;
} E[N*N];
int tt, ss, dd, H[N], L, f, t, c, D[N];
bool V[N];
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
struct NODE {
  int f, d;
} T[N<<2];
void PushUp(int rt) {
  int l=rt<<1, r=rt<<1|1;
  if(T[l].d < T[r].d) T[rt].d = T[l].d, T[rt].f = T[l].f;
  else T[rt].d = T[r].d, T[rt].f = T[r].f;
}
void build(int l=1, int r=N, int rt=1) {
  if(l==r) {
    D[l] = +oo;
    T[rt].d = +oo;
    T[rt].f = l;
    return;
  }
  int m = (l+r) >> 1;
  build(lson);
  build(rson);
  PushUp(rt);
}
void insert(int p, int v, int l=1, int r=N, int rt=1) {
  if(l==r) {
    D[l] = v;
    T[rt].d = v;
    return;
  }
  int m = (l+r) >> 1;
  if(p<=m) insert(p, v, lson);
  else insert(p, v, rson);
  PushUp(rt);
}
void pop(int p, int l=1, int r=N, int rt=1) {
  if(l==r) {
    T[rt].d = +oo;
    return;
  }
  int m = (l+r) >> 1;
  if(p<=m) pop(p, lson);
  else pop(p, rson);
  PushUp(rt);
}
void Relax(int s, int w, int r) {if(D[s] > w) insert(s, w); pop(r);}
bool Relax(int&s, int w) {return s>w? (s=w, true): false;}
void dijkstra(int s = 0) {
  int times = N, tmp;
  D[s] = 0;
  while(times--) {
    V[tmp=s] = true;
    for(int i=H[s], j; ~i; i=E[i].n)
      if(!V[j=E[i].t]) Relax(D[j], D[s] + E[i].c);
    for(int i=0; i<N; i++)
      if(!V[i]) s = tmp == s? i: (D[i]<D[s]? i: s);
  }
}
int main() {
  while(~scanf("%d%d%d", &tt, &ss, &dd)) {
    memset(H, -1, sizeof(H));
    memset(V, false, sizeof(V));
    L = 0;
    for(int i=0; i<N; i++) D[i] = +oo;
    for(int i=0; i<tt; i++) {
      scanf("%d%d%d", &f, &t, &c);
      add(f, t, c);
    }
    build();
    for(int i=0; i<ss; i++) {
      scanf("%d", &t);
      add(0, t, 0);
    }
    dijkstra(0);
    int ans = +oo;
    for(int i=0; i<dd; i++) {
      scanf("%d", &t);
      ans = ans>D[t]? D[t]: ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}
