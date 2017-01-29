#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
char s1[200], s2[200];

int l1, l2;
int dp[200][200];
int flag[200][200];
int temp;
int cal(int i, int j) {
	//cout<<i<<" "<<j<<endl;
	if (i >= l1 && j >= l2) {
		return 0;
	}
	if(i >= l1) {
		return l2-j;
	}
	if(j >= l2){
		return l1-i;
	}
	if(s1[i] == s2[j]){
		return 1+cal(i+1, j+1);
	}else
		return min(1+cal(i+1, j), 1+cal(i,j+1));
}

int main (void) {
	while (1) {
		scanf ("%s %s", s1, s2);
		//printf ("%s %s\n", s1, s2);
		if(s1[0] == EOF) {
			return 0;
		}
		l1 = strlen (s1);
		l2 = strlen (s2);
		//cout<<l1<<" "<<l2<<endl;
		cout<< cal(0, 0)<<endl;
	}

	return 0;
}
