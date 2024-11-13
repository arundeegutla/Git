#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int N = nextInt(), M = nextInt(), L = nextInt()+1;
    int F = nextInt();
    vector<int> flies(L);
    while(F--) flies[nextInt()]++;

    vector<bool> seen(L);
    queue<int> q;
    q.push(0);

    ll count = 0;
    while(q.size()){
        int here = q.front(); q.pop();
        if(seen[here]) continue;
        seen[here] = true; 
        
        count += flies[here];
        if(here+N < L && !seen[here+N]){
            q.push(here+N);
        }
        if(here-M >= 0 && !seen[here-M]){
            q.push(here-M);
        }
    }

    cout << count << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}