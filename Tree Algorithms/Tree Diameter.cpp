/**
 * Author: Samuel Batara (Aratab)
**/ 
#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+5;
vector<int> adj[mxn];
int f[mxn], s[mxn];

void dfs(int a, int p) {
	for(int b : adj[a]) if(b != p) {
		dfs(b,a);
		if(f[b] + 1 > f[a]) {
			s[a] = f[a];
			f[a] = f[b] + 1;
		} else if(f[b] + 1 > s[a]) {
			s[a] = f[b] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for(int i=0; i<n-1; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,-1);
	int ans = 0;
	for(int i=1; i<=n; i++) {
		ans = max(ans, f[i] + s[i]);
	}
	cout << ans << '\n';
	return 0;
}
