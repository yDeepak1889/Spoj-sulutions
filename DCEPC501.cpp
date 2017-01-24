#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
ll n;
ll arr[1000010];
ll dp[1000010];
bool flag[1000010];

ll cal(ll c) {
	if(c >= n) {
		dp[c] = 0;
		flag[c] = true;
		return 0;
	}
	if (flag[c]) {
		return dp[c];
	}
	ll temp1 = 0;
	ll temp2 = 0;
	ll temp3 = 0;
	ll ans1 = 0, ans2 = 0, ans3 = 0;
	temp1 = arr[c];
	ans1 = temp1 + cal(c+2);
	if(c+1 < n){
		temp2 = temp1 + arr[c+1];
		ans2 = temp2 + cal(c+4);
	}if(c+2 < n){
		temp3 = temp2 + arr[c+2];
		ans3 = temp3 + cal(c+6);
	}
	dp[c] = max(ans1, max (ans2, ans3));
	flag[c] = true;
	return dp[c];
}

int main (void) {
	int test;
	cin>>test;
	while (test--) {
		cin>>n;
		memset(flag, false, sizeof (flag));
		memset(dp, 0ll, sizeof(dp));
		int i;
		for (i = 0; i < n; i++) {
			scanf ("%lld", &arr[i]);
		}
		printf ("%lld\n", cal(0));
	}

	return 0;
}
