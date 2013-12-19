#include <cstring>
#include <cstdio>
using namespace std;
int const N = 50010;
int n, k, ans=0, d, x, y, P[N], D[N];
int find(int p) {
  if(P[p] == P[P[p]]) return P[p];
  int ret = find(P[p]);
  D[p] = (D[P[p]] + D[p]) % 3;
  P[p] = ret;
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  for(int i=1; i<=n; i++) {P[i] = i; D[i] = 0;}
  while(k--) {
    scanf("%d%d%d", &d, &x, &y);
    if(x>n || y>n || (x==y && d == 2)) {ans++; continue;}
    int px = find(x);
    int py = find(y);
    if(px == py && (D[y]-D[x]+4) % 3 != d) {ans++; continue;}
    else {
        P[py] = px;
        D[py] = (D[px] + D[x] - D[y] + d + 2)%3;
    }
  }
  printf("%d\n", ans);
}
