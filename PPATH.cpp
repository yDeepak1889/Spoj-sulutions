#include <bits/stdc++.h>

using namespace std;

int arr[10010];

bool check(int a, int b)
{
	int ctr = 0;
	while (a||b) {
		if(a%10 == b % 10) {
			ctr++;
		}
		a /= 10;
		b /= 10;
	}
	if (ctr == 3) {
		return true;
	}else {
		return false;
	}
}

int bfs (int a, int b, vector< vector<int> > g)
{
	vector<int> d(10000,0);
	vector<int> s(10000,0);
	int current;
	queue<int> q;
	q.push(a);
	int size_q = 1;
	int max = 0;
	if(a == b){
		return max;
	}

	s[current] = 1;
	int skip;
	int count;
	vector<int>::iterator it1, it2;
	while (size_q != 0) {
		current = q.front();
	//	printf("%d\n",current);
		q.pop();
		size_q--;
		count = g[current].size();
		//printf("%d\n",g[current][7]);
		for (int i = 0; i < 8; i++) {
			skip = g[current][i];
			it1 = d.begin();
			it2 = s.begin();
			
			if(*(it2+skip) == 0) {
				*(it1+skip) = *(it1+current) + 1;
				*(it2 + skip) = 1;
				q.push(skip);
				size_q++;
			//	printf("Success\n");
				if (skip == b) {
					max = skip;
					return *(it1 + skip);
				}
			}
		}
	}
	
}

int main()
{
	int i,j;
	arr[0] = 1;
	arr[1] = 1;
	
	for (i = 2; i*i < 10010; i++) {
		if (!arr[i]) {
			for (j = i; j < 10010; j += i) {
				arr[j] = 1;
			}
		}
	}
	
	vector<vector<int> > g(10000+1);
	
	for (i = 1000; i < 10000; i++) {
		if(!arr[i]) {
			for (j = i + 1; j < 10000; j++) {
				if(!arr[j]) {
					if(check(i,j)) {
						g[i].push_back(j);
						g[j].push_back(i);
					}
				}
			} 
		} 
	}
	
	int test;
	scanf ("%d", &test);
	
	while (test--) {
		int a,b;
		scanf ("%d %d", &a, &b);
		int max;
	
		max = bfs (a,b,g);
		printf("%d\n",max);
	}
	
	return 0;
}
