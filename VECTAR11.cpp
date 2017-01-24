#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
int arr[1000010];
int dp[1000010];
int t[1000010];
int main (void) {

	int i;
	int temp = 1;
	int temp1;
	for (i = 1; i <= 1000000; i++) {
		temp1 = (int)sqrt(i);
		if (temp1 * temp1 == i) {
			t[i] = 1;
			arr[i] = temp;
			temp = i;
		}else {
			arr[i] = temp;
		}
	}
	// for (i = 1; i <= 100; i++) {
	// 	cout<<i<<"--->"<<arr[i]<<endl;
	// }
	dp[0] = 0;
	dp[1] = 1;
	for (i = 2; i <= 1000000; i++) {
		temp = i;
		if (t[i]) {
			dp[i] = 1;
			continue;
		}
		while (temp != 0) {
		//	cout<<temp<<"---->"<<i-arr[temp]<<endl;
			if(!dp[i-arr[temp]] && i-arr[temp] != 0) {
				dp[i] = 1;
				break;
			}
			if(temp == 1) {
				break;
			}
	//		cout<<i<<"#####"<<temp<<endl;
			temp = arr[temp];
		}
	}
	// for (i = 1; i <= 10; i++) {
	// 	cout<<i<<"---->"<<dp[i]<<endl;
	// }
	int test;
	scanf ("%d", &test);
	while (test--) {
		scanf ("%d", &temp);
		if(dp[temp]) {
			printf ("Win\n");
		}else {
			printf ("Lose\n");
		}
	}
	return 0;
}
