#include "cstring"
#include "cstdio"
#include "algorithm"
using namespace std;
int const N = 1010;
int c, m, n, i, j, mat[N][N], le[N], ri[N], ANS;
char ch;
int main() {
  scanf("%d", &c);
  while(c--) {
    scanf("%d%d", &m, &n);
    for(i=1, memset(mat, 0, sizeof(mat)); i<=m; i++)
      for(j=1; j<=n && scanf(" %c ", &ch); j++)
        if(ch=='F') mat[i][j] = mat[i-1][j]+1;
    for(i=1, ANS=0; i<=m; i++) {
      for(j=1; j<=n; j++) le[j] = ri[j] = j;
      for(j=2; j<=n; j++) if(mat[i][j]) while(mat[i][le[j]-1] >= mat[i][j]) le[j] = le[le[j]-1];
      for(j=n-1; j>=1; j--) if(mat[i][j]) while(mat[i][ri[j]+1] >= mat[i][j]) ri[j] = ri[ri[j]+1];
      for(j=1; j<=n; j++) if(mat[i][j]) ANS = max(ANS, mat[i][j]*(ri[j]-le[j]+1));
    }
    printf("%d\n", ANS*3);
  }
  return 0;
}
