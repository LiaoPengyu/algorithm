#include <cstdio>
int const N = 10001;
int r[N], ret;
int main() {
  for(int i=1, j=1, k=0; i<N; j++, k=0)
    for(;k<j; k++, i++) r[i] = r[i-1] + j;
  while(~scanf("%d", &ret) && ret)
    printf("%d %d\n", ret, r[ret]);
  return 0;
}
