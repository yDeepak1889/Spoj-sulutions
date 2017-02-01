#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007ll
int n;
int arr[2002];
int dp[2002][2002][2];
int ans[2002];

int cal (int d, int i, int j) {
	if(i > j){
		return 0;
	}
	if(dp[i][j][0]&&dp[i][j][1] == d) {
		return dp[i][j][0];
	}
	int a, b;
	a = arr[i]*d + cal(d+1, i+1, j);
	b = arr[j]*d + cal(d+1, i, j-1);
	dp[i][j][0] = max(a, b);
	dp[i][j][1] = d;
	// if(a > b) {
	// 	ans[d] = arr[i];
	// }else {
	// 	ans[d] = arr[j];
	// }
	return dp[i][j][0];
}

int main (void) {
	cin>>n;
	int i;
	for (i = 0; i < n; i++) {
		cin>>arr[i];
	}
	cout<<cal(1, 0, n-1)<<endl;
	// int sum = 0;
	// for (i = 1; i<=n; i++){
	// 	cout<<ans[i]<<endl;
	// 	sum += ans[i]*i;
	// }
	//cout<<sum<<endl;
	return 0;
}
