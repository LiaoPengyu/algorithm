bool isUnique(char* str, int len) {
  bool c_set[256] = {};
  for(int i=0; i<len; i++) {
    if(c_set[str[i]]) return false;
    c_set[str[i]] = true;
  }
  return true;
}
