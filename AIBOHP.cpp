#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
int flag[6110][6110];
ll ans[6110][6110];
string s;
ll cal(int l, int r) {
	if (l >= r) {
		return 0;
	}
	if(flag[l][r]) {
		return ans[l][r];
	}
	if (s[l] == s[r]) {
		ans[l][r] = cal(l+1, r-1);
		flag[l][r] = 1;
		return ans[l][r];
	}else {
		ans[l][r] = min(cal(l+1, r)+1, cal(l, r-1)+1);
		flag[l][r] = 1;
		return ans[l][r];
	}
}
int main (void) {
	int test;
	cin>>test;
	while (test--) {
		memset(flag, 0, sizeof(flag));
		s.clear();
		cin>>s;
		int len = s.size();
		cout<<cal(0,len-1)<<endl;
	}

	return 0;
}
