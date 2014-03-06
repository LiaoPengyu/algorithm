void removeDuplicates(char*str, int len) {
  int tail = 1, i;
  char* start = str;
  while(*(++str)) {
    for(i=0; i<tail; i++)
      if(start[i] == *str) break;
    if(i == tail) start[tail++] = *str;
  }
  start[tail] = 0;
}

void removeDuplicates2(char*str, int len) {
  int tail = 1, i;
  bool c_set[256] = {};
  for(c_set[*str]=true, i=1; i<len; i++) {
    if(!c_set[str[i]]) {
      str[tail++] = str[i];
      c_set[str[i]] = true;
    }
  }
}
