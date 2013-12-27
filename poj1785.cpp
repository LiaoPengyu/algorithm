#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const N = 50010;
struct Node {
  char f[100];
  int s, l, r;
} T[N];
bool cmp(int i, int j) {return strcmp(T[i].f, T[j].f)<0;}
int n, i, j, S[N], top, TT[N];
void insert() {
  int ii = top;
  while(~ii && T[S[ii]].s < T[i].s) ii--;
  if(~ii) T[S[ii]].r = i;
  if(ii<top) T[i].l = S[ii+1];
  S[++ii] = i;
  top = ii;
}
void print(int r) {
  putchar('(');
  if(T[r].l)print(T[r].l);
  printf("%s/%d", T[r].f, T[r].s);
  if(T[r].r)print(T[r].r);
  putchar(')');
}
int main() {
  while(scanf("%d", &n) && n) {
    top = -1;
    memset(T, 0, sizeof(T));
    for(i=1; i<=n; i++) scanf(" %[a-z]/%d ", T[i].f, &T[i].s), TT[i]=i;
    sort(TT+1, TT+n+1, cmp);
    for(i=TT[1], j=1; j<=n; ++j, i=TT[j]) insert();
    print(S[0]);
    putchar('\n');
  }
  return 0;
}
