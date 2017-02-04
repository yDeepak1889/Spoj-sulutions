#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007ll
int dp[2000][2000];
bool flag[2000][2000];
string a, b;
int l1, l2;
int cal(int i, int j) {
	if(i >= l1 || j >= l2) {
		return 0;
	}
	if(flag[i][j]) {
		return dp[i][j];
	}
	if (a[i] == b[j]){
		dp[i][j] =  cal(i+1, j+1) + 1;
	}else{
		dp[i][j] = max(cal(i, j+1), cal(i+1, j));
	}
	flag[i][j] = true;
	return dp[i][j];
}
int main (void) {
	int test;
	cin>>test;
	while (test--) {
		memset(dp, 0, sizeof(dp));
		memset(flag, false, sizeof(flag));
		a.clear();
		b.clear();
		cin>>a>>b;
		l1 = a.size();
		l2 = b.size();
		int ans = cal(0, 0);
		l1-=ans;
		l2-=ans;
		cout<<max(l1,l2)<<endl;
	}

	return 0;
}
