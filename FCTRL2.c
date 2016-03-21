#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int num,tes;
		scanf("%d",&tes);
	while(tes)
	{
		scanf("%d",&num);
	int   *res;
		res=(int*)malloc(sizeof(int));
		res[0]=1;
	int n=2,carry=0,prod,i=1,j,num1;
		while(n<=num)
		{
			for(j=0;j<i;j++)
			{
				prod=res[j]*n+carry;
				res[j]=prod%10;
				carry=prod/10;
			if(carry!=0 && j==i-1)
				{
					num1=carry;
					while(num1)
					{
						++i;
						res=(int*)realloc(res,sizeof(int)*i);
						res[i-1]=num1%10;
						num1=num1/10;
						
					}carry=0;
					break;
				}	
			}
			n++;
		}
		while(i)
			{
					printf("%d",res[i-1]);
						i--;
			}
			printf("\n");
		tes--;
		}
	return 0;
} 
