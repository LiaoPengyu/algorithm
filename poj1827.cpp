#include <cstring>
#include <cstdio>
using namespace std;
int const N = 1010, M = 2010;
struct EDGE {
  int t, n;
} E[M];
int n, m, i, f, t, L, H[N], P[N], C[N];
void add(int f, int t) {
  E[L].t = t;
  E[L].n = H[f];
  H[f] = L++;
}
int find(int p) {
  if(P[p] > 0) P[p] = find(P[p]);
  return p;
}
void unions(int f, int t) {
  int rf = find(f);
  int rt = find(t);
  if(rf == rt) return;
  if(P[rf] < P[rt]) {
    int tmp = P[rt];
    P[rt] = rf;
    P[rf] += tmp;
  }
}
int main() {
  while(~scanf("%d%d", &n, &m)) {
    memset(H, -1, sizeof(H));
    memset(P, -1, sizeof(P));
    L = 0;
    for(i=0; i<m; i++) {
      scanf("%d%d", &f, &t);
      add(f, t);
      unions(f, t);
    }
  }
  return 0;
}
