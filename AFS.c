#include<stdio.h>
#define MAX 1000000
 
unsigned long long int lp[MAX + 10];
unsigned long long int sum_div[MAX + 10];
unsigned long long int seq[MAX+10];
 
unsigned long long int power(int prime, int ctr) 
{
	int i;
	unsigned long long int prod;
	
	prod = 1;
	
	for(i = 0; i < ctr; i++)
		prod = prod * prime;
	return prod;
}
 
int main(void)
{
	int i;
	int j;
	
	for (i = 2; i <= MAX; i++) {
		if(!lp[i]) {
			for (j = i; j <= MAX; j+=i) {
				if(!lp[j]) {
					lp[j] = i;
				}
			}
		}
	}
	
	//for(i = 2; i<= MAX ; i++)
		//printf("%d--->%d\n", i, lp[i]);
	
	unsigned long long int temp;
	int ctr;
	unsigned long long int prime;
	unsigned long long int prod;
	
	prod = 1;
	ctr = 0;
	temp = 0;
	
	for(i = 2; i <= MAX; i++) {
		temp = i;
		prime = lp[temp];
		prod  = 1;
		while(temp != 1) {
			temp = temp/ lp[temp];
			ctr ++;
			
			if (prime != lp[temp]){
				prod = prod * (power(prime, ctr+1) -1)/(prime -1);
				prime = lp[temp];
				ctr = 0;
			}
		}
		sum_div[i] = prod - i;
		seq[i] = seq[i-1] + sum_div[i];
	}
	int test;
	scanf("%d", &test);
	
	while(test--) {
		int num;
		scanf("%d", &num);
		printf("%lld\n", seq[num]);
	}	
	return 0;
} 
