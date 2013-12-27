#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int const N = 50010;
struct Node {
  int k, a, p, l, r;
} T[N];
bool cmp(int i, int j) {return T[i].k<T[j].k;}
int n, i, j, top, TT[N], S[N];
void insert() {
  int ii = top;
  while(~ii && T[S[ii]].a>T[i].a) ii--;
  if(~ii) T[S[ii]].r = i, T[i].p = S[ii];
  if(ii<top) T[i].l = S[ii+1], T[S[ii+1]].p = i;
  S[++ii] = i;
  top = ii;
}
int main() {
  scanf("%d", &n);
  top = -1;
  for(i=1; i<=n; i++) scanf("%d%d", &T[i].k, &T[i].a), TT[i]=i;
  sort(TT+1, TT+n+1, cmp);
  for(i=TT[1], j=1; j<=n; j++, i=TT[j]) insert();
  puts("YES");
  for(i=1; i<=n; i++) printf("%d %d %d\n", T[i].p, T[i].l, T[i].r);
  return 0;
}
