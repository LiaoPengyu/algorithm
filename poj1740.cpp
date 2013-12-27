#include <cstring>
#include <cstdio>
using namespace std;
int n, p[111], in;
int main() {
  while(scanf("%d", &n) && n) {
    memset(p, 0, sizeof(p));
    for(int i=0; i<n; i++) {scanf("%d", &in); p[in]++;}
    if(n&1) {puts("1"); continue;}
    else for(int i=0; i<101; i++)
           if(p[i]&1) {p[110] = 1; break;}
    printf("%d\n", p[110]);
  }
  return 0;
}
