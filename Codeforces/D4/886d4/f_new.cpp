#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt();

    unordered_map<int, int> frogs(n+1);
    for(int i = 0; i < n; i++)
        frogs[nextInt()]++;

    vector<int> buckets(n+1);
    for(auto [key, hop] : frogs)
        for(int at = hop; at <= n; at += hop)
            buckets[at] += frogs[hop];

    cout << *(max_element(buckets.begin(), buckets.end())) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}