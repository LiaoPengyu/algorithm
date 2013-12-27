#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

int const N = 10000;
int c, n, m;
int tree[N<<3], ord[N<<2];
set<int> s;
vector<int> d;
pair<int, int> p[N];

void init()
{
  memset(tree, -1, sizeof(tree));
  s.clear(); d.clear(); ord[0] = 1;
}
inline void PushDown(int rt) {
  if(tree[rt] != -1) {
    tree[rt<<1] = tree[rt];
    tree[rt<<1|1] = tree[rt];
    tree[rt] = -1;
  }
}
void update(int L, int R, int i, int l=1, int r=n, int rt=1) {
  if(L<=l&&r<=R) {
    tree[rt] = i; return;
  }
  PushDown(rt);
  int m = (l+r) >> 1;
  if(L<=m) update(L, R, i, lson);
  if(R>m) update(L, R, i, rson);
}
int query(int p, int l=1, int r=n, int rt=1) {
  if(l==r)
    return tree[rt];
  PushDown(rt);
  int m = (l+r) >> 1;
  return p<=m? query(p, lson): query(p, rson);
}
int main() {
  scanf("%d", &c);
  while(c--) {
    init();
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
      scanf("%d%d", &p[i].first, &p[i].second);
      d.push_back(p[i].first); d.push_back(p[i].second);
    }
    sort(d.begin(), d.end()); vector<int>::iterator iter = unique(d.begin(), d.end());
    n = iter - d.begin();
    for(int i=1; i<n; i++)
      ord[i] = ord[i-1] + (d[i]-1==d[i-1] ? 1:2);
    n = ord[n-1];
    for(int i=0; i<m; i++) {
      p[i].first = ord[lower_bound(d.begin(), iter, p[i].first) - d.begin()];
      p[i].second = ord[lower_bound(d.begin(), iter, p[i].second) - d.begin()];
      update(p[i].first, p[i].second, i);
    }
    for(int i=0; i<n; i++) {
      s.insert(query(i+1));
    }
    printf("%lu\n", s.size());
  }
  return 0;
}
