inline void swap(int *a, int x, int y) {
  int tmp = a[x];
  a[x] = a[y];
  a[y] = tmp;
}
int partition(int *a, int e) {
  int tmp = a[e];
  int cur, p;
  for(cur=p=0; p<e; p++) {
    if(a[p] < tmp) {
      swap(a, p, cur);
      cur++;
    }
  }
  swap(a, cur, e);
  return cur;
}
void quicksort(int *a, int len) {
  if(len<=1) return;
  int mid = partition(a, len-1);
  quicksort(a, mid);
  quicksort(a+mid+1, len-mid-1);
}

#include <cstdio>
using namespace std;

int main() {
  int a[] = {9, 8, 7, 6, 3, 1, 5, 2, 4};
  quicksort(a, 9);
  for(int i=0; i<9; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
