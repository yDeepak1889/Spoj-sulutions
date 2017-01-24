#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main (void)
{
  while(1){
    int n;
    cin>>n;
    if(n == 0) {
      break;
    }

    ll arr[n];
    int i;

    for (i = 0;i < n; i++) {
      cin>>arr[i];
    }

    ll mh = arr[0], maxa = arr[0], ctr = 1, temp;

    for (i = 1; i < n; i++) {
      mh = min(mh, arr[i]);
      ctr++;
      if(arr[i] > ctr*mh) {
        mh = arr[i];
        ctr = 1;
        maxa = max(maxa,arr[i]);
      }else {
        maxa = max(maxa,ctr * mh);
      }
    //  cout<<mh<<" "<<ctr<<" "<<maxa<<endl;
    }
    cout<<maxa<<endl;

  }
}
