#include<stdio.h>
#define MAX 10000000
int arr[MAX+10];
int main(void)
{
	
		
	long long int i;
	long long int j;
	long long int sum;
	j = 1;
	arr[0] = 0;
	arr[1] = 1;
	for (i = 2; i <= MAX;) {
		sum = ((j + 1) * (j + 1 + 1)) / 2;
		//printf("%lld %lld\n", j, sum);
		while(sum > i && i <= MAX) {
			arr[i] = j;
			i ++;
		}
		j++;
	}
	int test;
	scanf("%d", &test);
	while(test--) {
		int num;
		scanf("%d", &num);
		
		int check;
		check = arr[num];
			
		sum = (check * (check+1)) / 2;
			
		int ans1;
		int ans2;
			
		if( sum - num == 0 ) {
			if(check % 2 == 0) {
				ans1 = check;
				ans2 = 1;
			} else {
				ans1 = 1;
				ans2 = check;
			}
		} else {
			int diff;
			diff = num - sum;
			
			if(check % 2 == 0) {
				ans1 = check + 2 - diff;
				ans2 = diff;
			} else {
				ans1 = diff;
				ans2 = check + 2 - diff;
			}
		}
		printf("TERM %d IS %d/%d\n", num, ans1, ans2);
	}
	return 0;
} 
