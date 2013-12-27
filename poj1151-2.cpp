#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;
const double eps=1e-12;
const int N=209;
struct node
{
  double ox,oy;
  int x,y;
};
struct rect
{
  node s,t;
}a[N];
int n,cnta,cntb;
double ar[500],br[500];
double backa[500],backb[500];
int bina(double x)
{
  int s=0,t=cnta-1;
  while(s<=t)
    {
      int mid=(s+t)>>1;
      if(fabs(ar[mid]-x)<eps) return mid+1;
      if(ar[mid]>x) t=mid-1;
      else s=mid+1;
    }
}
int binb(double x)
{
  int s=0,t=cntb-1;
  while(s<=t)
    {
      int mid=(s+t)>>1;
      if(fabs(br[mid]-x)<eps) return mid+1;
      if(br[mid]>x) t=mid-1;
      else s=mid+1;
    }
}
int M[N][N];
void add(int i,int j,int v)
{
  for(;i<N;i+=-i&i)
    {
      int tj=j;
      for(;tj<N;M[i][tj]+=v,tj+=-tj&tj);
    }
}
int sum(int i,int j)
{
  int ans=0;
  for(;i;i-=-i&i)
    {
      int tj=j;
      for(;tj;ans+=M[i][tj],tj-=-tj&tj);
    }
  return ans;
}
void rect_add(int x1,int y1,int x2,int y2)
{
  add(x1,y1,1);
  add(x1,y2+1,-1);
  add(x2+1,y1,-1);
  add(x2+1,y2+1,1);
}
void init()
{
  int numa=0,numb=0;
  memset(M,0,sizeof(M));
  for(int i=0;i<n;i++)
    {
      scanf("%lf%lf%lf%lf",&a[i].s.ox,&a[i].s.oy,&a[i].t.ox,&a[i].t.oy);
      ar[numa++]=a[i].s.ox;
      br[numb++]=a[i].s.oy;
      ar[numa++]=a[i].t.ox;
      br[numb++]=a[i].t.oy;
    }
  cnta=1;
  for(int i=1;i<numa;i++)
    if(fabs(ar[i]-ar[cnta-1])>eps) ar[cnta++]=ar[i];
  sort(ar,ar+cnta);
  for(int i=0;i<cnta;i++)
    backa[i+1]=ar[i];
  cntb=1;
  for(int i=1;i<numb;i++)
    if(fabs(br[i]-br[cntb-1])>eps) br[cntb++]=br[i];
  sort(br,br+cntb);
  for(int i=0;i<cntb;i++)
    backb[i+1]=br[i];

  for(int i=0;i<n;i++)
    {
      a[i].s.x=bina(a[i].s.ox);
      a[i].s.y=binb(a[i].s.oy);
      a[i].t.x=bina(a[i].t.ox);
      a[i].t.y=binb(a[i].t.oy);
      rect_add(a[i].s.x,a[i].s.y,a[i].t.x-1,a[i].t.y-1);
    }
  double ans=0;
  for(int i=1;i<cnta;i++)
    for(int j=1;j<cntb;j++)
      if(sum(i,j))
        {
          double mx=backa[i+1]-backa[i];
          double my=backb[j+1]-backb[j];
          ans+=mx*my;
        }
  printf("%.2f\n\n",ans);
}
int main()
{
  //freopen("in.txt","r",stdin);
  int cnt=1;
  while(scanf("%d",&n),n)
    {
      printf("Test case #%d\nTotal explored area: ",cnt++);
      init();
    }
  return 0;
}
