#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007ll

int main (void) {
	int n;
	while(1) {
		cin>>n;
		if(n == 0) {
			return 0;
		}
		int ctr = 0;
		while(n) {
			n = n>>1;
			ctr++;
		}
		cout<<ctr-1<<endl;
	}

	return 0;
}
