#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test;
	
	scanf ("%d", &test);
	
	while (test--) {
		long long a3,al3,s;
		
		scanf ("%lld %lld %lld",&a3,&al3,&s);
		
		long long n;
		n = s * 2 / (a3+al3);
		long long d;
	//	printf("%lldsuccess\n",al3-a3);
		d = (al3 - a3) / (n-5);
	//	printf ("%lld---->\n",d);
		long long a;
		a  = a3 - 2 * d;
		
		printf ("%lld\n",n);
		long long int i;
		long long num;
		for (i = 0; i < n; i++) {
			num = a + i*d;
			printf("%lld ",num);
		}
		printf("\n");
		
	}
	return 0;
}
