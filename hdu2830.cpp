#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const N = 1010, M = 1010;
int n, m, v[N][M], l[N], i, j, k, ANS;
char mat[M];
inline void add(int p) {for(; p<=n; p+=(p&-p)) l[p]++;}
inline int get(int p, int ret=0) {for(; p>=1; p-=(p&-p)) ret+=l[p]; return ret;}
int main() {
  while(~scanf("%d%d", &n, &m)) {
    for(memset(v, 0, sizeof(v)), i=1; i<=n && scanf(" %s ", mat); i++)
      for(j=1; j<=m; j++)
        if(mat[j-1]-'0') v[i][j] = v[i-1][j] + 1;
    for(i=1, ANS=0; i<=n; i++) {
      for(memset(l, 0, sizeof(l)), j=1; j<=m; j++) if(v[i][j]) add(v[i][j]);
      for(j=1, k=get(n); j<=m; j++) ANS = max(ANS, v[i][j]*(k-get(v[i][j]-1)));
    }
    printf("%d\n", ANS);
  }
  return 0;
}
