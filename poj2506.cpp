#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int const N = 251;

struct BigNum {
  static int const N = 100;
  char num[N];
  int len; // without \0
  BigNum();
  BigNum(int n);
  BigNum(char* newnum, int l);
  BigNum operator + (BigNum const& other) const;
  void print() const;
  BigNum& operator =(BigNum const& other);
} lis[N][5];
BigNum::BigNum() {
  num[0] = '\0';
  len = 0;
}
BigNum::BigNum(int n) {
  int i=0;
  if(n) {
    for(i=0; n>0; n/=10)
      num[i++] = (n % 10) + '0';
  } else num[i++] = '0';
  num[i] = '\0';
  len = i;
}
BigNum::BigNum(char* newnum, int l) {
  strncpy(num, newnum, l);
  num[l] = '\0';
  len = l;
}
BigNum BigNum::operator + (BigNum const& other) const {
  char newnum[BigNum::N];
  int l = max(len, other.len), m = min(len, other.len), flag=0, tmp;
  BigNum const& ma = len>other.len? *this: other;
  for(int j=0; j<l; j++) {
    if(j>=m) {
      if(j>=ma.len) tmp = flag;
      else tmp = ma.num[j] - '0' + flag;
    }
    else tmp = num[j] + other.num[j] - '0' - '0' + flag;
    newnum[j] = tmp%10 + '0';
    if(tmp>=10) {
      if(j==l-1) l++;
      flag = 1;
    } else flag = 0;
  }
  newnum[l] = '\0';
  return BigNum(newnum, l);
}
BigNum& BigNum::operator =(BigNum const& other) {
  strncpy(num, other.num, other.len);
  num[other.len] = '\0';
  len = other.len;
  return *this;
}
void BigNum::print() const {
  for(int i=len; i>0; i--) {
    printf("%c", num[i-1]);
  }
  printf("\n");
}
int main() {
  int n;
  lis[0][0] = BigNum(1); lis[1][0] = BigNum(1);
  lis[0][1] = BigNum(0); lis[1][1] = BigNum(1);
  lis[0][2] = BigNum(0); lis[1][2] = BigNum(1);
  lis[0][3] = BigNum(0); lis[1][3] = BigNum(0);
  lis[0][4] = BigNum(0); lis[1][4] = BigNum(0);
  for(int i=2; i<N; i++) {
    lis[i][0] = lis[i-1][0] + lis[i-1][3] + lis[i-1][4];
    lis[i][1] = lis[i-1][0] + lis[i-1][3] + lis[i-1][4];
    lis[i][2] = lis[i-1][0] + lis[i-1][3] + lis[i-1][4];
    lis[i][3] = lis[i-1][2];
    lis[i][4] = lis[i-1][1];
  }
  while(~scanf("%d", &n)) {
    (lis[n][0] + lis[n][3] + lis[n][4]).print();
  }
  return 0;
}
