#include "cstring"
#include "cstdio"
#include "memory"
#include "algorithm"
using namespace std;
int const MN = 105;
int L, N, C, T, VR, VT1, VT2, p[MN], i, j, per, dis;
double tmpt, ANS;
inline void imin(double&a, double b) {
  if(a<0) a = b;
  else a = min(a, b);
}
int main() {
  while(~scanf("%d", &L)) {
    scanf("%d%d%d", &N, &C, &T);
    scanf("%d%d%d", &VR, &VT1, &VT2);
    for(i=1, p[0]=0; i<=N; i++) scanf("%d", &p[i]);
    if(VT1<=VT2) {
      if(VR > VT2) puts("Good job,rabbit!");
      else puts("What a pity rabbit!");
      continue;
    }
    double*dp = new double[(N+1)*(C+1)];
    fill(dp, dp + (N+1) * (C+1), -1);
    dp[0+C] = 0;
    for(i=1, per=(i-1)*(C+1); i<=N; i++, per=(i-1)*(C+1))
      for(j=0; j<=C; j++)
        if(dp[per+j] >= 0) {
          if(j>=(dis=p[i]-p[i-1]))  {
            tmpt = (double(dis)/VT1);
            imin(dp[i*(C+1)+C], dp[per+j] + tmpt + T);
            imin(dp[i*(C+1)+j-dis], dp[per+j] + tmpt);
          } else {
            tmpt = double(j)/VT1 + double(dis-j)/VT2;
            imin(dp[i*(C+1)+C], dp[per+j] + tmpt + T);
            imin(dp[i*(C+1)], dp[per+j] + tmpt);
          }
        }
    ANS = -1;
    for(i = 0, per=N*(C+1); i<=C; i++)
      if(dp[per+i] >= 0)
        if(i>=(dis=L-p[N])) imin(ANS, dp[per+i] + double(dis)/VT1);
        else imin(ANS, dp[per+i] + double(i)/VT1 + double(dis-i)/VT2);
    if(L > VR * ANS) puts("What a pity rabbit!");
    else puts("Good job,rabbit!");
    // printf("%f\n", ANS);
    delete []dp;
  }
  return 0;
}
