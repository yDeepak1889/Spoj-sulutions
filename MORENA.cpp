	#include <bits/stdc++.h>

	using namespace std;

	#define ll long long
	#define MOD 1000000007ll

	int main (void) {
		ll n;
		cin>>n;
		ll i, arr[n+1], dp[n+1];

		for (i = 1; i <= n; i++) {
			cin>>arr[i];
		}

		for (i = 2; i <= n; i++) {
			if(arr[i] > arr[i-1]) {
				dp[i-1] = 1;
			}else if(arr[i] < arr[i-1] ){
				dp[i-1] = 0;
			}else if(arr[i] == arr[i-1]){
				dp[i-1] = -1;
			}
		}
		ll past, ctr  = 0;
		ctr = 0;
		past = -1;
		for (i = 1; i < n; i++) {
			if((past == 0 && dp[i] == 1)||(past == 1 && dp[i] == 0)||(past == -1 && (dp[i] == 1 || dp[i] == 0))) {
				ctr++;
				//past = dp[i];
				past = dp[i];
			}
		}
		cout<<ctr+1<<endl;
		return 0;
	}
