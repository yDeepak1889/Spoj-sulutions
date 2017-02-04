#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007ll
int dp[101][505];
int w, n;
typedef struct item{
	int w;
	int c;
}item;
item arr[101];
bool cmp(item a, item b) {
	return a.w < b.w;
}
int main (void) {
	while(1){
		cin>>w>>n;
		if(w == 0 && n == 0) {
			return 0;
		}
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		int i;
		for (i = 0; i < n; i++) {
			cin>>arr[i].w>>arr[i].c;
		}
		sort(arr, arr+n, cmp);
		for (i = 1; i <= n; i++) {
			for (int j = 1; j <= w; j++) {
				if(j < arr[i-1].w) {
					dp[i][j] = dp[i-1][j];
				}else if(dp[i-1][j] < dp[i-1][j-arr[i-1].w]+arr[i-1].c){
					dp[i][j] =  dp[i-1][j-arr[i-1].w]+arr[i-1].c;
				}else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		int j;
		int sum = 0;
		sum = dp[n][w];
		for (i = 1; i <= w; i++) {
			if(dp[n][i] == sum) {
				break;
			}
		}
		cout<<i<<" "<<dp[n][w]<<endl;
	}


	return 0;
}
