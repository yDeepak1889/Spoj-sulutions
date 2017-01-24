#include<bits/stdc++.h>
using namespace std;

int arr[2010][2010];
void allBlack(int * state, int n)
{
	int i;

	for (i =0; i < n; i++) {
		state[i] = -1;
	}
	return ;
}
vector<int> v;
bool dfs(int n, int * state, int s)
{
	int ctr = 0;
	

	v.push_back(s);
	state[s] = 0;
	while (!v.empty()) {
		s = v.back();
		v.pop_back();


		for (int i = 0; i < n; i++) {
			if (arr[s][i] == 1) {
				if(state[i] == -1)
					v.push_back(i);
				if (state[s] == 0 && state[i] == 0 || (state[s] == 1 && state [i] == 1)){
					return true;
				}else{
					if (state[s] == 1){
						state[i] = 0;
					}else{
						state[i] = 1;
					}
				}
				
			}
		}
	}
	v.clear();
	return false;
}


int main (void)
{
	int test;
	scanf ("%d", &test);

	for (int a = 1; a <= test; a++) {
		int n, m;
		memset(arr, 0, sizeof(arr));
		scanf("%d%d", &n, &m);
		int i;
		int x,y;

		for (i = 0;i < m;i++) {
			scanf ("%d%d", &x, &y);
			arr[x-1][y-1] = 1;
			arr[y-1][x-1] = 1;
		}

		int state[n];
		allBlack(state, n);
		printf("Scenario #%d:\n",a);
		for (i = 0; i < n; i++) {
			if (state[i] == -1) {
				if(dfs(n,state,i)){
					printf("%s\n","Suspicious bugs found!");
					break;
				}
			}
		}
		if (i == n) {
			printf("%s\n", "No suspicious bugs found!");
		}
	}
	return 0;
}