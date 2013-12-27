#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define oo 1<<25
int const N = 1050;
int TT, SS, DD, f, t, c, H[N], L, D[N], ans;
bool I[N];
struct EDGE {
  int t, n ,c;
} E[N*N];
void add(int f, int t, int c) {
  E[L].t = t;
  E[L].c = c;
  E[L].n = H[f];
  H[f] = L++;
  E[L].t = f;
  E[L].c = c;
  E[L].n = H[t];
  H[t] = L++;
}
bool Relax(int &d, int c) {return d>c? (d=c, true): false;}
void spfa(int s=0) {
  queue<int> Q;
  for(D[s]=0, I[s]=true, Q.push(s); !Q.empty(); Q.pop(), I[s]=false) {
    for(int i=H[s=Q.front()], j; ~i; i=E[i].n)
      if(Relax(D[j=E[i].t], D[s]+E[i].c) && !I[j]) Q.push(j), I[j] = true;
  }
}
int main() {
  while(~scanf("%d%d%d", &TT, &SS, &DD)) {
    L = 0;
    memset(H, -1, sizeof(H));
    memset(I, false, sizeof(I));
    for(int i=0; i<N; i++) D[i] = +oo;
    for(int i=0; i<TT; i++) {
      scanf("%d%d%d", &f, &t, &c);
      add(f, t, c);
    }
    for(int i=0; i<SS; i++) {
      scanf("%d", &t);
      add(0 ,t, 0);
    }
    spfa(0);
    ans = +oo;
    for(int i=0; i<DD; i++) {
      scanf("%d", &t);
      ans = min(ans, D[t]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
