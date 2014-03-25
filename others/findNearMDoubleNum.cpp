#include <cstdio>
using namespace std;
double* findNear(double *a, int len, int m, double x) {
  if(m>len) return NULL;
  if(m==len) return a;
  if(x<a[0]) return a;
  if(x>a[len-1]) return a+len-m;
  int s=0, i;
  for(i=m; i<len; i++) {
    if(x-a[i]>=0) s++;
    else if(a[i]-x < x-a[s]) s++;
    else break;
  }
  return a+s;
}
int main() {
  double a[] = {1.234, 1.356, 3.564, 5.456, 5.555, 6.111, 6.441};
  int m = 4;
  double *s = findNear(a, 7, m, 5);
  for(int i=0; i<m; i++)
    printf("%lf ", s[i]);
  printf("\n");
  return 0;
}
