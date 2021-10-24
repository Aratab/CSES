/**
 * Author: Samuel Batara (Aratab)
**/ 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e18+5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,q; cin >> n >> m >> q;
	ll dist[n][n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(i==j) dist[i][j] = 0;
			else dist[i][j] = inf;
		}
	}
	for(int i=0; i<m; i++) {
		int a,b,c; cin >> a >> b >> c;
		--a; --b;
		dist[a][b] = min(dist[a][b], 1ll*c);
		dist[b][a] = min(dist[b][a], 1ll*c);
	}
	for(int k=0; k<n; k++) {
		for(int a=0; a<n; a++) {
			for(int b=0; b<n; b++) {
				dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b]);
			}
		}
	}
	
	while(q--) {
		int a,b; cin >> a >> b; --a; --b;
		if(dist[a][b]==inf) cout << -1 << '\n';
		else cout << dist[a][b] << '\n';
	}
	return 0;
}
