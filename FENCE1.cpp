#include <bits/stdc++.h>

using namespace std;

int main()
{
	while (1) {
		long long length;
		scanf ("%lld", &length);
		
		if (length==0) 
			break;
			
		double ans;
		
		ans = (length * length) / (2 * 3.1415926);
		
		ans *= 100;
		ans = round(ans);
		ans /= 100;
		
		
		printf ("%.2lf\n", ans);
		
		
	}
}
