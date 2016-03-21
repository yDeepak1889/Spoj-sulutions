#include<stdio.h>
int main(void)
{
	long int t;
		scanf("%ld",&t);
	while(t)
	{
		long num;
		int sum=0;
		scanf("%ld",&num);
		while(num)
		{
			sum=sum+num/5;
			num=num/5;
		}
		printf("%d\n",sum);
		t--;
	}
	return 0;
} 
