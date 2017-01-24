#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
int arr[110][110];
int ans[110][110];
int flag[110][110];
int n, m;

int cal (int l, int r) {
//	cout<<l<<" "<<r<<endl;
	if (l >= n || r >= m || r < 0) {
		return 0;
	}
	if (flag[l][r]) {
		return ans[l][r];
	}
	if (l == n-1) {
		flag[l][r] = 1;
		ans[l][r] = arr[l][r];
		return arr[l][r];
	}

	int a = 0, b = 0, c = 0;
	if (r != 0) {
		a = cal(l+1, r-1)+arr[l][r];
	}if (r != m-1) {
		b = cal(l+1, r+1)+arr[l][r];
	}
	c = cal(l+1, r)+arr[l][r];
	ans[l][r] = max(a,max(b, c));
	flag[l][r] = 1;
	return ans[l][r];
}

int main (void) {
	int test;
	cin>>test;
	int w;
	while (test--) {
		memset(flag, 0, sizeof (flag));

		cin>>n>>m;
		int i, j;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				cin>>w;
				arr[i][j] = w;
				//cout<<arr[i][j]<<" ";
			}
		//	cout<<endl;
		}
		int mm = 0;
		for (i = 0; i < m; i++) {
			j = cal(0, i);
		//	cout<<j<<endl;
			mm = max(mm, j);
		}
		cout<<mm<<endl;
	}


	return 0;
}
