#include <cstring>
#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

int const N = 100010;
int const VN = 5010;
struct Edge {
  int to, next, cost;
} edges[N<<1];
int n, r, f, t, c, H[VN], i, CNT;
void insert(int f, int t, int c) {
  edges[CNT].to = t;
  edges[CNT].cost = c;
  edges[CNT].next = H[f];
  H[f] = CNT++;

  edges[CNT].to = f;
  edges[CNT].cost = c;
  edges[CNT].next = H[t];
  H[t] = CNT++;
}
int D[VN], D2[VN];
inline bool relax(int &t, int c, int &nc) {
  return (t > c) ? (nc = t, t = c, true) : false;
}
#define oo 1<<23
int solve(int s = 1) {
  typedef pair<int, int> P;
  priority_queue<P, vector<P>, greater<P> > que;
  fill(D, D + n + 1, +oo);
  fill(D2, D2 + n + 1, +oo);
  D[s] = 0;
  que.push(P(D[s], s));
  while (!que.empty()) {
    P t = que.top(); que.pop();
    if (t.first > D2[t.second]) continue;
    for (int i = H[t.second], j, nc; ~i; i = edges[i].next) {
      if (relax(D[j = edges[i].to], nc = t.first + edges[i].cost, nc))
        que.push(P(D[j], j));
      if (nc > D[j] && relax(D2[j], nc, nc))
        que.push(P(D2[j], j));
    }
  }
  return D2[n];
}
int main() {
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  scanf("%d%d", &n, &r);
  memset(H, -1, sizeof(H));
  for (i = CNT = 0; i < r; i++) {
    scanf("%d%d%d", &f, &t, &c);
    insert(f, t, c);
  }
  printf("%d\n", solve());
  return 0;
}
