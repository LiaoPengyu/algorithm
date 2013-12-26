#include "cstdio"
#include "cstring"
using namespace std;
int const N = 100050;
int T, i, j, len, pd, p[N];
char s[N];
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf(" %s ", s+1);
    len = strlen(s+1);
    for(p[1]=0, j=0, i=2; i<=len; i++) {
      while(j>0 && s[j+1]!=s[i]) j=p[j];
      p[i] = s[j+1]==s[i]? ++j: j;
    }
    pd = len - p[len];
    printf("%d\n", p[len]? (pd-p[len]%pd)%pd: pd);
  }
  return 0;
}
