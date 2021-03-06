#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007ll

int n;
pair<int,int> p[100010];


bool cmp(pint a, pint b) {
	if(a.first == b.first) {
		return a.second > b.second;
	}else{
		return a.first > b.first;
	}
}


int main (void) {

	int test;
	cin>>test;
	while (test--) {
		int i;
		cin>>n;
		for (i = 0; i < n; i++) {
			cin>>p[i].first>>p[i].second;
		}
		sort(p,p+n, cmp);
		int ans = 1;
		int pre = p[0].first;
		for(i = 1; i < n; i++) {
			if (p[i].second<=pre) {
				ans++;
				pre = p[i].first;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
