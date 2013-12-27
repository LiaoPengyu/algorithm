#include <cstdio>
#include <cstring>
using namespace std;
int const N = 100010;
struct node {
  bool w;
  int n[10];
} tree[N];
char word[11];
int L;
bool ans;
bool insert(char*w) {
  int id=0;
  for(int p=0; w[p]; p++) {
    int&ne = tree[id].n[w[p]-'0'];
    if(!ne) ne = ++L;
    else {
      if(!w[p+1]) return true;
      if(tree[ne].w) return true;
    }
    id = ne;
  }
  tree[id].w = true;
  return false;
}
int main() {
  int t, n;
  scanf("%d", &t);
  for(int c=0; c<t; c++) {
    scanf("%d", &n);
    memset(tree, 0, sizeof(tree));
    L = 0;
    ans = false;
    for(int i=0; i<n; i++) {
      scanf("%s", word);
      if(word[0] && !ans) ans = insert(word);
    }
    if(ans) puts("NO");
    else puts("YES");
  }
  return 0;
}
