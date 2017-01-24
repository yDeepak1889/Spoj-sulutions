#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll

string s1, s2;

int dp[1010][1010];
int len1, len2;
bool flag[1010][1010];

int cal (int i, int j){
	//cout<<len1<<" "<<len2<<endl;
	//cout<<i<<"---->"<<j<<endl;
	if(flag[i][j]) {
		return dp[i][j];
	}
	if(s1[i] == '\0' && s2[j] == '\0') {
		flag[i][j] = true;
		dp[i][j] = 0;
		return 0;
	}
	int temp;
	if (s1[i] == s2[j]) {
		dp[i][j] = cal(i+1, j+1);
		flag[i][j] =true;
		return dp[i][j];
	} else {

		if (i == len1) {
			temp = 30+cal(i, j+1);
			dp[i][j] = temp;
			flag[i][j] = true;
			return temp;
		}else if(j == len2) {
			temp = 15 + cal (i+1, j);
			dp[i][j] = temp;
			flag[i][j] = true;
			return temp;
		}else{
		 	temp = min (15+cal(i+1, j), 30+cal(i,j+1));
			dp[i][j] = temp;
			flag[i][j] = true;
			return temp;
		}
		}
}


int main (void) {
	while (1) {
		s1.clear();
		s2.clear();

		memset(dp, 0, sizeof(dp));
		memset (flag, false, sizeof(flag));

		cin>>s1;
		if(s1[0] == '#') {
			return 0;
		}

		cin>>s2;
		len1 = s1.size();
		len2 = s2.size();
	//	cout<<s1<<" "<<s2<<endl;
	//	cout<<len1<<" "<<len2<<endl;
			cout<<cal(0, 0)<<endl;;
	}

}
