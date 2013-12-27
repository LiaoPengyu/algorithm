#include <cstdio>
#include <cstring>
int const N = 10010;
int p[N], v[N], C, n, i, f ,t;
int main() {
  scanf("%d", &C);
  while(C--) {
    memset(v, 0, sizeof(v));
    memset(p, 0, sizeof(p));
    scanf("%d", &n);
    for(i=1; i<n; i++) {
      scanf("%d%d", &f, &t);
      p[t] = f;
    }
    scanf("%d%d", &f, &t);
    while(f) {v[f] = 1; f=p[f];}
    while(!v[t]) t=p[t];
    printf("%d\n", t);
  }
  return 0;
}
