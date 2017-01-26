#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
string s;
vector<char>v;
int c = 0;
int ctr = 0;
int main (void) {
	int a = 1;
	while (1) {
		s.clear();
		cin>>s;
		if(s[0] == '-'){
			break;
		}
		v.clear();
		c = 0;
		ctr = 0;
		int i = 0;
		while (s[i] != '\0') {
			if(s[i] == '{') {
				v.push_back(s[i]);
				c++;
			}else {
				if(c == 0) {
					v.push_back('{');
					c++;
					ctr++;
				}else {
					v.pop_back();
					c--;
				}
			}
			i++;
		}
		ctr += (c/2);
		cout<<a<<". "<<ctr<<endl;
		a++;
	}

	return 0;
}
