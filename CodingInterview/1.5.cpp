void replace(char* str, int len) {
  int c=0, nlen;
  for(int i=0; i<len; i++)
    if(str[i]==' ') c++;
  nlen = len + 2*c;
  str[nlen] = 0;
  for(int i=len-1; i>=0; i--) {
    if(str[i]==' ') {
      str[nlen-1] = '0';
      str[nlen-2] = '2';
      str[nlen-3] = '%';
      nlen -= 3;
    } else {
      str[nlen-1] = str[i];
      nlen -= 1;
    }
  }
}
