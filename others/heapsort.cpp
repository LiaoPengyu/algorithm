inline int left(int i) {return i<<1;}
inline int right(int i) {return i<<1|1;}
inline void swap(int *a, int x, int y) {
  int tmp = a[x];
  a[x] = a[y];
  a[y] = tmp;
}
void heapify(int *a, int i, int len) {
  int max = i, l, r;
  for(int hl=len>>1; i<=hl;) {
    if(a[i]<a[l=left(i)]) max = l;
    if((r=right(i))<=len && a[max]<a[r=right(i)]) max = r;
    if(max != i) {
      swap(a, i, max);
      i = max;
    } else break;
  }
}
void heapify_rec(int *a, int i, int len) {
  int l = left(i);
  int r = right(i);
  int max = i;
  if(l<=len && a[l]>a[i]) max = l;
  if(r<=len && a[r]>a[max]) max = r;
  if(max != i) {
    swap(a, i, max);
    heapify_rec(a, max, len);
  }
}
void heapsort(int *a, int len) {
  // start at index 1
  for(int i=len>>1; i>0; i--)
    heapify_rec(a, i, len);
  for(; len>1; ) {
    swap(a, 1, len);
    heapify_rec(a, 1, --len);
  }
}

#include <cstdio>
using namespace std;

int main() {
  int a[] = {-1, 9, 8, 7, 6, 3, 1, 5, 2, 4};
  heapsort(a, 9);
  for(int i=1; i<=9; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
