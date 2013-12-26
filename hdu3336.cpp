#include "cstdio"
#include "cstring"
using namespace std;
int const N = 200010;
int T, l, i, j, p[N], ANS, dp[N];
char s[N];
int main() {
  scanf("%d", &T);
  while(T-- && scanf(" %d ", &l)) {
    scanf("%s", s+1);
    for(memset(p, 0, sizeof(p)), memset(dp, 0, sizeof(dp)), dp[1]=1,
            j=0, ANS=1, i=2; i<=l; i++) {
      while(j>0 && s[j+1]!=s[i]) j=p[j];
      p[i] = s[j+1] == s[i]? ++j: j;
      dp[i] = dp[p[i]] + 1;
      ANS = (ANS + dp[i]) % 10007;
    }
    printf("%d\n", ANS);
  }
  return 0;
}
