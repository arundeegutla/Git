#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

vvi grid;
vvi vis;
int ff(int i, int j) {
	if (grid[i][j] == 0)
		return 0;
	vis[i][j] = true;
	vi dx = {1, -1, 0, 0};
	vi dy = {0, 0, -1, 1};
	
	int sum = grid[i][j];
	for (int k = 0; k < 4; k++) {
		int newi = dx[k] + i;
		int newj = dy[k] + j;
		if (newi < 0 || newi >= grid.size() || newj < 0 || newj >= grid[i].size())
			continue;
		if (vis[newi][newj])
			continue;
		vis[newi][newj] = true;
		sum += ff(newi, newj);
	}
	return sum;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vii starts;
		grid = vvi(n, vi(m));
		vis = vvi(n, vi(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
				if (grid[i][j] > 0)
					starts.emplace_back(i, j);
			}
		}

		int vol = 0;
		for (int i = 0; i < starts.size(); i++) {
			vol = max(vol, ff(starts[i].first, starts[i].second));
		}
		
		cout << vol << endl;

	}
	return 0;
}
