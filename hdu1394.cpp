#include <cstdio>
#include <iostream>

using namespace std;
const int N = 5000;
int seq[N];

void solve(int n) {
  int p = 0;
  int m;
  for(int i=1; i<n; i++) {
    for(int j=0; j<i; j++) {
      if(seq[j]>seq[i])
        p++;
    }
  }
  m = p;
  for(int i=0; i<n; i++) {
    p += n-1 - seq[i] - seq[i];
    m = min(m, p);
  }
  printf("%d\n", m);
}

int main() {
  int n;
  while(~scanf("%d", &n)) {
    for(int i=0; i<n; i++)
      scanf("%d", &seq[i]);
    solve(n);
  }
  return 0;
}
