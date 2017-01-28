#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
int prime[100000];
int main (void) {
	prime[0] = 1;
	prime[1] = 1;
	int arr[1000];
	int i;
	int c = 1;
	int j;
	arr[c] = 2;
	c++;
	for (i = 3; i*i<=9999; i++) {
		if(!prime[i]) {
			for (j = 2*i; j <= 9999; j+=i) {
				prime[j] = 1;
			}
		}
	}
	for (i = 2; i <= 10000; i++) {
		if (!prime[i] && i % 4 == 1) {
			arr[c] = i;
			c++;
		}
	}
	int test;
	cin>>test;

	while (test--) {
		int n, k;
		cin>>n>>k;
		int num = arr[n];
	//	cout<<num<<endl;
		int dp[k][num+1];
		memset(dp, 0, sizeof(dp));
		int temp[k];
		for (i = 0; i < k; i++) {
				temp[i] = i+1;
				dp[i][0] = 1;
		}
		for (i = 0; i < k; i++) {
				for (c = 1; c <= num; c++) {
				if(c - temp[i] >= 0){
					if(i != 0){
						dp[i][c] = dp[i][c-temp[i]] + dp[i-1][c];
				}else {
					dp[i][c] = dp[i][c-temp[i]];
				}
			}else if(i != 0){
				dp[i][c] = dp[i-1][c];
			}
		}
		// for (j = 1; j <= num; j++) {
		// 	cout<<dp[i][j]<<" ";
		// }
		// cout<<endl;
	}
	cout<<dp[k-1][num]<<endl;
}
	return 0;
}
