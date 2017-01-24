#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}else{
		return gcd(b, a%b);
	}
}

int main()
{
	int test;
	scanf ("%d", &test);
	string b;
	while (test--) {
		
		int a;
		scanf("%d", &a);
		cin>>b;
		if (a == 0){
			cout<<b<<endl;
			continue;
		}
		int ans = 0;

		int i = 0;

		while (b[i] != '\0') {
			ans = (ans*10 + (int(b[i] - '0'))) % a;
			i++;
		}
		printf("%d\n",gcd(a,ans));
		b.clear();
	}
	return 0;
}