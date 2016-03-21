#include<stdio.h>
#include<string.h>
int main(void)
{
	int test;
	
	scanf("%d", &test);
	getchar();	
	while(test) {	
		char str[210];
	
		scanf("%s", str);
		
		int i;
		int ctr;
		int j;
		ctr = 0;
		i = 0;
	//	printf("%d", (int)strlen(str));
		
		while(i < (int)strlen(str)) {
	//		printf("success1\n");
			if( ctr % 2 == 1) {
				
				for (j = 0; j < test/2; j++) {
					str[j+i] = str[i + test -j-1] + str[j+i];
					str[i + test -1 -j] = str[j+i] - str[i+test-1-j];
					str[i+j] = str[i+j] - str[i+test-1-j];
	//				printf("success\n");
				}
			}
	//		printf("%d", i);
			i = i + test;
			ctr ++;
			
		}
		//printf("%s", str);
	
		for (i = 0; i < test; i++) {
				for (j = i; j < strlen(str); j +=test)		
				printf("%c", str[j]);
			
		}
 
		printf("\n");
		
		scanf("%d", &test);
	}
	return 0;
} 	 
