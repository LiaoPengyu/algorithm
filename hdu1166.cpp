#include <cstdio>

using namespace std;

const int maxn = 50000<<2;
int sum[maxn];
#define buildl build
#define buildr build
#define queryl query
#define queryr query
#define updatel update
#define updater update

void refresh(int rt) {
  sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(int l, int r, int rt) {
  if(l == r) {
    scanf("%d", &sum[rt]);
    return;
  }
  int m = (l + r) >> 1;
  buildl(l, m, rt<<1);
  buildr(m+1, r, rt<<1|1);
  refresh(rt);
}

int query(const int l, const int r,
            int L, int R, int rt) {
  if(l <= L && r >= R) return sum[rt];
  int m = (L + R) >> 1, ret = 0;
  if(l <= m) ret += queryl(l, r, L, m, rt<<1);
  if(r > m) ret += queryr(l, r, m+1, R, rt<<1|1);
  return ret;
}

void update(const int pos, const int add,
             int L, int R, int rt) {
  if(L==pos && pos==R) {
    sum[rt] += add;
    return;
  }
  int m = (L+R) >> 1;
  if(pos <= m) updatel(pos, add,
                      L, m, rt<<1);
  else updater(pos, add,
               m+1, R, rt<<1|1);
  refresh(rt);
}

int main() {
  int t, n;
  char c[20];
  scanf("%d", &t);
  for(int i = 1; i<=t; i++)
    {
      printf("Case %d:\n", i);
      scanf("%d", &n);
      build(1, n, 1);
      while(1)
        {
          scanf("%s", c);
          if(*c == 'E') break;
          int a, b;
          scanf("%d%d", &a, &b);
          switch(*c)
            {
            case 'Q': printf("%d\n", query(a, b, 1, n, 1)); break;
            case 'A': update(a, b, 1, n, 1); break;
            case 'S': update(a, -b, 1, n, 1); break;
            }
        }
    }
  return 0;
}
