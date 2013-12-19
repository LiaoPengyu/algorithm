#include <cstdio>
#include <cstring>
using namespace std;
int const N = 501;
bool map[N][N], v[N];
int mat[N];
int n;
int find(int f) {
  for(int i=0; i<n; i++) {
    if(!map[f][i]) continue;
    if(v[i]) continue;
    v[i] = true;
    if(mat[i]==-1 || find(mat[i])) {
      mat[i] = f;
      return 1;
    }
  }
  return 0;
}
int max_match() {
  int ans = 0;
  memset(mat, -1, sizeof(mat));
  for(int i=0; i<n; i++) {
    memset(v, false, sizeof(v));
    ans += find(i);
  }
  return ans>>1;
}
int main() {
  while(~scanf("%d", &n)) {
    memset(map, false, sizeof(map));
    for(int i=0; i<n; i++) {
      int f, c, t;
      scanf("%d: (%d)", &f, &c);
      while(c--) {
        scanf("%d", &t);
        map[f][t] = true;
      }
    }
    printf("%d\n", n-max_match());
  }
  return 0;
}
