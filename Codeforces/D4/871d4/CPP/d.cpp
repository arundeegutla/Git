#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int start = nextInt(), goal = nextInt();

    unordered_set<int> visited;
    queue<int> q;
    q.push(start);
    visited.insert(start);
    while (q.size()) {
        int num = q.front(); q.pop();
        if(num%3) continue;
        int x = num/3;
        int twox = 2*x;
        if(visited.find(x) == visited.end()){
            q.push(x);
            visited.insert(x);
        }
        if(visited.find(twox) == visited.end()){
            q.push(twox);
            visited.insert(twox);
        }
    }
    
    cout << (visited.find(goal) != visited.end() ? "YES" : "NO") << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}