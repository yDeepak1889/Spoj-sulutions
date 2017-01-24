#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll

int main (void) {
	int n1, n2;
	vector<int> v1, v2;
	vector<int>::iterator it1, it2, it;
	while (1) {
		v1.clear();
		v2.clear();
		cin>>n1;
		if(n1 == 0) {
			break;
		}
		int i, num;
		for (i = 0; i < n1; i++) {
			cin>>num;
			v1.push_back(num);
		}
		cin>>n2;
		for (i = 0; i < n2; i++) {
			cin>>num;
			v2.push_back(num);
		}
		it1 = v1.begin();
		it2 = v2.begin();
		int total = 0, sum1 = 0, sum2 = 0;
		while (it1 != v1.end()) {
			sum1 += (*it1);
			sum2 = 0;
			it = lower_bound (v2.begin(), v2.end(),(*it1));
			if((*it) == (*it1)) {
				it++;
				while (it2 != it) {
					sum2 += (*it2);
					it2++;
				}
				total += max(sum1, sum2);
				sum1 = 0;
				sum2 = 0;
			}
			it1++;
		}
		sum2 = 0;
		while (it2 != v2.end()) {
			sum2 += (*it2);
			it2++;
		}
		total += max(sum1,sum2);
		cout<<total<<endl;
	}

	return 0;
}
