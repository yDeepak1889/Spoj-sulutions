#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll

string s;
int cnt[26];
ll dp[1000002];
ll cal() {
	dp[0] = 1;
	int i = 1;
	ll sum = 1;
	cnt[s[0]-'A'] = 1;
	while (s[i] != '\0') {
		dp[i] = (sum%MOD+1)%MOD;
		if (cnt[s[i]-'A'] != 0) {
		//	cout<<s[i]<<" "<<cnt[s[i]-'A']-1<<endl;
			sum = (sum %MOD + (dp[i]%MOD - dp[cnt[s[i]-'A']-1])%MOD)%MOD;
			if(sum < 0) {
				sum = sum + MOD;
				sum = sum %MOD;
			}
	//	if(sum < )
		//	cout<<i<<"------->"<<dp[i] - dp[cnt[s[i]-'A']-1]<<endl;
		}else{
			sum = (sum%MOD + (dp[i]%MOD))%MOD;
		}
		//dp[i] = sum;
		cnt[s[i]-'A'] = i+1;
		//cout<<i<<" "<<dp[i]<<" "<<sum<<endl;
		i++;
	}
	return sum;
}

int main (void) {
	int test;
	cin>>test;
	while (test--) {
		s.clear();
		memset(cnt, 0, sizeof(cnt));
		cin>>s;
		cout<<(cal()+1)%MOD<<endl;
	}

	return 0;
}
