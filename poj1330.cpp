#include <cstring>
#include <cstdio>
using namespace std;
int const N = 10010;
int L, H[N], F, T, ANS, I[N], P[N];
bool V[N];
struct EDGE {
  int t, n;
} E[N];
void add(int f, int t) {
  E[L].t = t;
  E[L].n = H[f];
  H[f] = L++;
}
int find(int n) {
  while(n != P[n]) n = P[n];
  return n;
}
void tarjan(int f) {
  P[f] = f;
  V[f] = true;
  if(f == F && V[T]) {ANS = find(T); return;}
  if(f == T && V[F]) {ANS = find(F); return;}
  for(int i = H[f]; i!=-1; i = E[i].n) {
    tarjan(E[i].t);
    if(ANS != -1) return;
    P[E[i].t] = f;
  }
}
int main() {
  int c, n, r;
  scanf("%d", &c);
  while(c--) {
    scanf("%d", &n);
    L = 0;
    memset(H, -1, sizeof(H));
    memset(V, false, sizeof(V));
    memset(I, 0, sizeof(I));
    for(int i=1; i<n; i++) {
      scanf("%d%d", &F, &T);
      F--; T--;
      add(F, T);
      I[T] ++;
    }
    scanf("%d%d", &F, &T);
    F--; T--;
    for(r=0; I[r]; r++);
    ANS = -1;
    tarjan(r);
    printf("%d\n", ++ANS);
  }
}
