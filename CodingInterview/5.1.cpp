int updateBits(int n, int m, int i, int j) {
  int mask = ~0;
  mask ^= (1<<j) - 1;
  mask |= (1<<i) - 1;
  return (n&mask) | (m<<j);
}
