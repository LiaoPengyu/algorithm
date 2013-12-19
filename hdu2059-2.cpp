#include "cstring"
#include "cstdio"
#include "algorithm"
using namespace std;
int const MN = 105;
int L, N, C, T, VR, VT1, VT2, p[MN], i, j, dis;
float tmpt, ANS, dp[MN];
inline void imin(float&a, float b) {
  if(a==-1) a = b;
  else a = min(a, b);
}
int main() {
  while(~scanf("%d", &L)) {
    scanf("%d%d%d", &N, &C, &T);
    scanf("%d%d%d", &VR, &VT1, &VT2);
    for(i=1, p[0]=0, p[N+1]=L; i<=N; i++) scanf("%d", &p[i]);
    if(VT1<=VT2) {
      if(VR > VT2) puts("Good job,rabbit!");
      else puts("What a pity rabbit!");
      continue;
    }
    fill(dp, dp+MN, -1);
    dp[0] = 0;
    for(i=1; i<=N+1; i++)
      for(j=0; j<i; j++)
        if(C>=(dis=p[i]-p[j])) imin(dp[i], dp[j]+(j? T:0)+float(dis)/VT1);
        else imin(dp[i], dp[j]+(j? T:0)+float(C)/VT1+float(dis-C)/VT2);
    // printf("%f\n", dp[N+1]);
    if(dp[N+1] * VR > L) puts("Good job,rabbit!");
    else puts("What a pity rabbit!");
  }
  return 0;
}
