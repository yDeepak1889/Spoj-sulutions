#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main (void)
{
  int test;
  cin>>test;
  vector <ll> v;
  queue<ll> q;
  while (test--) {
    ll n;
    cin>>n;

    ll a, b, c, tm;
    int i;
    for (i = 0; i < n; i++) {
      scanf ("%lld:%lld:%lld", &a,&b, &c);
      tm = a*60*60 + b*60 + c;
      v.push_back(tm);
    }

    sort(v.begin(), v.end(), greater<long long>());

    tm = v.back();
    q.push(tm);
    v.pop_back();
    

    while(!v.empty()) {

    }
  }

  return 0;
}
