#include <cstdio>
int main() {
  for(char s[110], m=0; ~scanf(" %s ", s); m=0, putchar('\n')) {
    for(int i=0; s[i]; i++) if(s[i]>m) m = s[i];
    for(int i=0; s[i]; i++) printf("%c%s", s[i], s[i]==m?"(max)":"");
  }
  return 0;
}
