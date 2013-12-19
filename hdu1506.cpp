#include "cstdio"
#include "cstring"
#include "algorithm"
#define LL long long
// __int64
#define LLd "lld"
// I64d
using namespace std;
LL const N = 100100;
LL h[N], ANS, n, i, j, le[N], ri[N];
int main() {
  while(scanf("%"LLd, &n), n) {
    for(i=1, h[n+1]=0; i<=n; i++) scanf("%"LLd, &h[i]), le[i]=ri[i]=i;
    for(i=2; i<=n; i++) if(h[i]) while(h[le[i]-1] >= h[i]) le[i] = le[le[i]-1];
    for(i=n-1; i>=1; i--) if(h[i]) while(h[ri[i]+1] >= h[i]) ri[i] = ri[ri[i]+1];
    for(i=1, ANS=0; i<=n; i++) ANS = max(ANS, h[i] * (ri[i]-le[i]+1));
    printf("%"LLd"\n", ANS);
  }
  return 0;
}
