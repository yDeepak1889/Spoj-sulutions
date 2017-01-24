#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll

int main (void) {
	int test;
	cin>>test;
	while (test--) {
		ll n, k, t, f;
		cin>>n>>k>>t>>f;
		ll i = 0;
		ll temp = 1;
		ll p = f/k;
		ll p1 = f % k;
		p = p * k;
		ll temp1 = 1;
		while (temp <= p) {
			temp = n * temp1;
			temp1 *= k;
		//	cout<<temp<<endl;
		}
		temp1 /= k*k;
	//	cout<<temp1<<endl;
		ll ans;
	//	ans =  n + (n*temp1)
		ans = 0;
		temp = 1;
		while (temp <= temp1) {
			ans += temp*n;
			temp = temp * k;
		}
	//	cout<<ans<<endl;
		temp = temp1*n;
		temp = f - temp;
		if(p1 != 0){
			temp = temp1-p1;
			ans += temp*k;
		}
		//cout<<n<<" "<<(n*temp1)<<" "<<endl;
		//cout<<temp1<<" "<<temp<<endl;
		cout<<ans<<endl;
	}

	return 0;
}
