#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int const N = 502, K = 1010;
vector<int> p[N];
int k, m, n, mat[N], female[K], male[K];
struct Partner{
  int m, f;
} P[K];
bool flag[N];
int find(int f) {
  for(int i=0; i<(int)p[f].size(); i++) {
    int to = p[f][i];
    if(flag[to]) continue;
    flag[to] =true;
    if(mat[to]==-1 || find(mat[to])) {
      mat[to] = f;
      return 1;
    }
  }
  return 0;
}
int max_match() {
  int ans=0;
  memset(mat, -1, sizeof(mat));
  for(int i=0; i<m; i++) {
    memset(flag, false, sizeof(flag));
    ans += find(i);
  }
  return ans;
}
int main() {
  while(scanf("%d", &k) && k) {
    scanf("%d%d", &m, &n);
    for(int i=0; i<k; i++) {
      scanf("%d%d", &P[i].f, &P[i].m);
      female[i] = P[i].f;
      male[i] = P[i].m;
    }
    sort(female, female+k);
    int fb = unique(female, female+k) - female;
    sort(male, male+k);
    int mb = unique(male, male+k) - male;
    for(int i=0; i<N; i++) p[i].clear();
    for(int i=0; i<k; i++) {
      int x = lower_bound(female, female+fb, P[i].f) - female;
      int y = lower_bound(male, male+mb, P[i].m) - male;
      p[x].push_back(y);
    }
    printf("%d\n", max_match());
  }
  return 0;
}
