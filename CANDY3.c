#include<stdio.h>
int main(void)
{
	long long int test;
	scanf("%lld",&test);
	
	while(test--) {
		printf("\n");
		unsigned long long int n;
		scanf("%lld", &n);
		unsigned long long int num,sum = 0, i,num2;
		if(n == 1) {
			scanf("%lld", &num);
			printf("YES\n");
		} else if (n == 2) {
			scanf("%lld", &num);
			num %= n;
			sum = num;
			scanf("%lld", &num2);
			num2 %= n;
			sum += num2;
			
			if(sum % n == 0) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
		else {sum = 0;
			scanf("%lld", &num);
                        num %= n;
                        sum = num;
                        scanf("%lld", &num2);
                        num2 %= n;
                        sum += num2;
			sum %= n;
			for(i = 3; i <= n; i++) {	
				scanf("%lld", &num);
				sum = sum + num % n;
				sum %= n;
			} 
			if(sum == 0) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
} 
