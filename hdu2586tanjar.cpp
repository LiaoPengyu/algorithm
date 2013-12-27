#include <cstdio>
#include <cstring>
using namespace std;
int const N=40010, M = 210;
struct EDGE {
  int t, n, l;
} E[N<<1], Q[M<<1];
int n, m, t, LE, LQ, HE[N], HQ[N], D[N], P[N], QU[M][3];
bool V[N];
void add(EDGE e[], int&L, int h[], int f, int t, int l) {
  e[L].t = t;
  e[L].l = l;
  e[L].n = h[f];
  h[f] = L++;

  e[L].t = f;
  e[L].l = l;
  e[L].n = h[t];
  h[t] = L++;
}
int find(int t) {
  if(P[t] != t) return P[t] = find(P[t]);
  return t;
}
void tarjan(int f) {
  P[f] = f;
  V[f] = true;
  for(int i = HE[f]; i!=-1; i = E[i].n) {
    if(V[E[i].t]) continue;
    D[E[i].t] = D[f] + E[i].l;
    tarjan(E[i].t);
    P[E[i].t] = f;
  }
  for(int i = HQ[f]; i!=-1; i = Q[i].n)
    if(V[Q[i].t]) QU[Q[i].l][2] = find(Q[i].t);
}
int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    LE = LQ = 0;
    memset(HE, -1, sizeof(HE));
    memset(HQ, -1, sizeof(HQ));
    for(int i=1; i<n; i++) {
      int f, t, l;
      scanf("%d%d%d", &f, &t, &l);
      f--; t--;
      add(E, LE, HE, f, t, l);
    }
    for(int i=0; i<m; i++) {
      int f, t;
      scanf("%d%d", &f, &t);
      f--; t--;
      add(Q, LQ, HQ, f, t, i);
      QU[i][0] = f; QU[i][1] = t;
    }
    D[0] = 0;
    memset(V, false, sizeof(V));
    tarjan(0);
    for(int i=0; i<m; i++)
      printf("%d\n", D[QU[i][0]] + D[QU[i][1]] - 2 * D[QU[i][2]]);
  }
  return 0;
}
