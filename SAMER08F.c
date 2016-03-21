#include<stdio.h>
int main(void)
{
	int n,sum=0,i,j,k;
		scanf("%d",&n);
	while(n!=0)
	{
		sum=0;
		for(i=1;i<n+1;i++)
		for(j=1;j<n+2-i;j++)
		for(k=1;k<n+2-i;k++)
			sum++;
		printf("%d\n",sum);
		scanf("%d",&n);
	}
} 
