#include <cstdio>
int main() {
  int  T, k, S, s, E, v, R, r;
  scanf("%d", &T);
  for(int c=1; c<=T; c++) {
    scanf("%d", &k);
    s = r = 0; R = -2000;
    for(int i=1; i<=k; i++) {
      scanf("%d", &v);
      r += v;
      s = s? s: i;
      if(r>R) {S = s; E = i; R=r;}
      if(r<0) {s = 0; r = 0;}
    }
    printf("Case %d:\n%d %d %d\n", c, R, S, E);
    if(c!=T) putchar('\n');
  }
  return 0;
}
