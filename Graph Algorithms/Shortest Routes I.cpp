/**
 * Author: Samuel Batara (Aratab)
**/ 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mxn = 1e5+5;
const ll inf = 1e18+5;
vector<pair<int,int>> ad[mxn];
ll dist[mxn];
bool vis[mxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m; cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a,b,c; cin >> a >> b >> c;
		--a; --b;
		ad[a].push_back({b,c});
	}
	for(int i=0; i<n; i++) {
		dist[i] = inf;
	}
	priority_queue<pair<ll,int>> q;
	q.push({0,0});
	dist[0] = 0;
	
	while(!q.empty()) {
		int a = q.top().second; q.pop();
		if(vis[a]) continue;
		vis[a] = true;
		for(auto t : ad[a]) {
			int b = t.first;
			ll c = t.second;
			if(dist[b] > dist[a] + c) {
				dist[b] = dist[a] + c;
				q.push({-dist[b], b});
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		cout << dist[i] << " ";
	}
	return 0;
}
