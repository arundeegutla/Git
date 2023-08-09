#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt(), m = nextInt();
    vector<vector<int>> graph(n, vector<int>());
    for(int i = 0; i < m; i++){
        int from = nextInt()-1, to = nextInt()-1;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int x = -1, y = -1;
    vector<bool> visited(n);
    queue<int> q;

    for(int i = 0; i < n; i++)
        if(graph[i].size() == 1){
            q.push(i);
            visited[i] = true;
        }

    vector<int> children(n);
    while(q.size()){
        int here = q.front(); q.pop();
        if(graph[here].size() != 1){
            y = children[here];
            for(auto e : graph[here]){
                if(visited[e]) continue;
                x = graph[e].size();
                cout << x << " " << y << "\n";
                return;
            }
        }
        children[graph[here][0]]++;
        q.push(graph[here][0]);
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}