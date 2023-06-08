#include <bits/stdc++.h>
using namespace std;
#define long long long
int nextInt() {int a;cin >> a;return a;}
string next(){string a; cin >> a;return a;}
long nextLong(){long a; cin >> a;return a;}

class Edge {
public:
    int to;
    int ind;
    Edge(int to, int ind){
        this->to = to;
        this->ind = ind;
    }
};

void solve() {
    int n = nextInt();
    vector<vector<Edge>> edges(n, vector<Edge>());

    for(int i = 0; i < n-1; i++){
        int from = nextInt() - 1;
        int to = nextInt() - 1;
        edges[from].push_back(*(new Edge(to, i)));
        edges[to].push_back(*(new Edge(from, i)));
    }

    vector<bool> visited(n, false);
    vector<int> iterations(n, 1);
    queue<Edge> q;
    q.push(*(new Edge(0, -1)));

    visited[0] = true;
    int maxx = 1;
    while(q.size()) {
        Edge here = q.front(); q.pop();
        int dist = iterations[here.to];
        for(auto x : edges[here.to]) {
            if(visited[x.to]) continue;
            iterations[x.to] = dist + (x.ind < here.ind);
            maxx = max(iterations[x.to], maxx);
            visited[x.to] = true;
            q.push(x);
        }
    }

    cout << maxx << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    while(n--) solve();
}