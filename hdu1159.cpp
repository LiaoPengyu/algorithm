#include "cstdio"
#include "algorithm"
using namespace std;
int const N = 501;
int i, j, dp[N][N];
char a[N], b[N];
int main() {
  while(~scanf(" %s ", a+1)) {
    scanf(" %s ", b+1);
    for(i=1; a[i]; i++)
      for(j=1; b[j]; j++)
        dp[i][j] = a[i] == b[j]? dp[i-1][j-1]+1: max(dp[i][j-1], dp[i-1][j]);
    printf("%d\n", dp[i-1][j-1]);
  }
  return 0;
}
