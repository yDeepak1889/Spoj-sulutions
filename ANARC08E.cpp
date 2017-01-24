#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
ll fact[12];
ll aa, bb;
int main (void) {
	//ll temp = 1;
	fact[0] = 1ll;
	for (ll i = 1; i <= 12ll; i++) {
		fact[i] = i*fact[i-1];
	}
	ll a, c, b;
	while (1) {
		cin>>aa>>bb;
		if(aa == -1) {
			break;
		}
		a = max(aa, bb);
		b = min(aa, bb);
		c = (fact[a+1])/(fact[a+1-b]*fact[b]);
		if(c == aa + bb){
			cout<<aa<<"+"<<bb<<"="<<aa+bb<<endl;
		}else {
			cout<<aa<<"+"<<bb<<"!="<<aa+bb<<endl;
		}

	}
	return 0;
}
