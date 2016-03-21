#include<stdio.h>
 
#define MAX 10000000
 
unsigned long long int prime[10000010];
unsigned long long int fibo[100000010];
int main(void)
{	
	int i;
	int j;
 
	fibo[0] = 0;
	fibo[1] = 0;
 
	for (i = 2; i <= MAX; i++) {
		if(!prime[i]) {
			for (j = i; j <= MAX; j+=i) {		
				if(!prime[j]) {
					prime[j] = i;
				}
			}
		}
	}
	
	for (i = 2; i <= MAX; i++) {
		fibo[i] = fibo[i-1] + prime[i];
	}
	
	int test;
	
	scanf("%d", &test);
	
	while(test--) {
		int num;
		scanf("%d", &num);
		
		printf("%lld\n", fibo[num]);
	}
 
	return 0;
} 
