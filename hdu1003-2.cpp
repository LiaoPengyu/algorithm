#include <cstdio>
int main() {
  int  T, k, S, s, E, e, v, R, r;
  scanf("%d", &T);
  for(int c=1; c<=T; c++) {
    scanf("%d", &k);
    s = e = 1; r = R = -2000;
    for(int i=1; i<=k; i++) {
      scanf("%d", &v);
      if(r < 0) {r=v; s = e = i;}
      else if(0 < r) {r+=v; e = i;}
      else if(v > 0) {r=v; e = i;}
      if(r > R) {R=r; S=s; E=e;}
    }
    printf("Case %d:\n%d %d %d\n", c, R, S, E);
    if(c!=T) putchar('\n');
  }
  return 0;
}
