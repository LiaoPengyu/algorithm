#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int const N = 1010, M = 1010;
int m, n, c[M][N][3], i, j, k, ANS, top[M], bottom[M];
char str[N], mat;
inline void inc(int ch) {c[i][j][ch] = c[i][j-1][ch] + 1;}
int main() {
  while(~scanf("%d%d ", &m, &n)) {
    for(i=1, memset(c, 0, sizeof(c)); i<=m && scanf(" %s", str); i++)
      for(j=1; j<=n && (mat=str[j-1]); j++)
        if(mat=='a') inc(0);
        else if(mat=='b') inc(1);
        else if(mat=='c') inc(2);
        else if(mat=='w') inc(0), inc(1);
        else if(mat=='x') inc(1), inc(2);
        else if(mat=='y') inc(0), inc(2);
        else if(mat=='z') inc(0), inc(1), inc(2);
    for(k=0, ANS=0; k<3; k++)
      for(j=1; j<=n; j++) {
        for(i=1; i<=m; i++) top[i] = bottom[i] = i;
        for(i=2; i<=m; i++) if(c[i][j][k]) while(c[top[i]-1][j][k] >= c[i][j][k]) top[i] = top[top[i]-1];
        for(i=m-1; i>=1; i--) if(c[i][j][k]) while(c[bottom[i]+1][j][k] >= c[i][j][k]) bottom[i] = bottom[bottom[i]+1];
        for(i=1; i<=m; i++) if(c[i][j][k]) ANS = max(ANS, c[i][j][k] * (bottom[i]-top[i]+1));
      }
    printf("%d\n", ANS);
  }
  return 0;
}
