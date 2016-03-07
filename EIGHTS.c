#include<stdio.h>
int main(void)
{
	
	long long int test;
	scanf("%lld", &test);
		
	while(test--) {
		unsigned long long int k, sum = 0;
			scanf("%lld", &k);
		sum = 192 + (k - 1) * 250;
		printf("%lld\n", sum);
	}
}

