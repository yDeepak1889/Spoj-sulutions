#include<stdio.h>
int main(void)
{
	
		int n;
		scanf("%d", &n);
	while(n != -1) {
		long long int arr[n];	
		long long int i,j,sum=0, ans;
		
		for (i = 0 ; i < n ; i++) {
			scanf("%lld", &arr[i]);
			sum = sum + arr[i];
		}
		//printf("%d %d %d ", sum, n, sum % n);
		if ((sum % n ) == 0){
			ans = sum / n;
			sum = 0;
			for (i = 0 ; i < n ; i++) {
				if (arr[i] - ans > 0)
					sum = sum + (arr[i] - ans);
				}
			
		printf("%lld", sum);
		
		} else {
			printf("-1");
		}
		printf("\n");
		scanf("%d", &n);
	}
	return 0;
 
}
