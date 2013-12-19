#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int S = 1000, SS = 600, MN=33;
int N, NN, m;
double Q, p, s, I[31], dp[MN], ANS, pa, pb, pc;
char t;
bool f;
int main() {
  while(~scanf("%lf%d", &Q, &N) && N) {
    NN = ANS = 0;
    while(N--) {
      scanf("%d", &m);
      pa = pb = pc = s = 0;
      f = false;
      while(m--) {
        scanf(" %c:%lf ", &t, &p);
        if(f) continue;
        if(t-'A'>2 || t-'A'<0) {f = true; continue;}
        if(p > SS) {f = true; continue;}
        if(t == 'A') pa += p;
        if(t == 'B') pb += p;
        if(t == 'C') pc += p;
        s += p;
      }
      if(f || s>S || pa > SS || pb > SS || pc > SS) continue;
      I[NN++] = s;
    }
    fill(dp, dp+NN+1, 0);
    for(int j=0; j<NN; j++)
      for(int i=NN; i; i--)
        dp[i] = max(dp[i], dp[i-1]+I[j]);
    for(int i=NN; i; i--) if(dp[i]<=Q) {ANS = dp[i]; break;}
    printf("%.2lf\n", ANS);
  }
  return 0;
}
