#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int const N = 4000;
struct EDGE {
  int t, n;
} E[N];
int n, H[N], I[N], L, P[N], R[N];
vector<int> Q[N];
bool V[N];
void add(int f, int t) {
  E[L].t = t;
  E[L].n = H[f];
  H[f] = L++;
}
int find(int p) {
  if(p != P[p]) return P[p] = find(P[p]);
  return p;
}
void tarjan(int f) {
  P[f] = f;
  V[f] = true;
  for(int i=0; i<(int)Q[f].size(); i++)
    if(V[Q[f][i]]) R[find(Q[f][i])]++;
  for(int i=H[f]; ~i; i=E[i].n) {
    tarjan(E[i].t);
    P[E[i].t] = f;
  }
}
int main() {
  while(~scanf("%d", &n)) {
    memset(H, -1, sizeof(H));
    memset(V, false, sizeof(V));
    memset(R, 0, sizeof(R));
    memset(I, 0, sizeof(I));
    for(int i=0; i<n; i++) Q[i].clear();
    int f, c, t, r, q;
    L = 0;
    for(int i=0; i<n; i++) {
      scanf("%d:(%d)", &f, &c);
      f--;
      while(c--) {
        scanf("%d", &t);
        add(f, t-1);
        I[t-1]++;
      }
    }
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
      scanf(" (%d %d)", &f, &t);
      f--; t--;
      Q[f].push_back(t); Q[t].push_back(f);
    }
    for(r = 0; I[r]; r++);
    tarjan(r);
    for(int i=0; i<n; i++)
      if(R[i]) printf("%d:%d\n", i+1, R[i]);
  }
  return 0;
}
