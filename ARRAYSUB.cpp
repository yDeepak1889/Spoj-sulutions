#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
multiset<int> :: iterator it;
int main (void)
{
	int n;
	scanf ("%d", &n);

	int arr[n];
	int i;

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int max = -1;

	int k;
	int ind ;
	scanf("%d", &k);
	for (i = 0;i < k; i++) {
		s.insert(arr[i]);
	}
	it = s.end();
	it--;
	printf("%d ", *it);
	int start = k;
	i = 0;
	while (start < n) {
		it = s.find(arr[i]);
		s.erase(it);
		i++;
		s.insert(arr[start]);
		it= s.end();
		it--;
		printf("%d ", *it);
		/*it = s.begin();
		while (it != s.end()) {
			printf("%d ", *it);
			it++;
		}
		printf("\n");*/
		start++;
	} 
	printf("\n");

	return 0;
}