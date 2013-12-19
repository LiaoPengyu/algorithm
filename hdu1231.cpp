#include <cstdio>
int main() {
  int  k, S, s, E, v, R, r, sf, ss;
  while(scanf("%d", &k), k) {
    R = s = -1; r = sf = 0;
    for(int i=0; i<k; i++) {
      scanf("%d", &v);
      r += v;
      if(!sf) sf = 1, ss = v;
      if(v>=0) s = ~s? s: v;
      if(r>R) {S = s; E = v; R=r;}
      if(r<0) {s = -1; r = 0;}
    }
    if(~R) printf("%d %d %d\n", R, S, E);
    else printf("%d %d %d\n", 0, ss, v);
  }
  return 0;
}
