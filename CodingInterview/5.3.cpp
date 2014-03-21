inline bool getBit(int n, int i) {
  return n&(1<<i);
}
void setBit(int& n, int i) {
  n ^= 1<<i;
}
int getNext(int n) {
  int i=0, c=0;
  while(!getBit(n, i)) i++;
  while(getBit(n, i)) i++, c++;
  setBit(n, i);
  n = (n & ~((1<<i) - 1)) | ((1<<(c-1))-1);
  return n;
}
int getPre(int n) {
  int i=0, c=0;
  while(getBit(n, i)) i++;
  while(!getBit(n, i)) i++, c++;
  setBit(n, i);
  n = (n | ((1<<i) - 1)) & ~((1<<(c-1))-1);
  return n;
}
