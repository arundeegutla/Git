#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(auto& x : arr) cin >> x, x--;


	if(k == 1) {
		for(int i = 0; i < n; i++){
			if(arr[i] != i) {
				cout << "NO" << "\n";
				return;
			}
		}
		cout << "YES" << "\n";
		return;
	}


	vector<int> vis(n);
	vector<int> depth(n);
	vector<int> cyclesizes;

	auto dfs = [&](int at, int dist, auto&& dfs) -> void {
		if(vis[at] == 2) return;
		
		vis[at] = 1;
		depth[at] = dist;
		int next = arr[at];
		if(vis[next] == 1){
			cyclesizes.push_back(depth[at] - depth[next] + 1);
		} else {
			dfs(next, dist+1, dfs);
		}
		vis[at] = 2;
	};

	for(int i = 0; i < n; i++){
		if(vis[i] == 0) {
			dfs(i, 0, dfs);
		}
	}

	for(auto size : cyclesizes) {
		if(size != k) {
			cout << "NO" << "\n";
			return;
		}
	}


	cout << "YES" << "\n";




}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n;
	while(n--) solve();
}