#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int const N = 1e5 + 10;
string words;
int head[26], wc, STR, in[26], out[26], p[N];

int find(int n) {
  int nn = n;
  while(p[nn]>=0) nn = p[nn];
  while(p[n]>0) {
    p[n] = nn;
    n = p[n];
  }
  return nn;
}
void union_s(int a, int b) {
  int ra = find(a);
  int rb = find(b);
  if(ra == rb) return;
  if(p[ra] > p[rb]) {
    p[rb] += p[ra];
    p[ra] = rb;
  } else {
    p[ra] += p[rb];
    p[rb] = ra;
  }
}
bool check() {
  int flag=0;
  for(int i=0; i<26; i++) {
    if(in[i] == out[i]) continue;
    if(out[i] - in[i] == 1) flag++;
    else if(out[i] - in[i] == -1) flag++;
    else return false;
    if(flag>2) return false;
  }
  int s=-1;
  for(int i=0; i<26; i++)
    if(head[i]) {
      if(s == -1) s = find(i);
      else if(find(i) != s)
        return false;
    }
  return true;
}
int main() {
  int N;
  for(scanf("%d", &N); N--;) {
    scanf("%d", &wc);
    STR = 0;
    memset(head, 0, sizeof(head));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(p, -1, sizeof(p));
    for(int i=0; i<wc; i++) {
      cin >> words;
      int f = words[0] - 'a';
      int t = words[words.length()-1] - 'a';
      head[f] = 1; head[t] = 1;
      in[t] ++; out[f] ++;
      union_s(f, t);
    }
    if(!check())
      printf("The door cannot be opened.\n");
    else
      printf("Ordering is possible.\n");
  }
  return 0;
}
