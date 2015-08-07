#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
int const N = 31;
char input[N][N];
bool toggle[N][N], grid[N][N];
int n, counter;
int const delta[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void push(int x, int y, bool print = false) {
  counter++;
  if (print) printf("%d %d\n", x + 1, y + 1);
  for (int i = 0; i < 5; i++) {
    int tx = x + delta[i][0];
    int ty = y + delta[i][1];
    if (tx >= 0 && ty >= 0 && tx < n && ty < n) grid[tx][ty] ^= true;
  }
}
void solve(bool print = false) {
  for (int i = 1; i < n; i++)
    for (int j = 0; j < n; j++)
      if (grid[i - 1][j])
        push(i, j, print);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", input[i]);
    for (int i = 0; i < n; i++) {
      memset(grid, false, sizeof(grid));
      push(0, i); solve();
      for (int j = 0; j < n; j++)
        toggle[j][i] = grid[n - 1][j];
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        grid[i][j] = input[i][j] == '1';
    solve();
    for (int i = 0; i < n; i++) toggle[i][n] = grid[n - 1][i];
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j < n && toggle[j][i] == 0) j++;
      // assert(j != n);
      if (j == n) continue;
      for (int k = 0; k <= n; k++) swap(toggle[i][k], toggle[j][k]);
      for (int k = j + 1; k < n; k++)
        if (toggle[k][i])
          for (int l = i; l <= n; l++)
            toggle[k][l] ^= toggle[i][l];
      for (int k = 0; k < i; k++)
        if (toggle[k][i])
          for (int l = i; l <= n; l++)
            toggle[k][l] ^= toggle[i][l];
    }

    counter = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        grid[i][j] = input[i][j] == '1';
    for (int i = 0; i < n; i++) {
      // assert(toggle[i][i]);
      if (toggle[i][i] && toggle[i][n]) push(0, i);
    }
    solve();
    printf("%d\n", counter);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) grid[i][j] = input[i][j] == '1';
    for (int i = 0; i < n; i++)
      if (toggle[i][i] && toggle[i][n]) push(0, i, true);
    solve(true);
  }
}
