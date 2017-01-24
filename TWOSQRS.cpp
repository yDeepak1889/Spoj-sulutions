#include<bits/stdc++.h>
using namespace std;


void check(long long n) 
{
	long long i,j = 0ll;

	i = (long long)sqrt(n);

	while (i>0){
		if (j * j > n) {
			printf("No\n");
			return ;
		}else if (i*i + j* j == n){
			printf("Yes\n");
			return ;
		}else if (i * i + j * j < n){
			j++;
		}else{
			i--;
		}
	}
	return ;
}

int main (void)
{
	int test;
	scanf ("%d", &test);

	while (test--) {
		long long n;
		scanf ("%lld", &n);
		if (n == 0 || n ==1) {
			printf("Yes\n");
			continue;
		}
		check(n);
	}

	return 0;
}