#include <cstdio>
using namespace std;
int binary_search(int array[], int len, int value) {
  int l=0, r=len-1, m;
  while(l<=r) {
    // m = (l+r) >> 1;
    m = ((r-l)>>1) + l;
    if(array[m] > value) r = m-1;
    else if(array[m] < value) l = m+1;
    else return m;
  }
  return -1;
}
