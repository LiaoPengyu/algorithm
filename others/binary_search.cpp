#include <cstdio>
using namespace std;
int binary_search(int array[], int len, int value) {
  int l = 0, r = len - 1, m;
  while (l <= r) {
    // m = (l+r) >> 1;
    m = ((r - l) >> 1) + l;
    if (array[m] > value) r = m - 1;
    else if (array[m] < value) l = m + 1;
    else return m;
  }
  return -1;
}

// lower_bound: minimum x that array[x] >= V

int lower_bound(int array[], int len, int value) {
  int l = 0, r = len - 1, mid;
  while (l <= r) {
    mid = l + (r - l) >> 1;
    if (array[mid] < V) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return l;
}


// upper_bound: minimum x that array[x] > V

int lower_bound(int array[], int len, int value) {
  int l = 0, r = len - 1, mid;
  while (l <= r) {
    mid = l + (r - l) >> 1;
    if (array[mid] <= V) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return l;
}

// find maximum x that array[x] <= V

int lower_bound(int array[], int len, int value) {
  int l = 0, r = len - 1, mid;
  while (l <= r) {
    mid = l + (r - l) >> 1;
    if (array[mid] <= V) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return r;
}

// find maximum x that array[x] < V

int lower_bound(int array[], int len, int value) {
  int l = 0, r = len - 1, mid;
  while (l <= r) {
    mid = l + (r - l) >> 1;
    if (array[mid] < V) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return r;
}
