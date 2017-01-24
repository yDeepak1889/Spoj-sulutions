#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
string s;
ll ans[5010];
int flag[5010];
ll len;
ll cal(ll n) {
//	cout<<n<<endl;
	if(n>=len){
		return 1;
	}
	if (flag[n]) {
		return ans[n];
	}
	if (s[n] == '0'){
		flag[n] = 1;
		ans[n] = 0;
		return 0;
	}
	ll temp1 = 0, temp2 = 0;
	temp1 = cal(n+1);
	if(s[n] != '0' && n != len-1 && (s[n] == '1' || s[n] == '2')&&(s[n] >= '0' && s[n]<='6')) {
		temp2 = cal(n+2);
	}
	flag[n] = 1;
	ans[n] = temp1 + temp2;
	return temp1+temp2;
}
int main (void) {
	while(1) {
		memset(ans, 0, sizeof(ans));
		memset(flag, 0, sizeof(flag));
		s.clear();
		cin>>s;
		if (s == "0") {
			break;
		}
		len = s.size();
		cout<<cal(0)<<endl;
	}

	return 0;
}
