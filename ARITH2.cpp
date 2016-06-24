#include<bits/stdc++.h>

using namespace std;

int main()
{
	int test;
	scanf ("%d",&test);
	
	while (test--) {
		printf("\n");
		char a,sp;
		long long num1, ans,num2 = -1;
		
		a = '\0';
		
		while (a != '=') {
			sp = ' ';
			while (sp == ' ') {
				cin>>sp;
			}
			scanf ("%lld",&num1);
			sp = ' ';
			while (sp==' ') {
				cin>>sp;
			}
		//	getchar();
			switch (a) {
				case '+':
					ans += num1;
					break;
				case '-':
					ans -= num1;
					break;
				case '*':
					ans *= num1;
					break;
				case '/':
					ans /= num1;
					break;
				case '%':
					ans %= num1;
					break;
				default:
					ans = num1;
					break;
			} 
			
			scanf ("%c",&a);
		//	printf("%c\n",a);
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
