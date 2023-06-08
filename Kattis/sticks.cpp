#include <bits/stdc++.h>
using namespace std;
#define long long long
int nextInt() {int a;cin >> a;return a;}
string next(){string a; cin >> a;return a;}
long nextLong(){long a; cin >> a;return a;}

void solve() {
    int n = nextInt(), m = nextInt();
    vector<int> incoming(n, 0);
    vector<vector<int>> graph(n, vector<int>());
    while(m--){
        int from = nextInt() - 1;
        int to = nextInt() - 1;
        graph[from].push_back(to);
        incoming[to]++;
    }
    
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(!incoming[i])
            q.push(i);
            
    vector<int> ans;
    while(q.size()) {
        int here = q.front(); q.pop();
        ans.push_back(here+1);
        for(auto x : graph[here])
            if(--incoming[x] == 0)
                q.push(x);
    }

    if(ans.size() != n)
        cout << "IMPOSSIBLE" << "\n";
    else 
        for(auto x : ans)
            cout << x << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}