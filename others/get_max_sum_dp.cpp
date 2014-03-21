// 有n×n个格子，每个格子有正数或者0,从左上角往右下走，只能向下和向右，走两趟，求做过的格子中数字之和。如果一个格子两趟都经过，只加一次。
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

#define ad(x, y) ((x)==(y)? 0: a[(k+1)*n+i+j-k])
#define ar(x, y) ((x)==(y)? 0: a[(k)*n+i+j-k+1])

int const MN = 202;
int dp[MN][MN][MN];

int get_sum(int* a, int n) {
  int i, j, k;
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = a[0];
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      for(k=0; k<=i; k++) {
        if(i+1<n && k+1<n) dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + a[(i+1)*n+j] + ad(i+1, k+1));
        if(j+1<n && (i+j-k+1<n)) dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k] + a[(i)*n+j+1] + ar(i, k));
        if(i+1<n && (i+j-k+1<n)) dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + a[(i+1)*n+j] + ar(i+1, k));
        if(j+1<n && k+1<n) dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + a[(i)*n+j+1] + ad(i, k+1));
      }
  return dp[n-1][n-1][n-1];
}

int main() {
  int a[][6]={
    {0,0,3,0,2,0},
    {0,0,3,0,0,0},
    {0,0,3,0,0,0},
    {0,0,0,0,4,0},
    {0,0,0,0,4,0},
    {0,0,3,0,0,0}};
  int n = 6;
  printf("%d\n", get_sum((int*)a, n));

  return 0;
}
