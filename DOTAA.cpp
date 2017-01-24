#include<bits/stdc++.h>
using namespace std;
int main (void)
{
	int test;

	scanf ("%d", &test);

	while (test--) {
		int n, m ,d;

		scanf("%d%d%d",&n,&m,&d);
		int i;
		int arr[n];

		for (i = 0; i < n; i++) {
			scanf ("%d",&arr[i]);
		}
		int ctr = 0;
		bool flag = true;
		for (i = 0; i < n; i++) {
			ctr = arr[i] / d;

			if (arr[i] % d == 0){
				ctr--;
			}
			while(ctr && m){
				m-=1;
				ctr--;
			}
			if(m == 0){
				break;
			}
		}

		if (m == 0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}