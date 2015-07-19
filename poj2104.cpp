#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int const N = 100010, M = 5010;
vector<int> tree[N << 2];
int n, m, i, j, k, A[N], B[N];
void build(int l = 1, int r = n, int root = 1) {
  if (l == r) tree[root].push_back(A[l]);
  else {
    int m = (l + r) >> 1;
    build(l, m, root << 1);
    build(m + 1, r, root << 1 | 1);
    tree[root].resize(r - l + 1);
    merge(tree[root << 1].begin(), tree[root << 1].end()
          , tree[root << 1 | 1].begin(), tree[root << 1 | 1].end(),
          tree[root].begin());
  }
}
int query(int x, int l = 1, int r = n, int root = 1) {
  if (j<l || i>r) return 0;
  if (i <= l && j >= r) return upper_bound(tree[root].begin(), tree[root].end(), x) - tree[root].begin();
  int m = (l + r) >> 1;
  int lr = query(x, l, m, root << 1);
  int rr = query(x, m + 1, r, root << 1 | 1);
  return lr + rr;
}
int main() {
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int c = 1; c <= n; c++) {
    scanf("%d", &A[c]);
    B[c] = A[c];
  }
  sort(B + 1, B + 1 + n);
  build();
  for (int q = 1; q <= m; q++) {
    scanf("%d%d%d", &i, &j, &k);
    int f = 1, len = n, mid, half;
    while (len > 0) {
      half = len >> 1;
      mid = f + half;
      if (query(B[mid]) >= k) len = half;
      else {
        f = mid + 1;
        len -= half + 1;
      }
    }
    printf("%d\n", B[f]);
  }
  return 0;
}
