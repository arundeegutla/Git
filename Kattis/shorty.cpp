#include <bits/stdc++.h>
using namespace std;
#define long long long
int nextInt() {int a;cin >> a;return a;}
string next(){string a; cin >> a;return a;}
long nextLong(){long a; cin >> a;return a;}
double nextDouble(){double a; cin >> a;return a;}

class Edge {
public:
    int to;
    double factor;
    Edge(int to, double factor){
        this->to = to;
        this->factor = factor;
    }
};

void solve() {
    while(true){
        int n = nextInt(), m = nextInt();
        if(n==0&&m==0) return;
        vector<vector<Edge>> graph(n, vector<Edge>());
        while(m--){
            int from = nextInt();
            int to = nextInt();
            double factor = nextDouble();
            graph[from].push_back(*(new Edge(to, factor)));
            graph[to].push_back(*(new Edge(from, factor)));
        }

        vector<double> dist(n, 0);
        queue<int> q;
        q.push(0);
        dist[0] = 1;
        double maxx = 0;
        while(q.size()){
            int here = q.front(); q.pop();
            double d = dist[here];
            for(auto x : graph[here]){
                if(dist[x.to] < d * x.factor){
                    dist[x.to] = d * x.factor;
                    if(x.to == n-1) maxx = dist[n-1];
                    else q.push(x.to);
                }
            }
        }

        printf("%.4f\n", maxx);
    }
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}