#include "cstdio"
int t, i, ANS;
char str[1000];
int main() {
  scanf("%d ", &t);
  while(t--) {
    fgets(str, 1000, stdin);
    for(ANS=i=0; str[i]; i++) if(str[i]<0) ANS++;
    printf("%d\n", ANS>>1);
  }
  return 0;
}
