#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main (void)
{

  int n;
  cin>>n;
  ll arr[n];
  int i;

  for (i = 0; i < n; i++) {
    cin>>arr[i];
  }

  int k;
  cin>>k;

  deque<int> q(k);
  for (i = 0; i < k; i++) {
    while( !(q.empty()) && (arr[i] >= arr[q.back()])) {
      q.pop_back();
    }
    q.push_back(i);
  }

  for (; i < n; i++) {
    cout<<arr[q.front()]<<" ";
    while((!q.empty()) && q.front() <= i-k) {
      q.pop_front();
    }

    while ((!q.empty()) && arr[i] >= arr[q.back()]){
      q.pop_back();
    }
    q.push_back(i);
  }
  cout<<arr[q.front()]<<endl;
  return 0;
}
