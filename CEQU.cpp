#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll

ll gcd (ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd (b, a%b);
}

int main (void) {
	int test;
	cin>>test;
	int j;
	for (j = 1; j <= test; j++) {
		ll a, b, c;
		cin>>a>>b>>c;
		if (c % gcd(a, b) == 0) {
			printf ("Case %d: Yes\n", j);
		}else {
			printf("Case %d: No\n",j);
		}
	}

	return 0;
}
