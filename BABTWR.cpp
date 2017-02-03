#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007ll


typedef struct box{
	int l;
	int b;
	int h;
}box;
box arr[100];

int dp[100];
int n;

bool cmp(box a, box bb) {
	return a.l*a.b > bb.l * bb.b;
}

int main (void) {
	while(1){
	cin>>n;
	if(n == 0) {
		return 0;
	}
	memset(dp, 0, sizeof(dp));
	int i;
	for (i = 0; i < n; i++) {
		cin>>arr[i].l>>arr[i].b>>arr[i].h;
	}

	int ctr = n;

	for (i = 0; i < n; i++) {
		arr[ctr].l = arr[i].l;
		arr[ctr].b = arr[i].h;
		arr[ctr].h = arr[i].b;
		ctr++;
		arr[ctr].l = arr[i].h;
		arr[ctr].b = arr[i].b;
		arr[ctr].h = arr[i].l;
		ctr++;
	}
	int j;
	sort(arr, arr+ctr, cmp);
	// for (i = 0; i < ctr; i++) {
	// 	cout<<arr[i].l<<" "<<arr[i].b<<" "<<arr[i].h<<endl;
	// }
	int m = 0;
	for (i = 0; i < ctr; i++) {
		dp[i] = arr[i].h;
	//	cout<<arr[i].l<<" "<<arr[i].b<<" "<<arr[i].h<<endl;
		for (j = i-1; j >=0; j--) {
		//	cout<<"---->"<<arr[j].l<<" "<<arr[j].b<<" "<<arr[j].h<<endl;
			if((arr[i].l < arr[j].l && arr[i].b < arr[j].b)||(arr[i].l < arr[j].b && arr[i].b < arr[j].l)) {
				dp[i] = max(dp[i], dp[j]+arr[i].h);
			//	cout<<i<<" "<<j<<endl;
			}
		}
		m = max(dp[i], m);
	}
	cout<<m<<endl;
}
	return 0;
}
