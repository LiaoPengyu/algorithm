#include "cstdio"
int const M = 41;
long R[M][2];
int i, n, m;
int main() {
  for(R[1][0]=R[1][1]=0, R[2][0]=R[2][1]=1, i=3; i<M; i++)
    R[i][0] = R[i-1][1] + R[i-1][0], R[i][1] = R[i-1][0];
  scanf("%d", &n);
  while(n--) {
    scanf("%d", &m);
    printf("%ld\n", R[m][0]);
  }
  return 0;
}
