#include <bits/stdc++.h>
using namespace std;
#define long long long
int nextInt() {int a; cin >> a; return a;}

void solve(){
    int n = nextInt(), m = nextInt();
    vector<int> pages(n);
    for(auto& x : pages) x = nextInt();
    
    vector<int> incoming(n, 0);
    vector<int> tree(n, -1);
    for(int i = 0; i < m; i++){
        int from = nextInt() - 1;
        int to = nextInt() - 1;
        tree[to] = from;
        incoming[from]++;
    }

    vector<int> culminating;
    for(int i = 0; i < n; i++)
        if(!incoming[i])
            culminating.push_back(i);

    vector<bool> visited(n, false);
    auto go = [&](int v, auto && go) -> int {
        if(v == -1 || visited[v]) return 0;
        visited[v] = true;
        return pages[v] + go(tree[v], go);
    };

    int minn = (int)1e9;
    for(int i = 0; i < culminating.size(); i++) {
        for(int j = i+1; j < culminating.size(); j++) {
            minn = min(minn, go(culminating[i], go) + go(culminating[j], go));
            visited.assign(n, false);
        }
    }

    cout << minn << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}