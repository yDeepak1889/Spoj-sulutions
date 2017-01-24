#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
ll ans[100010][3];

vector<vector<ll> > v(100010);
vector<vector<ll> > :: iterator it;
vector<ll> :: iterator it1;
bool flag = false;
void dfs(ll s) {
	vector<ll> :: iterator it11;
		flag = false;
		it11 = v[s].begin();
		while (it11 != v[s].end()) {
			cout<<s<<" -----> "<<(*it11)<<endl;
			dfs((*it11));
			if (ans[s][0] < ans[(*it11)][0]+1) {
				ans[s][0] = ans[(*it11)][0]+1;
				ans[s][1] = ans[s][0];
			}else if (ans[s][1] < ans[(*it11)][0] + 1) {
				ans[s][1] = ans[(*it11)][0]+1;
			}
			ans[s][2] = max(ans[s][2], max (ans[(*it11)][2] , ans[(*it11)][0]+ans[(*it11)][1]));
			flag = true;
			it11++;
		}
		if(!flag) {
			ans[s][0] = 0;
			ans[s][1] = 0;
			ans[s][2] = 0;
		}
}

int main (void) {
	ll n;
	cin>>n;
	ll i;
	ll x, y;
	for (i = 0; i < n-1; i++) {
		cin>>x>>y;
		v[x].push_back(y);
	}

	// it = v.begin();
	// ll ctr = 0;
	// it++;
	// while (it != v.end()) {
	// 	it1 = (*it).begin();
	// 	while (it1 != (*it).end()) {
	// 		cout<<(*it1)<<" ";
	// 		it1++;
	// 	}
	// 	ctr++;
	// 	if(ctr == n) {
	// 		break;
	// 	}
	// 	cout<<endl;
	// 	it++;
	// }
	ll r;
	cin>>r;
	ll q;
	cin>>q;
	ll s;
	dfs(r);
	for (i = 1; i <= n; i++) {
		cout<<i<<" -----> "<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
	}
	while (q--) {
		cin>>s;
	}
	return 0;
}
