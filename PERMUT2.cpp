#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main (void)
{
	int n;
	scanf("%d", &n);
	while (n) {
	int arr[n];
	int temp[n];

	int i;

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		temp[arr[i] - 1] = i + 1;
	}

	for (i = 0; i < n; i++) {
		if (arr[i] != temp[i]) {
			break;
		}
	}

	if (i == n) {
		printf("ambiguous\n");
	} else {
		printf ("not ambiguous\n");
	}
	scanf("%d", &n);
	}
	return 0;
}
