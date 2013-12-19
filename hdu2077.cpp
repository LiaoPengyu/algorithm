#include <cstdio>
#include <cmath>
using namespace std;
int main() {
  int t, n;
  for(scanf("%d", &t); t; t--) {
    scanf("%d", &n);
    printf("%ld\n", (long)powl(3, (long)n-1) +1);
  }
}
