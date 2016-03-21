#include<stdio.h>
 
#include<math.h>
 
#define MAX 1000000000
 
int prime[1000000];
int seg_sieve[1000000];
 
int main(void)
{	
	int i;
	int j;
	
	int k = 0;
	int limit;
	limit = (int)sqrt((double)MAX);
	for (i = 2; i*i <= limit; i++){
		if(!prime[i]) {
			for (j = i*2; j <= limit; j+=i) {
				prime[j] = 1;
			}
		}
	}
	for(i = 2; i <= limit ; i++) {
		if(prime[i] == 0) {
			seg_sieve[k++] = i;
		}
	}
	
	//for( i = 0; i < k; i++)
	//	printf("%d  ", seg_sieve[i]);
	
	int test;
	scanf("%d", &test);
	while(test--) {
	int a;
	int b;
	int lo_limit ;
	scanf("%d %d", &a, &b);
	lo_limit = a;
	int ans[b-a+1] ;
	for(i = 0; i < b-a+1; i++) {
		ans[i] = 1;
	}
	for(i = 0; i < k; i++) {
		lo_limit = ((int)(a/seg_sieve[i]))*seg_sieve[i];
		if(lo_limit < a) {
		lo_limit += seg_sieve[i];
		}
		//printf("%d ", lo_limit);
		for(j = lo_limit; j < b+1; j += seg_sieve[i]) {
			//printf("%d ", seg_sieve[i]);
			if(seg_sieve[i] != j) {
				//printf("\n%d", seg_sieve[i]);
				ans[j-a] = 0;
			}	
		}
	} 
	
	for(i = a; i < b+1; i++) {
		if(ans[i-a] != 0 && i != 1)
		printf("%d\n", i);
	}
	printf("\n");
	}
	
	return 0;
 
}
