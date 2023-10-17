#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}


void solve() {
    int n = nextInt(), m = nextInt();
    vector<vector<int>> graph(n, vector<int>());
    while(m--){
        int from = nextInt() - 1;
        int to = nextInt() - 1;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    priority_queue<Edge> edgesl
    for (auto x : graph[0]) 
        edges.push(x);
    v<bool> visited(n);
    visited[0] = true;
    int minCost = 0, edgeNum = 0;
    while (!edges.isEmpty()) {
        Edge e = edges.poll();				
        if (visited[e.from] && visited[e.v2]) continue;
        if (!visited[e.from]) {
            for (auto x : graph[e.from])
                edges.add(x);	
            visited[e.from] = true;
        } else {
            for (auto x : graph[e.v2])
                edges.add(x);	
            visited[e.v2] = true;
        }	
        minCost += e.w;
        edgeNum++;
        if (NUMBER OF VERTICES - 1 == edgeNum) break;
    }


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}