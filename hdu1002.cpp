#include <cstdio>
#include <cstring>
#include <iostream>

const int LEN = 1000;
char num1[LEN], num2[LEN];

using namespace std;
int main() {
  int c;
  cin >> c;
  for(int i=1; i<=c; i++) {
    if(i>1) cout<<endl;
    cout << "Case " << i << ':' << endl;
    memset(num1, 0, LEN*sizeof(char));
    memset(num2, 0, LEN*sizeof(char));
    cin >> num1 >> num2;
    cout << num1 << " + " << num2 << " = ";
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxl = len1>len2? len1: len2;
    for(int j=0, end=(len1+1)>>1; j<end; j++)
      {
        int tmp = num1[j] - '0';
        num1[j] = num1[len1-j-1] - '0';
        num1[len1-j-1] = tmp;
      }
    for(int j=0, end=(len2+1)>>1; j<end; j++)
      {
        int tmp = num2[j] - '0';
        num2[j] = num2[len2-j-1] - '0';
        num2[len2-j-1] = tmp;
      }
    for(int j=0; j<maxl; j++)
      {
        num1[j] += num2[j];
        if(num1[j] >= 10)
          {
            if(j==maxl-1) maxl++;
            num1[j] -= 10;
            num1[j+1] += 1;
          }
        num1[j] += '0';
      }
    reverse(num1, num1+maxl);
    cout << num1 << endl;
  }
}
