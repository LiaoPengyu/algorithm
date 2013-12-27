#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const N = 1001;
struct NODE {int x, y;} node[N];
int head[40001], next[N], s[N];
bool find(int x, int y) {
  int hash = abs(x+y);
  int index = head[hash];
  while(index != -1)
    if(node[index].x == x && node[index].y == y) return true;
    else index = next[index];
  return false;
}
bool cmp(int a, int b) {
  if(node[a].x==node[b].x) return node[a].y<node[b].y;
  return node[a].x<node[b].x;
}
int main() {
  int n;
  while(scanf("%d", &n) && n) {
    memset(head, -1, sizeof(head));
    memset(next, -1, sizeof(next));
    for(int i=0; i<n; i++) {
      scanf("%d%d", &node[i].x, &node[i].y);
      int hash = abs(node[i].x + node[i].y);
      next[i] = head[hash];
      head[hash] = i;
      s[i] = i;
    }
    sort(s, s+n, cmp);
    int ans = 0;
    for(int ii=0; ii<n; ii++)
      for(int jj=ii+1; jj<n; jj++) {
        int i = s[ii], j = s[jj];
        int x = node[i].x + node[i].y - node[j].y;
        int y = node[i].y + node[j].x - node[i].x;
        if(!find(x, y)) continue;
        x = node[j].x + node[i].y - node[j].y;
        y = node[j].y + node[j].x - node[i].x;
        if(find(x, y)) ans++;
      }
    printf("%d\n", ans>>1);
  }
  return 0;
}
