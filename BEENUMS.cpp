#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	
	while (1) {
		scanf ("%lld", &n);
		
		if (n == -1) {
			return 0;
		}
		
		char ans;
		if ((n-1) % 6 != 0) {
			ans = 'N';
		}else {
			n = (n-1)/3;
			
			long long temp;
			temp = (long long)sqrt(n);
			
			while (1) {
				if (temp*(temp-1) == n) {
					ans = 'Y';
					break;
				}else if (temp*(temp-1)> n){
					ans = 'N';
					break;
				}else {
					temp++;
				}
			}
		}
		
		printf ("%c\n",ans);
		
	}
}
