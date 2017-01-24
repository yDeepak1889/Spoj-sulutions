#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007ll
typedef struct {
	int l;
	int r;
	int i;
}node;
node p[200002];
int n, q;
int arr[30002];
int ans[200002];
int cnt[1000010];
int current = 0;
int block;
inline bool cmp(node x, node y) {
	if((x.l)/block != (y.l)/block){
		return x.l<y.l;
	}
	return x.r<y.r;
}

inline void add(int i) {
	if(cnt[arr[i]] == 0) {
		current++;
	}
	cnt[arr[i]]++;
}
inline void remove (int i) {
	if (cnt[arr[i]] == 1) {
		current--;
	}
	cnt[arr[i]]--;
}
int main (void) {
	scanf ("%d", &n);
	int i;
	block = (int)sqrt(n);
	for (i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
	}
	cin>>q;
	for (i = 0; i < q; i++){
		scanf ("%d%d", &(p[i].l), &(p[i].r));
		p[i].i = i;
	}
	sort (p, p+q,cmp);
	int mo_l = 0, mo_r = -1;
	int l,r;
	for (i = 0; i < q; i++) {
		l = p[i].l-1;
		r = p[i].r-1;
		while (mo_r < r) {
			mo_r++;
			add(mo_r);
		}
		while (mo_r > r) {
			remove(mo_r);
			mo_r--;
		}
		while (mo_l < l) {
			remove(mo_l);
			mo_l++;
		}
		while (mo_l > l) {
			mo_l--;
			add(mo_l);
		}
		ans[p[i].i] = current;
	}
	for (i = 0; i < q; i++) {
		printf ("%d\n", ans[i]);
	}
	return 0;
}
