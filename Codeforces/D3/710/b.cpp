#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    set<int> stars;
    for(int i = 0; i < n; i++)
        if(s[i]=='*')
            stars.insert(i);


    int count = 1;
    int first = *stars.begin();
    while(true){
        auto itr = stars.upper_bound(first+k);
        int next = *(--itr);
        if(next == first) break;
        count++;
        first = next;
    }

    cout << count << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}