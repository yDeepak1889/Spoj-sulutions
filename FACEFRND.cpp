#include<bits/stdc++.h>
using namespace std;

int main (void)
{
	int n, m;
	scanf ("%d", &n);
	map<int, int> mp;
	map<int,int> mp1;
	map <int, int> :: iterator it;
	int num, num1;
	while (n--) {
		scanf ("%d",&num);
		mp1[num] = 1;
		if (mp[num] == 1){
			mp[num] = -1;
		}
		scanf ("%d", &m);
		while (m--) {
			scanf ("%d", &num1);

			if (mp1[num1] == 1) {
				mp[num1] = -1;
			}else{
				mp[num1] = 1;
			}
		}

	}


	it = mp.begin();
	int ctr = 0;
	while (it != mp.end()) {
	//	printf("%d\n",it->first );
		if (it->second != -1) {
			ctr += it->second;
		}
		it++;
	}

	printf("%d\n",ctr );


	return 0;
}