#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, a, b;
    cin >> n >> b >> a;
    a--, b--;

    vector<vector<int>> graph(n);
    vector<bool> seen(n);

    for(int i = 0; i < n; i++){
        int from, to;
        cin >> from >> to;
        from--, to--;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }   

    if(a == b) {
        cout << "NO\n";
        return;
    }


    auto dfs = [&](int at, int p, int i, auto&& dfs) -> bool {
        if(p != -1 && at == i) return true;
        if(seen[at]) return false;
        seen[at] = true;
        for(auto e : graph[at])
            if(e != p)
                if(dfs(e, at, i, dfs)){
                    seen[at] = false;
                    return true;
                }
        seen[at] = false;
        return false;
    };


    vector<int> distA(n, n+1);
    queue<int> q;
    q.push(a);
    distA[a] = 0;
    while(q.size()){
        int here = q.front();q.pop();
        for(auto e : graph[here]) {
            if(distA[e] > distA[here] + 1){
                distA[e] = distA[here] + 1;
                q.push(e);
            }
        }
    }

    vector<int> distB(n, n+1);
    q.push(b);
    distB[b] = 0;
    while(q.size()){
        int here = q.front();q.pop();
        for(auto e : graph[here]) {
            if(distB[e] > distB[here] + 1){
                distB[e] = distB[here] + 1;
                q.push(e);
            }
        }
    }

    vector<bool> cycle(n);
    for(int i = 0; i < n; i++){
        if(dfs(i, -1, i, dfs)){
            if(distA[i] < distB[i]){
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}