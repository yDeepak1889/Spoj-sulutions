#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007ll
int dp[1000][1000];
int arr[1000];
int n, k;
int main (void) {
	int  test;
	cin>>test;
	int temp;
	int num;
	int sum = 0;
	int i, j, k;
	while (test--) {
		cin>>n>>k;
		for (i = 1; i <= n; i++) {
			cin>>temp;
			sum = 0;
			for (j = 0; j < temp; j++) {
				cin>>num;
				sum+=num;
			}
			arr[i] = sum;
		}
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= k; j++) {
				if(j-arr[i] >= 0) {
					dp[i][j] = max(dp[i-1][j], arr[i]+dp[i-1][j-arr[i]]);
				}else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		cout<<dp[n][k]<<endl;
	}

	return 0;
}
