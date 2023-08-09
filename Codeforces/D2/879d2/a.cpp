#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    vector<int> arr(nextInt());
    int pos = 0, negs = 0;
    for(auto& x : arr) (x = nextInt()) < 0 ? negs++ : pos++;
    int changed = negs;
    while(pos - changed < 0) {
        pos++;
        changed--;
    }

    cout << (negs - changed) + (changed%2) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}