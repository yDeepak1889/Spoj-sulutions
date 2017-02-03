#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007ll
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)

int n, m;
int arr[1000][1000];
int dp[1000][1000];

int main (void) {
	cin>>n>>m;
	int i, j;
	F(i, 0, n-1) {
		F (j, 0, m-1) {
			cin>>arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	F(i, 1, m-1) {
		dp[0][i] = dp[0][i-1]+arr[0][i];
	}

	F (i, 1, n-1){
		dp[i][0] = dp[i-1][0] + arr[i][0];
	}
	F(i, 1, n-1){
		F (j, 1, m-1) {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + arr[i][j];
		}
	}
	cout<<dp[n-1][m-1]<<endl;
	return 0;
}
