#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll

string s;
int arr[30][30];
int a[30];
int len;
int c = 0;

bool cal() {
	int i;
	int prev = 0;
	int sum;
	for (i = 0; i <= c; i++) {
		//	cout<<a[i]<<endl;
	//	cout<<len<<endl;
		if(i == 0) {
			sum = arr[0][a[i]];
		}else if(i == c && a[c-1]!=len-1){
			sum = arr[a[c-1]+1][len-1];
		}else if(a[i-1]!=len-1){
			sum = arr[a[i-1]+1][a[i]];
		}else{
			continue;
		}
	//	cout<<sum<<" "<<a[i]<<endl;
		if(prev > sum){
			return false;
		}
		prev = sum;
	}
	return true;
}

int main (void) {
	int t = 1;
	while (1) {
		s.clear();
		cin>>s;
		if(s == "bye") {
			break;
		}
		len = s.size();
		int i, j;
		i = 0;
		while (s[i] != '\0') {
			j = i+1;
			arr[i][i] = s[i]-'0';
			while (s[j] != '\0') {
				arr[i][j] = arr[i][j-1] + (s[j]-'0');
				j++;
			}
			i++;
		}
		// for (i = 0; i < len; i++) {
		// 	for(j = 0; j < len; j++) {
		// 		cout<<arr[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		int temp;
		int temp1;

		int ans = 1;
		int ctr = 0;
		for (i = 0; i <= (1<<(len-1))-1; i++) {
			temp = i;
			c = 0;
			ctr = 0;
			while (temp){
				temp1 = (temp & 1);
				if(temp1 == 1){
				//	cout<<i<<" "<<ctr<<" "<<c<<endl;
					a[c] = ctr;
					c++;
				}
				ctr++;
				temp = temp>>1;
			}
		//	 cout<<i<<" "<<c<<"---->"<<endl;
			// for(j = 0; j < c; j++) {
			// 	cout<<a[j]<<endl;
			// }

			if (c!= 0 && cal()){
				ans++;
			}
		}
		cout<<t<<". "<<ans<<endl;
		t++;
	}
}
