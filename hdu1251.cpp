#include <cstdio>
using namespace std;
int const N = 1000001, W = 11;
int L = 0;
char word[W];
struct dt {
  int n[26], cnt;
} D[N];
void insert(char*w, int p, int id) {
  if(!w[p]) return;
  int& n = D[id].n[w[p]-'a'];
  if(n) D[n].cnt ++;
  else {
    n = ++L;
    D[n].cnt ++;
  }
  insert(w, p+1, n);
}
int find(char*w, int p, int id) {
  if(!w[p]) return D[id].cnt;
  int n = D[id].n[w[p]-'a'];
  if(n) return find(w, p+1, n);
  return 0;
}
int main() {
  while(gets(word), word[0])
    insert(word, 0, 0);
  while(gets(word)) printf("%d\n", find(word, 0 ,0));
  return 0;
}
