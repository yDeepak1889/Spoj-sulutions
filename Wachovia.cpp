#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007ll

int dp[55][1010];
int arr[1010][2];
int w, n;

int cal(int w, int i) {
	if(i >= n || w < 0) {
		return 0;
	}
	if(dp[i][w]) {
		return dp[i][w];
	}
	int a = cal(w, i+1);
	int b = 0;
	if(w >= arr[i][0]) {
		b = cal(w-arr[i][0], i+1) + arr[i][1];
	}
	dp[i][w] = max(a, b);
	return dp[i][w];
}

int main (void) {
	int test;
	cin>>test;
	while (test--){
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		cin>>w>>n;
		int i;
		for (i = 0; i < n; i++) {
			cin>>arr[i][0]>>arr[i][1];
		}

		cout<<"Hey stupid robber, you can get "<<cal(w, 0)<<"."<<endl;
	}
	return 0;
}
