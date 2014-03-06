#include <cstring>
void setZeros(int**matrix, int low, int column) {
  int i, j;
  bool*al = new bool[low];
  bool*ac = new bool[column];
  memset(al, false, sizeof(bool)*low);
  memset(ac, false, sizeof(bool)*column);
  for(i=0; i<low; i++)
    for(j=0; j<column; j++)
      if(!matrix[i][j])
        al[i] = ac[j] = true;
  for(i=0; i<low; i++)
    for(j=0; j<column; j++)
      if(al[i] || ac[j]) matrix[i][j] = 0;
  delete[] al;
  delete[] ac;
}
