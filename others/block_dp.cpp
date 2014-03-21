// 用1×1,1×2,2×1的格子填满k×(2^n)的方块，k不大于5,n不大于1024
#include <cstring>
#include <cstdio>

#ifdef WIN32
#define ll __int64
#else
#define ll long long
#endif // WIN32

#define MOD 1000000007

void cal(int a[][32][32], int mc, int col, int now, int next) {
  if(col>=mc) {
    a[mc][now][next]++;
    return;
  }
  cal(a, mc, col+1, now, next);
  if(((now>>col) & 1) == 0) {
    cal(a, mc, col+1, now, next | (1<<col));
    if((col+1<mc) && ((now>>(col+1)) & 1) == 0)
      cal(a, mc, col+2, now, next);
  }
}
inline int mul(ll a, ll b) {
  return a * b % MOD;
}
void multiply(int len, int a[32][32], int b[32][32]) {
  int i, j, k;
  for(i=0; i<len; i++)
    for(j=0; j<len; j++)
      for(k=b[i][j]=0; k<len; k++)
        if((b[i][j] += mul(a[i][k], a[k][j])) >= MOD)
          b[i][j] -= MOD;
}
int calculate(int n, int k) {
  int a[6][32][32], mat[2][32][32];
  int i, j;
  memset(a, 0, sizeof(a));
  for(i=1; i<6; i++)
    for(j=(1<<i)-1; j>=0; j--)
      cal(a, i, 0, j, 0);
  memcpy(mat[0], a[k], sizeof(mat[0]));
  k = 1<<k;
  for(i=0; n; n--) {
    multiply(k, mat[i], mat[i^1]);
    i ^= 1;
  }
  return mat[i][0][0];
}

int main() {
  printf("%d\n", calculate(1024, 5));
  return 0;
}
