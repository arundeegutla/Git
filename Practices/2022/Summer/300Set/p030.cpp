#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    int m = nextInt();
    vector<vector<int>> graph(n);
    while(m--){
        int from = nextInt()-1, to = nextInt()-1;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}