#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int const N = 10010, M = 100010;
struct Edge {
  int t, n;
} E[M];
int H[N], L, C, n, m, f, t, LOW[N], DFN[N], S[N], T;
bool V[N], I[N];
void add(int f, int t) {
  E[L].t = t;
  E[L].n = H[f];
  H[f] = L++;
}
void tarjan(int f) {
  if(C) return;
  V[f] = I[f] = true;
  LOW[f] = DFN[f] = L++;
  S[T++] = f;
  for(int i=H[f], j; ~i; i=E[i].n)
    if(!V[j=E[i].t]) {tarjan(j); LOW[f] = min(LOW[f], LOW[j]);}
    else if(I[j]) LOW[f] = min(LOW[f], DFN[j]);
  if(LOW[f] == DFN[f]) do {
      C++; I[S[--T]] = false;
    } while(f != S[T]);
}
int main() {
  while(~scanf("%d%d", &n, &m) && (n || m)) {
    memset(H, -1, sizeof(H));
    memset(V, false, sizeof(V));
    memset(I, false, sizeof(I));
    L = 0;
    for(int i=0; i<m; i++) scanf("%d%d", &f, &t), add(f, t);
    if(n<=1) {puts("Yes"); continue;}
    if(!m) {puts("No"); continue;}
    L = C = T = 0;
    tarjan(E[0].t);
    puts(C==n? "Yes": "No");
  }
  return 0;
}
