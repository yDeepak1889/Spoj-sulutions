#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin>>test;
	while (test--) {
		int n, k;
		cin>>n>>k;
		int arr[k+1];
		for (int i = 1; i <= k; i++) {
			cin>>arr[i];
		}
		if(n == 1 && arr[k] != -1) {
			cout<<arr[k]<<endl;
			continue;
		}else if (n == 1){
			cout<<-1<<endl;
			continue;
		}
		int dp[k+1][k+1];
		memset(dp, 0, sizeof(dp));
		int i, j, temp1, temp2, temp3;
		for (i = 1; i <= k; i++) {
			for (j = 1; j <= k; j++) {
				if(j < i) {
					dp[i][j] = dp[i-1][j];
					continue;
				}
				if (arr[i] == -1) {
					dp[i][j] = dp[i-1][j];
					continue;
				}
				temp1 = dp[i-1][j];
				temp2 = arr[i];
				temp3 = dp[i][j-i];
				if (temp1 == 0) {
					if (temp3 == 0 && i != j) {
						dp[i][j] = 0;
					}else {
						dp[i][j] = temp2 + temp3;
					}
				}else if(temp3 == 0 && i != j){
					dp[i][j] = temp1;
				}else {
					dp[i][j] = min(temp1, temp2+temp3);
				}
			}
		}
		for (i = 1; i <= k; i++) {
			for (j = 1; j <= k; j++) {
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}

		if (dp[k][k] == 0) {
			cout<<-1<<endl;
		}else {
			cout<<dp[k][k]<<endl;
		}
	}
	return 0;
}
