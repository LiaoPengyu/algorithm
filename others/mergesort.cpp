void merge(int a[], int tmp[], int sp, int ep, int ee) {
  int l, cur, r;
  int ss = sp;
  for(l=cur=sp, r=ep; l<ep && r<=ee;) {
    if(a[l]<a[r]) tmp[cur++] = a[l++];
    else tmp[cur++] = a[r++];
  }
  while(l<ep) tmp[cur++] = a[l++];
  while(r<=ee) tmp[cur++] = a[r++];
  for(;ss<=ee; ss++) a[ss] = tmp[ss];
}
void mergesort_work(int *a, int *tmp, int s, int e) {
  if(s>=e) return;
  int mid = (s+e) >> 1;
  mergesort_work(a, tmp, s, mid);
  mergesort_work(a, tmp, mid+1, e);
  merge(a, tmp, s, mid+1, e);
}
void mergesort(int *a, int len) {
  int *tmp = new int[len];
  mergesort_work(a, tmp, 0, len-1);
}

#include <cstdio>
using namespace std;

int main() {
  int a[] = {9, 8, 7, 6, 3, 1, 5, 2, 4};
  mergesort(a, 9);
  for(int i=0; i<9; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
