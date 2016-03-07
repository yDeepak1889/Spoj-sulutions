#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int l, int m, int r)
{
	int n1;
	int n2;
	
	n1 = m - l +1;
	n2 = r - m;
		
	int L[n1];
	int R[n2];
	
	int i;
	int j;
	int k;	
		
	for (i = 0; i < n1; i++)
		L[i] = arr[i+l];
	for (j = 0; j < n2; j++) 	
		R[j] = arr[m+1+j];
		
	i = 0;
	j = 0;
	k = l;
	
	while( i < n1 && j < n2) {
		if( L[i] < R[j]) {
			arr[k] = R[j];
			j++;
		} else {
			arr[k] = L[i];
			i++;
		}	
		k++;
	}
	
	while(i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	
	return ;
}
			
void mergeSort(int arr[], int l, int r) 
{
	if(l < r) {	
		int mid;
		mid = l + (r-l)/2;
		mergeSort(arr, l , mid);
		mergeSort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
	return;
}

int main(void)
{
	long long int test;
	scanf("%lld", &test) ;
	int j;
	for(j = 1; j <= test; j++) {
		long long num, n;
			
		scanf("%lld %lld", &num, &n);
		
		int arr[n];
		int i;
		for(i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		
		mergeSort(arr,0, n-1);
		long long sum = 0;
		i = 0;
		int ctr = 0;
		while(sum < num && i < n) {
			sum = sum + (long long )arr[i];
			i ++;
			ctr ++;
		}
		
		if(sum < num) {
			printf("Scenario #%d:\nimpossible\n", j);
		}else {
			printf("Scenario #%d:\n%d\n", j, ctr);
		}
		printf("\n");
	}
	return 0;
}
		
		
