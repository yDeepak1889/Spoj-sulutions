#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll

ll arr[10010];
ll check[10010];
ll dp[10010];
int n;
ll cal (int l) {
	if (l >= n) {
		return 0;
	}
	if (check[l]) {
		///cout<<"success"<<endl;
		return dp[l];
	}
	ll a;
	a = max(arr[l] + cal(l+2), cal(l+1));
	check[l] = 1;
	dp[l] = a;
	return a;
}

int main (void) {
	int test;
	cin>>test;
	int j;
	for (j = 1; j <= test; j++) {
		cin>>n;
		memset(arr, 0, sizeof (arr));
		memset(dp, 0, sizeof(dp));
		memset(check, 0, sizeof (check));
		int i;
		for (i = 0; i < n; i++) {
			cin>>arr[i];
		}
		cout<<"Case "<<j<<":"<<" "<<cal(0)<<endl;
	}
	return 0;
}
