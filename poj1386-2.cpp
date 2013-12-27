#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct node
{
  int to,next;
}edges[100010];
int box[26];

string name;
int n,in[26],out[26],size,start;
bool flag[26];

void add(int from,int to,int str)
{
  edges[size].to=to;
  edges[size].next=box[from];
  box[from]=size++;
}

void dfs_connect(int x)
{
  for(int i=box[x];i!=-1;i=edges[i].next)
    {
      int ne=edges[i].to;
      if(flag[ne])continue;
      flag[ne]=true;
      dfs_connect(ne);
    }
}

bool check()
{
  int num=0;
  for(int i=0;i<26;++i)
    {
      if(in[i]==out[i])continue;
      if(out[i]-in[i]==1)
        {
          start=i;num++;
          if(num>2)return false;
        }
      else if(in[i]-out[i]==1)
        {
          num++;
          if(num>2)return false;
        }
      else return false;
    }
  memset(flag,false,sizeof(flag));
  flag[start]=true;
  dfs_connect(start);
  for(int i=0;i<26;++i)
    if(in[i]||out[i])
      if(!flag[i])return false;
  return true;
}

int main()
{
  //    freopen("in.txt","r",stdin);
  int t;
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d",&n);
      memset(in,0,sizeof(in));
      memset(out,0,sizeof(out));
      memset(box,-1,sizeof(box));
      size=0;
      start=26;
      for(int i=0;i<n;++i)
        {
          cin>>name;
          int len=name.length();
          out[name[0]-'a']++;in[name[len-1]-'a']++;
          add(name[0]-'a',name[len-1]-'a',i);
          start=name[0]-'a';
        }
      if(!check())
        cout<<"The door cannot be opened."<<endl;
      else
        cout<<"Ordering is possible."<<endl;
    }
  return 0;
}
