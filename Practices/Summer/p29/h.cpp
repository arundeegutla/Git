#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<ll> cows(n);
    for(auto& x : cows) x = nextInt();


    vector<int> visited(1<<n); 
    auto go = [&](int at, ll left, ll right, int mask, auto && go) -> void {
        if(at == n) {
            visited[mask] |= left!=0 && left == right;
            return;
        }
        go(at+1, left, right, mask, go);
        go(at+1, left+cows[at], right, (mask|(1<<at)), go);
        go(at+1, left, right+cows[at], (mask|(1<<at)), go);
    };

    go(0, 0, 0, 0, go);

    cout << accumulate(visited.begin(), visited.end(), 0) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}