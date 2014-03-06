#include <cstring>
bool isSubstring(char*, char*);
bool isRotation(char*str1, char*str2) {
  int l1 = strlen(str1), l2 = strlen(str2);
  if(l1!=l2) return false;
  char* tmp = new char[l1*2+1];
  strcpy(tmp, str1);
  strcpy(tmp+l1, str1);
  return isSubstring(tmp, str1);
}
