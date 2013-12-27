Source Code

Problem: 2337		User: ariselpy
Memory: 292K		Time: 32MS
Language: C++		Result: Accepted
Source Code
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int const N = 1e3 + 10;
int STR;
string words[N];
int in[26], out[26], head[26], path[N], top;
struct Edge {
  int to;
  int str;
  int next;
  bool used;
  Edge(){}
  Edge(int t, int s, int n): to(t), str(s), next(n), used(false) {}
} edges[N];

void add(int f, int t, int s) {
  edges[STR]  = Edge(t, s, head[f]);
  head[f] = STR++;
}
void fluery(int s) {
  for(int i = head[s]; i!=-1; i=edges[i].next) {
    Edge& str = edges[i];
    if(str.used) continue;
    str.used = true;
    fluery(str.to);
    path[top++] = str.str;
  }
}
bool unless(string const&a, string const&b) {
  return !(a<b);
}
int main() {
  int c; scanf("%d", &c);
  while(c--) {
    int wc;
    scanf("%d", &wc);
    for(int i=0; i<wc; i++) cin >> words[i];
    sort(words, words+wc, unless);
    STR = 0;
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(head, -1, sizeof(head));
    for(int i=0; i<wc; i++) {
      int f = words[i][0] - 'a';
      int t = words[i][words[i].size()-1] - 'a';
      add(f, t, i);
      in[t]++; out[f] ++;
    }
    int flag=0, start=-1;
    for(int i=0; i<26; i++) {
      if(in[i] == out[i]) continue;
      if(out[i] - in[i] == 1 && start == -1) {start = i; flag++;}
      else if(in[i] - out[i] == 1) flag++;
      else flag += 3;
    }
    if(flag != 0 && flag != 2) {
      puts("***"); continue;
    }
    top = 0;
    fluery(start==-1? words[wc-1][0]-'a': start);
    if(top < wc) {
      puts("***");
    }
    else {
      for(int i = top-1; i>=0; i--) {
        cout << words[path[i]];
        if(i!=0) cout<<'.';
        else cout<<endl;
      }
    }
  }
  return 0;
}
