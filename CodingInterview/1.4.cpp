#include <cstring>
bool anagram(char* str1, char* str2) {
  int l1 = strlen(str1);
  int l2 = strlen(str2);
  if(l1 != l2) return false;
  int cset[256] = {}, cunique = 0;
  for(int i=0; i<l1; i++) {
    if(!cset[str1[i]]) cunique++;
    cset[str1[i]]++;
  }
  for(int i=0; i<l2; i++) {
    if(!cset[str2[i]]) return false;
    cset[str2[i]]--;
    if(!cset[str2[i]]) {
      cunique--;
      if(!cunique) return i==l2-1;
    }
  }
  return false;
}
