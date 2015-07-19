#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
int const N = 5005 << 1;
int M = 30;
int sa[N<<1], tsa[N], ra[N<<1], tra[N], sum[N], height[N];
string s;

#define INF 5010
string s1, s2;
int l1, l2;

void sorting(int j) {
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i<=s.length(); i++) sum[ra[i+j]]++;
  for (int i = 1; i<=M; i++) sum[i] += sum[i-1];
  for (int i = s.length(); i>0; i--) tsa[sum[ra[i+j]]--] = i;
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i<=s.length(); i++) sum[ra[i]]++;
  for (int i = 1; i<=M; i++) sum[i] += sum[i-1];
  for (int i = s.length(); i>0; i--) sa[sum[ra[tsa[i]]]--] = tsa[i];
}
void get_sa() {
  for (int i = 1; i<=s.length(); i++) sum[tra[i] = s[i-1]-'a'+1]++;
  for (int i = 1; i<=M; i++) sum[i] += sum[i-1];
  for (int i = s.length(); i>0; i--) sa[sum[tra[i]]--] = i;
  for (int i = 1; i<=s.length(); i++) ra[i] = tra[i];
  for (int j = 1, p; j <= s.length() * 2; j <<= 1) {
    sorting(j);
    tra[sa[1]] = p = 1;
    for (int i = 2; i<=s.length(); i++)
      tra[sa[i]] = (ra[sa[i]] != ra[sa[i-1]] || ra[sa[i]+j] != ra[sa[i-1]+j])? ++p: p;
    for (int i = 1; i<=s.length(); i++) ra[i] = tra[i];
    M = p + 1;
  }
}
void get_height() {
  for (int i = 1, j = 0; i<=s.length(); i++) {
    if (ra[i] == 1) continue;
    while (s[i+j-1] == s[sa[ra[i]-1]+j-1]) j++;
    height[ra[i]] = j;
    if (j) j--;
  }
}

int main() {
  cin >> s1 >> s2;
  l1 = s1.length(); l2 = s2.length();
  s = s1 + char(26 + 'a') + s2;
  get_sa();
  get_height();
  int ans = INF;
  for(int i=2; i<=s.length(); i++)
    if(((sa[i]<=l1) ^ (sa[i-1]<=l1))
       && height[i]>height[i-1] && height[i]>height[i+1])
      ans=min(ans, min(height[i],max(height[i-1],height[i+1])+1));
  printf("%d\n",ans==INF? -1: ans);
  return 0;
}
