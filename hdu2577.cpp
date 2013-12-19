#include "cstdio"
int t, C, NC, tc, tnc;
char c;
inline bool upper(char c) {return c>='A' && c<='Z';}
inline int min(int a, int b) {return a<b? a: b;}
int main() {
  scanf("%d ", &t);
  for(; t--; printf("%d\n", min(C+1, NC)))
    for(C=tc=1, NC=tnc=0; (c=getchar()) != '\n'; tc = C, tnc = NC)
      if(upper(c)) C = min(tc+1, tnc+2), NC = min(tnc+2, tc+2);
      else C = min(tc+2, tnc+2), NC = min(tnc+1, tc+2);
  return 0;
}
