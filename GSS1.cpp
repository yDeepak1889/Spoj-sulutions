#include<bits/stdc++.h>
using namespace std;
#define MIN -1000000000
#define ll long long int
long long seg[200000][3];
void setSeg(long long int  * arr, long long int  low, long long int  high, long long int  pos)
{
 if (low == high) {
   //printf("SUcess1\n");
    seg[pos][1] = arr[low];
    seg[pos][0] = 0ll;
    seg[pos][2] = 0ll;
    return;
  }

  long long int  mid;
  mid = (low+high)/2;
//  printf("Success\n");
  setSeg(arr, low, mid, 2*pos+1);
  setSeg(arr, mid+1, high, 2*pos+2);

  long long int temp;

  temp = seg[2*pos+1][1] + seg[2*pos+1][2] + seg[2*pos+2][0] + seg[2*pos+2][1];

  if (temp >= seg[2*pos+1][1] && temp >= seg[2*pos+2][1]) {
    seg[pos][1] = temp;
    seg[pos][0] = seg[2*pos+1][0];
    seg[pos][2] = seg[2*pos+2][2];
  } else if (seg[2*pos+1][1] > seg[2*pos+2][1]){
    seg[pos][1] = seg[2*pos+1][1];
    seg[pos][0] = seg[2*pos+1][0];
    seg[pos][2] = seg[2*pos+1][2] + seg[2*pos+2][0] + seg[2*pos+2][1] + seg[2*pos+2][2];
  }else{
    seg[pos][1] = seg[2*pos+2][1];
    seg[pos][2] = seg[2*pos+2][2];
    seg[pos][0] = seg[2*pos+2][0] + seg[2*pos+1][0] + seg[2*pos+1][1] + seg[2*pos+1][2];
  }
//  printf("%lld %lld %lld\n", low, high, pos);
  return ;
}
ll * pp;
long long *  query(long long int  qlow, long long int  qhigh, long long int  low, long long int  high, long long int  pos)
{
//	cout<<low<<" "<<high<<endl;
	pp = (long long *) malloc (sizeof(long long int)*3);
	if  (low >= qlow && high <= qhigh) {
		//prlong long int f("Success1\n");
		pp[0] = seg[pos][0];
		pp[1] = seg[pos][1];
		pp[2] = seg[pos][2];
	//	cout<<low<<" "<<high<<" "<<pp[0]<<" "<<pp[1]<<" "<<pp[2]<<endl;
		return pp;
	}

	if (qlow > high || qhigh < low) {
		//prlong long int f("Success2\n");
		return NULL;
	}
	ll * ptr1, * ptr2;
	long long int  mid;
	mid = (low+high)/2ll;
	//printf("Success3\n");
	ptr1 = query(qlow, qhigh, low, mid, 2*pos+1);
	ptr2 = query(qlow, qhigh, mid+1, high, 2*pos+2);
	ll temp = 0;
	if (ptr1 == NULL && ptr2 == NULL) {
	//	cout<<low<<"---->"<<high<<endl;
		return NULL;
	}else if (ptr1 == NULL) {
	//	cout<<low<<"---->"<<high<<endl;
		return ptr2;
	}else if (ptr2 == NULL) {
		//cout<<low<<"---->"<<high<<endl;
		return ptr1;
	}
//	cout<<"#######"<<low<<" "<<high<<" "<<ptr1[0]<<" "<<ptr1[1]<<" "<<ptr1[2]<<" "<<ptr2[0]<<" "<<ptr2[1]<<" "<<ptr2[2]<<endl;
	temp = ptr1[1] + ptr1[2] + ptr2[0] + ptr2[1];

  if (temp >= ptr1[1] && temp >= ptr2[1]) {
    pp[1] = temp;
    pp[0] = ptr1[0];
    pp[2] = ptr2[2];
  } else if (ptr1[1] > ptr2[1]){
	//	cout<<ptr2[0]<<" "<<ptr2[1]<<" "<<ptr2[2]<<" "<<ptr1[0]<<endl;
		pp[2] = ptr1[2] + ptr2[0] + ptr2[1] + ptr2[2];
	//	cout<<"@@@@@@@@@@@@@@@"<<low<<" "<<high<<" "<<ptr1[0]<<" "<<ptr1[1]<<" "<<ptr1[2]<<" "<<ptr2[0]<<" "<<ptr2[1]<<" "<<ptr2[2]<<endl;
		pp[0] = ptr1[0];
		pp[1] = ptr1[1];
  }else{
    pp[1] = ptr2[1];
    pp[2] = ptr2[2];
    pp[0] = ptr2[0] + ptr1[0] + ptr1[1] + ptr1[2];
  }
	//cout<<low<<" "<<high<<" "<<pp[0]<<" "<<pp[1]<<" "<<pp[2]<<endl;
	return pp;
}


int  main (void)
{
  long long int  n;
  scanf ("%lld", &n);

  long long int  arr[n];
  memset(seg, 0, sizeof(seg));
  //memset(lazy, 0, sizeof(lazy));

  long long int  i;

  for (i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }

  setSeg(arr, 0, n-1, 0);

////////////////////////////////////////////////////////////////////
	ll ctr = 1;

		while (ctr < n) {
			ctr <<=1;
		}
		ll size;
		size = 2 * ctr - 1;
    FILE * fd;
    fd = fopen ("1.txt", "w");
  for (i = 0; i < size-1; i++) {
    fprintf(fd, "%lld %lld %lld\n", seg[i][0]+seg[i][1], seg[i][1], seg[i][2]+seg[i][1]);
  }

  printf("\n");

/////////////////////////////////////////////////////////////////////

//   long long int  q;
//   scanf ("%lld", &q);
//
//   long long int  o, x, y, val;
// 	ll * ptr;
//   while (q--) {
//     scanf ("%lld%lld", &x, &y);
//     x--;
//     y--;
// 		ptr = query(x, y, 0, n-1, 0ll);
// 		if (ptr != NULL)
//     printf("%lld\n", ptr[1]);
// }
// ll j;
// FILE * fd;
// fd = fopen ("1.txt", "w");
// for (i = 0; i < n; i++){
//   for (j = i; j  < n; j++) {
//     ptr = query(i, j, 0, n-1, 0ll);
//     if (ptr != NULL) {
//       // cout<<ptr[1]<<endl;
//       fprintf(fd, "%lld\n", ptr[1]);
//     }
//   }
// }

  return 0;
}
