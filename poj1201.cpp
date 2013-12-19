#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define oo 1<<30
const int N = 50010;
struct Edge {
  int t, n, d;
} E[N<<2];
int H[N], D[N], L, n, a, b, c, MIN, MAX;
void add(int f, int t, int d) {
  E[L].t = t;
  E[L].d = d;
  E[L].n = H[f];
  H[f] = L++;
}
bool relax(int&a, int b) {return a<b? (a=b, true): false;}
int SPFA(int s = MIN) {
  bool I[N] = {};
  queue<int> Q;
  for(fill(D, D+N, -oo), D[s]=0, I[s]=true, Q.push(s); !Q.empty(); I[s]=false, Q.pop())
    for(int i=H[s=Q.front()], j; ~i; i=E[i].n)
      if(relax(D[j=E[i].t], D[s]+E[i].d) && !I[j]) I[j]=true, Q.push(j);
  return D[MAX];
}
int main() {
  scanf("%d", &n);
  MIN = +oo, MAX = 0;
  memset(H, -1, sizeof(H));
  while(n--) {
    scanf("%d%d%d", &a, &b, &c);
    MIN = min(a, MIN);
    MAX = max(b+1, MAX);
    add(a, b+1, c);
  }
  for(int i=MIN; i<MAX; i++) add(i, i+1, 0), add(i+1, i, -1);
  printf("%d\n", SPFA());
  return 0;
}
