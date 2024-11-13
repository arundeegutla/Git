#include <bits/stdc++.h>
using namespace std;
#define long long long

class Edge {
public:
    int to;
    int w;
};

int main(){

    while(1){
        int n, m, queries, s;
        cin >> n >> m >> queries >> s;
        if(!n&&!m&&!queries&&!s) return 0;

        vector<vector<Edge>> nodes(n, vector<Edge>());
        for(int i = 0; i < m; i++){
            int from, to, w;
            Edge e;
            cin >> from >> e.to >> e.w;
            nodes[from].push_back(e);
        }

        vector<long> dist(n, LONG_MAX);
        queue<int> q;
        q.push(s);
        dist[s] = 0;

        while (!q.empty()){
            auto here = q.front(); q.pop();
            long distHere = dist[here];
            for(auto e : nodes[here]){
                if(dist[e.to] > distHere + e.w){
                    dist[e.to] = distHere + e.w;
                    q.push(e.to);
                }
            }
        }

        while(queries--){
            int to; cin >> to;
            cout << (dist[to] != LONG_MAX ? to_string(dist[to]) : "Impossible") << "\n";
        }
        cout << "\n";

    }

}