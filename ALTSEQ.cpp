#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll

int main (void) {
	int n;
	cin>>n;
	int i, arr[n];
	for (i = 0; i < n; i++) {
		cin>>arr[i];
	}
	int ans[n];
	int sol[n];
	for (i = 0; i < n; i++) {
		ans[i] = 1;
		sol[i] = i;
		for (int j = i-1; j >= 0; j--) {
			if (arr[i] > 0 && arr[j] < 0 && abs(arr[i]) > abs(arr[j])) {
				ans[i] = max(ans[i], 1+ans[j]);
			//	sol[i] = j;
			}else if (arr[i] < 0 && arr[j] > 0 && abs(arr[i]) > abs(arr[j]))  {
				ans[i] = max(ans[i], 1+ans[j]);
				//sol[i] =j;
				//break;
			}
		}
	}
	int mm = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		if (mm < ans[i]) {
			mm = ans[i];
			j = i;
		}
	}
	cout<<mm<<endl;
	return 0;
}
