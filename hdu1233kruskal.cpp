#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
#define oo 1<<25
int const N = 110;
int f, t, c, n, L, P[N], s, i;
struct Edge {int f, t, c;} E[(N*N)<<1];
bool cmp(Edge const&a, Edge const&b) {return a.c < b.c;}
void add(int f, int t, int c) {
  E[L].f = f;
  E[L].t = t;
  E[L++].c = c;
}
int find(int p) {
  if(P[p]<0) return p;
  return P[p]=find(P[p]);
}
void union_p(int a, int b) {
  int ra=find(a), rb=find(b);
  if(ra == rb) return;
  if(P[ra]>P[rb]) {
    P[rb]+=P[ra];
    P[ra]=rb;
  } else {
    P[ra]+=P[rb];
    P[rb]=ra;
  }
}
int kruskal() {
  int s=0, ret=0, rf, rt;
  memset(P, -1, sizeof(P));
  for(; s<L; s++) {
    if((rf=find(E[s].f)) != (rt=find(E[s].t))) {
      union_p(E[s].f, E[s].t);
      ret += E[s].c;
    }
    if(P[rf]==-n) break;
  }
  return ret;
}
int main() {
  while(scanf("%d", &n), n) {
    for(s=n*(n-1)/2, L=i=0; i<s && scanf("%d%d%d", &f, &t, &c); i++)
      add(f, t, c);
    sort(E, E+L, cmp);
    printf("%d\n", kruskal());
  }
  return 0;
}
