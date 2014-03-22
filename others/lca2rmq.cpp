#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;
int const N = 30;
struct Node {
  int t, n;
} tree[N<<1];
struct Query {
  int f, t;
} query[N<<1];
int array[N];
int H[N], cnt, E[N<<1], F[N];
bool flag[N];
int mat[N<<1][N<<1];
void insert(int h[], int f, int t) {
  tree[cnt].t = t;
  tree[cnt].n = h[f];
  h[f] = cnt++;
}
void num(int rt) {
  int num = 1, ft;
  queue<int> q;
  q.push(rt);
  while(!q.empty()) {
    ft = q.front();
    q.pop();
    array[ft] = num++;
    for(int i=H[ft]; ~i; i=tree[i].n)
      q.push(tree[i].t);
  }
}
void dfs(int rt) {
  F[rt] = cnt;
  E[cnt++] = rt;
  for(int i=H[rt]; ~i; i=tree[i].n) {
    dfs(tree[i].t);
    E[cnt++] = rt;
  }
}
void creat_mat(int *a, int len) {
  int i, j;
  for(i=0; i<len; i++)
    mat[i][i]=a[i];
  for(i=0; i<len; i++)
    for(j=i+1; j<len; j++) {
      if(array[mat[i][j-1]] < array[a[j]]) mat[i][j] = mat[i][j-1];
      else mat[i][j] = a[j];
    }
}
inline void swap(int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}
void ans(Query *Q, int len) {
  int a, b;
  for(int i=0; i<len; i++) {
    printf("%d %d: ", Q[i].f, Q[i].t);
    a = F[Q[i].f];
    b = F[Q[i].t];
    if(a>b) swap(a, b);
    printf("%d\n", mat[a][b]);
  }
}
int main() {
  int n, m, f, t, i;
  scanf("%d %d", &n, &m);
  cnt = 0;
  memset(H, -1, sizeof(H));
  memset(flag, false, sizeof(f));
  for(i=0; i<n; i++) {
    scanf("%d %d", &f, &t);
    insert(H, f, t);
    flag[t] = true;
  }
  for(i=0; i<m; i++) {
    scanf("%d %d", &f, &t);
    query[i].f = f;
    query[i].t = t;
  }
  memset(E, -1, sizeof(E));
  memset(F, -1, sizeof(F));
  for(i=1; i<=n+1 && flag[i]; i++);
  cnt = 0;
  num(i);
  dfs(i);
  creat_mat(E, cnt);
  ans(query, m);
  return 0;
}

// TEST DATA
// 11 6
// 12 5
// 12 11
// 5 1
// 5 3
// 3 2
// 3 4
// 11 10
// 11 7
// 7 9
// 9 6
// 9 8

// 1 8
// 3 10
// 2 4
// 10 6
// 7 8
// 5 1
