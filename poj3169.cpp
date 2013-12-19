#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define oo 1<<30
const int N = 1010;
struct Edge {
  int t, n, d;
} E[N*N];
int H[N], C[N], D[N], L, f, t, d, n, ml, md;
void add(int f, int t, int d) {
  E[L].t = t;
  E[L].n = H[f];
  E[L].d = d;
  H[f] = L++;
}
bool relax(int&a, int b) {return a>b? (a=b, true): false;}
int SPFA(int s = 1) {
  bool I[N] = {};
  queue<int> Q;
  for(fill(D, D+N, +oo), D[s]=0, I[s]=true, C[s]=1, Q.push(s); !Q.empty(); I[s]=false, Q.pop())
    for(int i=H[s=Q.front()], j; ~i; i=E[i].n)
      if(relax(D[j=E[i].t], D[s]+E[i].d) && !I[j]) {
        if(++C[j]>=n) return -1;
        Q.push(j), I[j]=true;
      }
  if(D[n]==+oo) return -2;
  return D[n];
}
inline void swap(int&a, int&b) {
  int tmp = a;
  a = b;
  b = tmp;
}
int main() {
  scanf("%d%d%d", &n, &ml, &md);
  memset(H, -1, sizeof(H));
  memset(C, 0, sizeof(C));
  for(int i=0; i<ml; i++) {
    scanf("%d%d%d", &f, &t, &d);
    if(f>t) swap(f, t);
    add(f, t, d);
  }
  for(int i=0; i<md; i++) {
    scanf("%d%d%d", &t, &f, &d);
    if(f<t) swap(f, t);
    add(f, t, -d);
  }
  for(int i=1; i<n; i++) add(i+1, i, 0);
  printf("%d\n", SPFA());
  return 0;
}
