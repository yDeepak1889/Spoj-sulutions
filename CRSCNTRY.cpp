#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007ll
int dp[2022][2022];
bool flag[2022][2022];

int o[2022], t[2022];

int n1, n2;

int cal (int i, int j){
	if(flag[i][j]) {
		return dp[i][j];
	}
	if(i == n1 || j == n2) {
		return 0;
	}
	if(o[i] == t[j]) {
	dp[i][j] =  1 + cal(i+1, j+1);
	flag[i][j] = 1;
	return dp[i][j];
	}else {
		dp[i][j] =  max (cal(i+1, j), cal(i, j+1));
		flag[i][j] = 1;
		return dp[i][j];
	}
}

int main (void) {
	int c;
	cin>>c;
	int m = 0;
	while (c--) {
		n1 = 0;
		n2 = 0;
		m = 0;
		while (1) {
			cin>>o[n1];
			if(o[n1] == 0) {
				break;
			}
			n1++;
		}
		while (1){
			memset(flag, false, sizeof(flag));
			n2 = 0;
			while (1) {
				cin>>t[n2];
				if (t[n2] == 0) {
					break;
				}
				n2++;
			}
			if(n2 == 0) {
				break;
			}
			m = max (m, cal (0, 0));
		}
		cout<<m<<endl;
	}

	return 0;
}
