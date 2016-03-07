#include<stdio.h>
int main(void)
{
	long long int num;
		
	scanf("%lld", &num);
		
	while(num != 1) {
		if(num % 2 == 1) {
			printf("NIE\n");
			break;
		} else {
			num = num / 2;
		}
	}
	if(num == 1) {
		printf("TAK\n");
	}
}
