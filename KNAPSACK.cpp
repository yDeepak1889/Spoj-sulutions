#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007ll

int main (void) {

	int s, n;
	cin>>s>>n;
	int i, arr[n][2];
	for (i = 0; i < n; i++) {
		cin>>arr[i][0]>>arr[i][1];
	}
	int dp[n+1][s+1];
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= n; i++) {
		for (int j = 1; j <= s; j++) {
			if(j < arr[i-1][0]) {
				dp[i][j] = dp[i-1][j];
			}else {
				dp[i][j] = max(dp[i-1][j], arr[i-1][1]+dp[i-1][j-arr[i-1][0]]);
			}
		}
	}
	cout<<dp[n][s]<<endl;
	return 0;
}
