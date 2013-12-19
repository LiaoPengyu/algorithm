#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
int T, n, m, L, S, ANS;
double P, p, dp[N*N];
struct Item {
  int v;
  double p;
} I[N];
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%lf%d", &P, &n);
    ANS = L = S = 0, P = 1 - P;
    while(n--) {
      scanf("%d%lf", &m, &p);
      S += m;
      I[L].v = m;
      I[L++].p = 1-p;
    }
    fill(dp, dp+S+1, -1);
    dp[0] = 1;
    for(int j=0; j<L; j++)
      for(int i=S, k=I[j].v; i>=k; i--)
        if(dp[i-k]>=0) dp[i] = max(dp[i], dp[i-k]*I[j].p);
    for(int i=S; i; i--)
      if(dp[i]>=P) {ANS=i; break;}
    printf("%d\n", ANS);
  }
  return 0;
}
