#include <cstdio>
#include <cmath>
using namespace std;
long long ans;
int n;
long long  powll(int m, long long t) {
  if(m==1) return t;
  long long v = powll(m>>1, t);
  if(m&1) return v*v*t;
  else return v*v;
}
int main() {
  while(~scanf("%d", &n)) {
    ans = powll(n, 3);
    printf("%lld\n", ans - 1);
  }
}

// #include<cstdio>
// int main()
// {
//   __int64 a[40];
//   a[1]= 2;
//   for(int i= 2; i<= 35; i++)
//     a[i]= 3* a[i-1]+ 2;
//   int n;
//   while(scanf("%d",&n)!=EOF)
//   {
//     printf("%I64d\n",a[n]);
//   }
//   return 0;
// }

// #include <cstdio>
// using namespace std;
// __int64 ans;
// int n;
// __int64  powll(int m, __int64 t) {
//   if(m==1) return t;
//   __int64 v = powll(m>>1, t);
//   if(m&1) return v*v*t;
//   else return v*v;
// }
// int main() {
//   while(~scanf("%d", &n)) {
//     ans = powll(n, 3);
//     printf("%I64d\n", ans - 1);
//   }
// }
