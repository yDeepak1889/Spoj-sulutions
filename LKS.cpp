#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007ll
int dp[2][2000002];
int w, n;
int arr[505][2];
int main (void) {
	cin>>w>>n;
	int i;
	for (i = 0; i < n; i++) {
		cin>>arr[i][0]>>arr[i][1];
	}
	int num = 1;
	int j;
	for (i = 0; i < n; i++) {
		for (j = 1; j <= w; j++) {
			if(j<arr[i][1]){
				dp[num][j] = dp[1-num][j];
			}else{
				dp[num][j] = max(dp[1-num][j], dp[1-num][j-arr[i][1]]+arr[i][0]);
			}
		}
		num = 1-num;
	}
	num = 1-num;
	cout<<dp[num][w]<<endl;
	return 0;
}
