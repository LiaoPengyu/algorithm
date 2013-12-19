#include <cstring>
#include <cstdio>
using namespace std;
int const MaxV = 1000;
int const MaxE = MaxV * (MaxV-1) / 2;
int n, m, du[MaxV], H[MaxV], P, p[MaxV];
int find(int n) {
  if(p[n]>=0) {p[n] = find(p[n]); return p[n];}
  else return n;
}
void unionp(int f, int t) {
  int rf = find(f);
  int rt = find(t);
  if(rf == rt) return;
  if(p[rf]>p[rt]) {
    p[rt] += p[rf];
    p[rf] = rt;
  } else {
    p[rf] += p[rt];
    p[rt] = rf;
  }
}
bool check() {
  for(int i=1, c=find(0); i<n; i++)
    if(find(i) != c) return false;
  for(int i=0; i<n; i++) {
    if(du[i] & 1) return false;
  }
  return true;
}
int main() {
  while(scanf("%d", &n) && n) {
    memset(du, 0, sizeof(du));
    memset(p, -1, sizeof(p));
    scanf("%d", &m);
    P = 0;
    for(int i=0; i<m; i++) {
      int f, t;
      scanf("%d%d", &f, &t);
      f--; t--;
      unionp(f, t);
      du[f] ++; du[t] ++;
    }
    if(!check()) puts("0");
    else puts("1");
  }
  return 0;
}
