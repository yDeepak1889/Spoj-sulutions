#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
ll dp[15];
ll power(ll i) {
	ll a = 1;
	ll sum = 1;
	for (a = 1; a <= i; a++) {
		sum = sum * 10;
	}
	return sum;
}



ll cal(ll n) {
	if(n < 10){
		return (n*(n+1))/2;
	}
	ll l, d = -1;
	ll temp  = n;
	while (temp) {
		l = temp%10;
		d++;
		temp /= 10;
	}
//	cout<<l<<endl;
	temp = power(d);
	return l*dp[d]+((l*(l-1))/2)*temp + l * (n%(l*temp) + 1) + cal(n%temp);
}


int main (void) {
	dp[0] = 0;
	dp[1] = 45;
	int i;
	for (i = 2; i <= 10; i++) {
		dp[i] = dp[i-1]*10 + 45 * (power(i-1));
	}
	while(1){
		ll a, b;
		cin>>a>>b;
		if(a == -1) {
			break;
		}

		if(a <= 1) {
			cout<<cal(b)<<endl;
		}else{
			cout<<cal(b)-cal(a-1)<<endl;
		}
	}
	return 0;
}
