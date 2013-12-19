#include <cstdio>
#include <cstring>

using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

int const N =  140000;
int cover[N<<2], XOR[N<<2];
int hash[N+1]; // N+1 is nessery

inline void FXOR(int rt) {
  if(cover[rt] != -1) cover[rt] ^= 1;
  else XOR[rt] ^= 1;
}
inline void PushDown(int rt) {
  if(cover[rt] != -1) {
    cover[rt<<1] = cover[rt<<1|1] = cover[rt];
    XOR[rt<<1] = XOR[rt<<1|1] = 0;
    cover[rt] = -1;
  }
  if(XOR[rt]) {
    FXOR(rt<<1); FXOR(rt<<1|1);
    XOR[rt] = 0;
  }
}
void update(int L, int R, char c, int l=0, int r=N, int rt=1) {
  if(L<=l&&R>=r) {
    if(c == 'U') {
      cover[rt] = 1;
      XOR[rt] = 0;
    } else if(c == 'D') {
      cover[rt] = 0;
      XOR[rt] = 0;
    } else if(c == 'C' || c == 'S') {
      FXOR(rt);
    }
    return;
  }
  PushDown(rt);
  int m = (l+r) >> 1;
  if(L<=m) update(L, R, c, lson);
  else if(c == 'I' || c == 'C')
    cover[rt<<1] = XOR[rt<<1] = 0;
  if(R>m) update(L, R, c, rson);
  else if(c == 'I' || c == 'C')
    cover[rt<<1|1] = XOR[rt<<1|1] = 0;
}
void query(int l=0, int r=N, int rt=1) {
  if(cover[rt]==1) {
    for(int i=l; i<=r; i++) {
      hash[i] = true;
    } return;
  } else if(cover[rt]==0) return;
  PushDown(rt);
  int m = (l+r) >> 1;
  query(lson); query(rson);
}
struct command {
  char c, lq, rq;
  int l, r;
  int operator<(command other){

  };
} cmd[65535];
int main() {
  cover[1] = XOR[1] = 0;
  int l, r;
  char c, lq, rq;
  while(~scanf("%c %c%d,%d%c\n", &c, &lq, &l, &r, &rq)) {
    l<<=1; r<<=1;
    if(lq=='(') l++;
    if(rq==')') r--;
    if(l>r) {
      if(c=='C' || c=='I')
        cover[1] = XOR[1] = 0;
    } else update(l, r, c);
  }
  query();
  bool flag = false; int s=-1, e;
  for(int i=0; i<(N); i++) {
    if(hash[i]) {
      if(s==-1) s=i;
      e=i;
    } else if(s!=-1) {
      if(flag) {
        printf(" ");
      } flag = true;
      printf("%c%d,%d%c", s&1?'(':'[', s>>1, (e+1)>>1, e&1?')':']');
      s=-1;
    }
  }
  if(!flag) printf("empty set");
  printf("\n");
  return 0;
}
