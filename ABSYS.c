#include<stdio.h>
#include<string.h>
int main(void)
{
	int test;
	scanf("%d", &test);
	
	while(test--) {
		char str_1[10];
		char str_2[10];
		char str_3[10];
		
		scanf("%s + %s = %s", str_1, str_2, str_3);
		int i;
		int ctr1 = 0, ctr2 = 0, ctr3 = 0;
		
		for( i = 0; i < strlen(str_1) ; i++) {
			if(str_1[i] == 'm') {
				ctr1 ++;
				break;
			}
		}
		
		
		for (i = 0; i < strlen(str_2); i++) {
			if(str_2[i] == 'm') {
				ctr2 ++;
				break;
			}
		}
		
		for (i = 0; i < strlen(str_3); i++) {
			if(str_3[i] == 'm') {
				ctr3++;
				break;
			}
		}
		long long int num;
		if(ctr1 != 0 ) {
			num = (long long )atoi(str_3) - (long long )atoi(str_2);
			printf("%lld + %s = %s\n", num, str_2, str_3);
		} else if ( ctr2 != 0) {
			num = (long long)atoi(str_3) - (long long )atoi(str_1);
			printf("%s + %lld = %s\n", str_1, num, str_3);
		} else {
			num = (long long )atoi(str_1) + (long long )atoi(str_2);
			printf("%s + %s = %lld\n", str_1, str_2, num);
		}
		
	}
	return 0;

}
