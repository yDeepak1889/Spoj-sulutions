#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
int help[1000010];
int main (void) {
	int n;
	cin>>n;
	int i, arr[n];
	for (i = 0; i < n; i++) {
		cin>>arr[i];
	}
	int ans[n];
	for (i = 0; i < n; i++) {
		ans[i] = 1+help[arr[i]-1];
		help[arr[i]] = ans[i];
	}
	int m = 0;
	for (i = 0; i < n; i++) {
		m = max(m, ans[i]);
	}
	cout<<m<<endl;
	return 0;
}
