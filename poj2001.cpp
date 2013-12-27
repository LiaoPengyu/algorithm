#include <cstdio>
int const W = 21, N = 20010;
int L=0;
struct NODE {
  int p;
  int n[26];
} tree[N];
char words[1000][W];
void insert(char*w, int p, int id) {
  if(!w[p]) return;
  int&n = tree[id].n[w[p]-'a'];
  if(n) tree[n].p++;
  else {
    n = ++L;
    tree[n].p++;
  }
  insert(w, p+1, n);
}
void find(char*w, int p, int id) {
  if(!w[p]) {putchar('\n'); return;}
  putchar(w[p]);
  int n = tree[id].n[w[p]-'a'];
  if(tree[n].p == 1) {putchar('\n'); return;}
  find(w, p+1, n);
}
int main() {
  int i=0;
  while(gets(words[i])) insert(words[i++], 0, 0);
  for(int j=0; j<i; j++) {
    printf("%s ", words[j]);
    find(words[j], 0, 0);
  }
  return 0;
}
