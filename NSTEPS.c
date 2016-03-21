#include<stdio.h>
int main(void)
{
	int test;
	scanf("%d", &test);
	
	while(test--) {
		int x;
		int y;
		int ans;
		scanf("%d %d", &x, &y);
		
		if(x == y) {
			if( x % 2 == 0 && y % 2 == 0) {
				ans = x + y;
			} else {
				ans = x + y -1;
			}
			printf("%d\n", ans);
		}
		
		else if ( x == y + 2) {
			if ( x % 2 == 0 &&  y % 2 ==0) {
				ans = x + y;
			} else {
				ans = x + y -1;
			}
			printf("%d\n", ans);
		} else {
			printf("No Number\n");
		}
	}
	return 0;
}
