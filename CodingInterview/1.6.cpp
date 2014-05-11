void rotate(int** matrix, int n) {
  for(int layer=0; layer<n/2; layer++) {
    int first = layer, last = n-1-layer;
    for(int i=first; i<last; i++) {
      int tmp = matrix[first][i];
      int offset = i-first;
      matrix[first][i] = matrix[last-offset][first];
      matrix[last-offset][first] = matrix[last][last-offset];
      matrix[last][last-offset] = matrix[i][last];
      matrix[i][last] = tmp;
    }
  }
}
