#include<bits/stdc++.h>
using namespace std;
double res[100009];
void pre()
{
 int i;
 res[1]=1;
 for(i=2;i<=100000;i++)
  res[i]=res[i-1] + 1.0/i;
}
main()
{
 int t;
 pre();
 scanf("%d",&t);
 while(t--)
 {
  int n;
  scanf("%d",&n);
  printf("%.15lf\n",res[n]);
 }
}
