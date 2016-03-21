#include<stdio.h>
 
int main(void)
{
	int x1;
	int x2;
	int x3;	
		
	x1 = 1;
	x2 = 1;
	x3 = 1;
	scanf("%d %d %d", &x1, &x2, &x3);
	while(x1 != 0 || x2 != 0 || x3 != 0) {
		
		
		if (x2 - x1 == x3 - x2) {
			printf("AP %d\n", x3 +(x3-x2));
		} else if (x3 / x2 == x2 / x1 ) {
			printf("GP %d\n", x3*(x3/x2));
		}
		scanf("%d %d %d", &x1, &x2, &x3);
	}
	return 0;
} 
