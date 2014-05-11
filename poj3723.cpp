#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const N = 10010;
int const R = 50010;
struct Edge {
  int x, y, d;
  bool operator<(Edge const& other) const {
    return d > other.d;
  }
} E[R];
int C, n, m, r, x, y, d, i, P[N << 1];
long long ANS;
int find(int p) {
  if (P[p] == p) return p;
  else return P[p] = find(P[p]);
}
int main() {
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  scanf("%d", &C);
  while (C--) {
    scanf("%d%d%d", &n, &m, &r);
    for (i = 0; i < r; i++) {
      scanf("%d%d%d", &x, &y, &d);
      E[i].x = x, E[i].y = y + n, E[i].d = d;
    }
    for (i = 0; i < n + m; i++) P[i] = i;
    sort(E, E + r);
    for (i = ANS = 0; i < r; i++) {
      x = find(E[i].x); y = find(E[i].y);
      if (x == y) continue;
      else {
        ANS -= E[i].d;
        P[x] = y;
      }
    }
    printf("%lld\n", ANS + (n+m) * 10000);
  }
  return 0;
}
