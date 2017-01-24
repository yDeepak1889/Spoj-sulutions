#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
map<ll, ll> mp;
ll cal (ll n) {
	if (n == 0) {
		return 0;
	}
	if(mp.find(n) != mp.end()) {
		return mp[n];
	}
	ll a, b, c;
	a = n/2;
	b = n/3;
	c = n/4;
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if (a + b + c > n) {
		a = cal(a);
		b = cal(b);
		c = cal(c);
		mp[n] = a + b + c;
		return a+b+c;
	}else{
		mp[n] = n;
		return n;
	}
}

int main (void) {
	ll n;
	while (scanf ("%lld", &n) != EOF) {
		mp.clear();
		cout<<cal(n)<<endl;
	}

	return 0;
}
