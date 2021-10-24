/**
 * Author: Samuel Batara (Aratab)
**/ 
#include <bits/stdc++.h>
using namespace std;

int vis[1005][1005];
int n,m;
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

bool inside(int x, int y) {
	if(x<0 || x>=n || y<0 || y>=m) return false;
	else if(vis[x][y]) return false;
	return true;
}

void dfs(int x, int y) { 
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(inside(nx,ny)) {
			vis[nx][ny] = 1;
			dfs(nx,ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(vis,0,sizeof(vis)); 
	cin >> n >> m;
	string s;
	for(int i=0; i<n; i++) {
		cin >> s;
		for(int j=0; j<m; j++) {
			vis[i][j] = (s[j]=='#'? 1:0);
		}
	} 
	
	int ans = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(vis[i][j]) continue;
			dfs(i,j);
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
