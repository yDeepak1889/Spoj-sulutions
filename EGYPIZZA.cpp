#include <bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf ("%d", &test);
	int x,y;
	int h3 = 0, h2 = 0, h4 = 0,n4 = 0;
	int ans = 1;
	while (test!=0) {
		scanf ("%d/%d",&x, &y);
		if(x==3) {
			h3++;
		}else if(y==2) {
			h2++;
		}else if(y==4) {
			n4++;
		}
		test--;
	}
	
	//printf("%d %d %d\n",h3,h2,n4);
	
	if(h2 % 2 == 0) {
		ans += (h2 / 2);
		h2 = 0;
	}else {
		ans +=(h2+1)/2;
		h2 = 1;
	}
	
	ans+=h3;
	h4 = h3;
	if(h2 == 1 && n4 != 0) {
		h4+=2;
		h2 = 0;
	}
	
	if(n4 > h4) {
		n4-=h4;
		ans+= (n4/4);
		n4 = n4 % 4;
		if(n4){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
