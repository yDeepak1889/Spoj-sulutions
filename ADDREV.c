#include<stdio.h>
int main(void)
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		int num1,num2;
			scanf("%d%d",&num1,&num2);
		int sum1=0,sum2=0,sum=0,r1,r2;
			while(num1)
			{
				r1=num1%10;
				sum1=sum1*10+r1;
				num1=num1/10;
				
			}
			while(num2)
			{
				r2=num2%10;
				sum2=sum2*10+r2;
				num2=num2/10;
			}
		//	printf("%d %d",sum1,sum2);
			r1=0;r2=0;
			sum=sum1+sum2;
		//	printf(" %d",sum);
			while(sum)
			{
				r1=sum%10;
				r2=r2*10+r1;
				sum=sum/10;
			}
			printf("%d\n",r2);	
		n--;
	}
	return 0;
} 
