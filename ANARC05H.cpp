#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll

string s;
ll arr[26][26];
ll len;

ll cal (ll l, ll r) {
	if (l == r) {
		return 0;
	}else if (l > r){
		return 0;
	}
	ll i = 0;
	ll sum = 0;
	for (i = r; i > l; i--) {
		if (arr[i][r] >= arr[l][i-1]){
			cout<<i<<" "<<r<<"--->"<<l<<" "<<i-1<<endl;
			sum += (1+cal(l, i-1));
		}else{
			sum += cal(l, i-1);
		}
	}
	return sum;
}
int main (void) {
	ll ctr = 1;
	while (1) {
		memset(arr, 0, sizeof(arr));
		s.clear();
		cin>>s;
		if (s == "bye"){
			return 0;
		}
		ll i, j,sum = 0;
		i = 0, j = 0;

		len = s.size();
		for (i = 0; i < len; i++) {
			sum = 0;
			for (j = i; j < len; j++) {
				sum += s[j] - '0';
				arr[i][j] = sum;
			}
		}
		// for (i = 0; i < len; i++) {
		// 	for (j = 0; j < len; j++) {
		// 		cout<<arr[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		cout<<ctr<<". "<<cal(0, len-1)+1<<endl;
		ctr++;
	}

	return 0;
}
