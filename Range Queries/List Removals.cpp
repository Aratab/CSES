/**
 * Author: Samuel Batara (Aratab)
**/ 
#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+5;
int t[4*mxn];
int a[mxn];
int n;

void build(int i, int l, int r) {
	if(l==r) {
		t[i] = 1;
	} else {
		int m = l + (r-l)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = t[2*i] + t[2*i+1];
	}
}

int query(int i, int l, int r, int p) { 
	if(l == r) {
		t[i] = 0;
		return a[l];
	}
	int m = l + (r-l)/2;
	int res;
	if(p <= t[2*i]) {
		res = query(2*i, l, m, p);
	} else {
		res = query(2*i+1, m+1, r, p-t[2*i]);
	}
	t[i] = t[2*i] + t[2*i+1];
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	build(1,0,n-1);
	for(int i=0; i<n; i++) {
		int p; cin >> p;
		int res = query(1,0,n-1,p);
		cout << res << ' ';
	}
	
	return 0;
}
