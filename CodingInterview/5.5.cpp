int bitSwapRequired(int a, int b) {
  int ret=0;
  for(int c=a^b; c!=0; c>>=1)
    ret += c&1;
  return ret;
}
