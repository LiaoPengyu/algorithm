#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int father[26], rank[26];
int in[26], out[26];
bool has[26];
int t, n;

int find(int x)
{
  if (x != father[x])
    {
      father[x] = find(father[x]);
    }
  return father[x];
}

void Union(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x == y) return ;
  if (rank[x] > rank[y])
    father[y] = x;
  else
    {
      if (rank[x] == rank[y])
        rank[y]++;
      father[x] = y;
    }
}

int main()
{
  scanf("%d", &t);
  while (t--)
    {
      scanf("%d", &n);
      char word[1010];
      for (int i = 0; i < 26; ++i)
        {
          father[i] = i;
          rank[i] = 0;
          has[i] = false;
          in[i] = out[i] = 0;
        }
      for (int i = 0; i < n; ++i)
        {
          scanf("%s", word);
          int a = word[0] - 'a';
          int b = word[strlen(word)-1] - 'a';
          has[a] = has[b] = true;
          out[a]++; in[b]++;
          Union(a, b);
        }
      int cnt = 0;
      for (int i = 0; i < 26; ++i)
        {
          if (has[i] && find(i) == i)
            cnt++;
          if (cnt > 1) break;
        }
      if (cnt > 1)
        {
          printf("The door cannot be opened.\n");
          continue;
        }
      int s1 = 0, s2 = 0;
      bool flag = true;
      for (int i = 0; i < 26; ++i)
        {
          if (has[i] && out[i] != in[i])
            {
              if (out[i] == in[i] + 1)
                s1++;
              else if (in[i] == out[i] + 1)
                s2++;
              else
                {
                  flag = false;
                  break;
                }
            }
        }
      if (flag && s1 <= 1 && s2 <= 1)
        //if (flag && ((s1 == 0 && s2 == 0) || (s1 == 1 && s2 == 1)))
        printf("Ordering is possible.\n");
      else
        printf("The door cannot be opened.\n");
    }
  return 0;
}
