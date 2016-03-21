#include<stdio.h>
#include<string.h>
int main()
{
	int t=10,s;
	while(t--)
	{
	char a[10000], c[10000];
	
	gets(a);
	gets(c);
	if(c[0]=='0')
	{
		printf("%s\n0\n",a);
		continue;
	}
	if(strcmp(a,c)==0)
	{
		printf("%s\n0\n",c);
		continue;
	}
	
	int len,i,j, size,k=0,l,v,g[10000],h=0;
			len=strlen(a);
			size=strlen(c);
		char b[len];
		for(i=0;i<len ;i++)
		{
			b[i]='0';
			g[i]=0;
		}
		g[len]=0;
		l=len-1;
		v=size-1;
	int m[10000],r[10000] ;
	
	while( v!=-1)
		b[l--]=c[v--];
	
	for(i=len-1 ;i>=0 ; i--)
	{
		m[i+1]=(a[i]-48+b[i]-48 +k)%10  ;
		k=(a[i]+b[i]-96+k) /10 ;
	}
	m[0]=k;   k=0;
	for(i=0; i<=len; i++)
	{
		r[i]=(m[i]+k*10)/2;
		k= (m[i]+k*10)% 2;
	}
	for(i=0;i<=len;i++)
		{
		if(r[i]==0 && h==0)
		continue;
	else
	{
	   printf("%d",r[i]);
	   h++;
	}
	}
	printf("\n");
	h=0;
	
	for(i=len; i>=0; i--)
	{
		l=a[i-1]-r[i]-48;
		if(l>=0)
			g[i]=l;
		else
			{
				g[i]=l+10;
				a[i-2]--;
			}
	}
	for(i=1; i<=len ;i++)
	{
	if(g[i]==0 && h==0)
		continue;
	else
	{
	   printf("%d",g[i]);
	   h++;
	}
	}
	printf("\n");
    }
	return 0;
}
 
